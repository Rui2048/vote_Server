#include "service.h"
#include <assert.h>
#include <iostream>
#include <string.h>
#include <fstream>
#include "../protobuf/protbuf.h"


CacheServer::CacheServer() 
{
    
}
CacheServer::~CacheServer()
{

}

int CacheServer::epollAddfd(int fd)
{
    assert(epfd != -1);
    epoll_event event;
    event.events = EPOLLIN;
    event.data.fd = fd;
    int ret = epoll_ctl(epfd, EPOLL_CTL_ADD, fd, &event);
    if (ret == -1)
    {
        std::cout << "epoll add fd fail on fd : " << fd << std::endl;
        return -1;
    }
    return 0;
}

int CacheServer::epollDelfd(int fd)
{
    assert(epfd != -1);
    epoll_event event;
    event.events = EPOLLIN;
    event.data.fd = fd;
    int ret = epoll_ctl(epfd, EPOLL_CTL_DEL, fd, &event);
    if (ret == -1)
    {
        std::cout << "epoll delete fd fail on fd : " << fd << std::endl;
        return -1;
    }
    return 0;
}

int CacheServer::init()
{
    //初始化日志：默认为异步日志,阻塞队列的容量为100
    std::string logName = "log_";
    Log::get_instance()->init(logName.c_str(), m_close_log, 8000, 50000, 0);
    //初始化线程池
    threadInit(m_thread_number, m_max_requests);
    //初始化epoll
    epfd = epoll_create(5);
    if (epfd == -1) 
    {
        LOG_ERROR("epoll init failed");
        return -1; 
    }
    LOG_INFO("cache_server init sucessfully!");
    return 0;
}

int CacheServer::startListen()
{
    lfd = socket(AF_INET, SOCK_STREAM, 0);
    if (lfd == -1)
    {
        LOG_ERROR("lfd create failed");
        return -1;
    }
    cache_server_sockaddr.sin_family = AF_INET;
    cache_server_sockaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    cache_server_sockaddr.sin_port = htons(cache_server_port);
    int opt = 1;
    setsockopt(lfd, SOL_SOCKET, SO_REUSEADDR, (const void *)&opt, sizeof(opt));
    int ret = bind(lfd, (sockaddr*)(&cache_server_sockaddr), sizeof(cache_server_sockaddr));
    if (ret == -1)
    {
        LOG_ERROR("listen sockfd bind failed, errno is %d", errno);
        return -1; 
    }
    ret = listen(lfd, 5);
    if (ret == -1)
    {
        LOG_ERROR("TCP start listen failed, errno is %d", errno);
        return -1; 
    }
    epollAddfd(lfd);
    if (ret == -1) return -1;
    LOG_ERROR("cache_server start listen success");
    return 0;
}

int CacheServer::connectToServer()
{
    cfd = socket(AF_INET, SOCK_STREAM, 0);

    server_sockaddr.sin_family = AF_INET;
    server_sockaddr.sin_port = htons(serverPort);
    inet_aton(server_ip.c_str(),&server_sockaddr.sin_addr);

    int ret = 0;
    ret = connect(cfd, (sockaddr*)(&server_sockaddr), sizeof(server_sockaddr));
    if (ret == -1)
    {
        LOG_ERROR("connect to server failed, errno is %d", errno);
        return -1;
    }
    epollAddfd(cfd);
    /*char buf[1024];
    memset(buf, 0, sizeof(buf));
    int len = recv(cfd, buf, sizeof(buf), 0);
    if (len > 0)
    {
        cout << "recv:" << len << endl << buf << endl;
    }*/
    char msg[] = "123";
    send(cfd, msg, sizeof(msg), 0);
    return 0;
}

int CacheServer::eventLoop()
{
    epoll_event evs[1024];
    char buf[1024]; //接收缓冲区
    int ev_size = sizeof(evs) / sizeof(epoll_event);
    while (!shutdown)
    {
        int num = epoll_wait(epfd, evs, ev_size, 0);  //不阻塞
        if (num == -1)
        {
            LOG_ERROR("epoll waited failed");
            return -1;
        }
        for (int i = 0; i < num; i++) 
        {
            int cur_fd = evs[i].data.fd;
            
            if (cur_fd == lfd) //新的客户端请求或者更新backup
            {
                sockaddr_in addr;
                socklen_t addr_len = sizeof(addr);
                cfd = accept(lfd, (sockaddr*)(&addr), &addr_len);
                if (cfd < 0)
                {
                    LOG_ERROR("%s:errno is:%d", "accept error", errno);
                    return -1;
                }
                epollAddfd(cfd);
                cout << "client connected" << endl;
                //char msg[] = "This is Server";
                //send(cfd, msg, strlen(msg), 0);
            }
            else if (cur_fd == cfd)
            {
                memset(buf, 0, sizeof(buf));
                int len = recv(cur_fd, buf, sizeof(buf), 0);
                if (len == 0) 
                {
                    //LOG_INFO("server disconnected");
                }
                else if (len == -1) 
                {
                    LOG_ERROR("recv from master_server failed, errno is %d", errno);
                }
                else
                {
                    cout << "recv:" << len << endl << buf << endl;
                    string msg = buf;
                    append(msg);
                }
            }
            else
            {
                memset(buf, 0, sizeof(buf));
                int len = recv(cur_fd, buf, sizeof(buf), 0);
                if (len == 0) 
                {
                    cout << "client disconnected" << endl;
                }
                else if (len == -1) 
                {
                    LOG_ERROR("recv from master_server failed, errno is %d", errno);
                    
                }
                else
                {
                    cout << "recv:" << len << endl << buf << endl;
                    string resp;
                    resp += "HTTP/1.1 200 OK\r\n";
                    resp += "Content-Length:12\r\n";
                    resp += "Connection:keep-alive\r\n";
                    resp += "Access-Control-Allow-Origin:*\r\n";
                    resp += "\r\n";
                    resp += "VoteServer\r\n";
                    const char *msg = resp.c_str();
                    int slen;
                    slen = send(cur_fd, msg, strlen(msg), 0);
                    //cout << "send worlds:" << slen << endl;
                }
            }
        }
    }
    return -1;
}


//初始化线程池
int CacheServer::threadInit(int thread_number, int max_requests)
{
    if (thread_number <= 0 || max_requests <= 0)
        throw std::exception();
    m_threads = new pthread_t[m_thread_number];
    if (!m_threads)
        throw std::exception();
    for (int i = 0; i < thread_number; ++i)
    {
        if (pthread_create(m_threads + i, NULL, worker, this) != 0)
        {
            delete[] m_threads;
            throw std::exception();
        }
        if (pthread_detach(m_threads[i]))
        {
            delete[] m_threads;
            throw std::exception();
        }
    }
    return 0;
}

/*工作线程运行的函数，它不断从工作队列中取出任务并执行之*/
void *CacheServer::worker(void *arg)
{
    CacheServer *Server = (CacheServer*)arg;
    Server->run();
    return Server;
}
void CacheServer::run()
{
    while (true)
    {
        m_queuestat.wait();
        m_queuelocker.lock();
        if (m_workqueue.empty())
        {
            m_queuelocker.unlock();
            continue;
        }
        string request = m_workqueue.front();
        m_workqueue.pop_front();
        m_queuelocker.unlock();
        char ch = request[0];
        request = request.substr(1, request.size() - 1);
        switch (ch)
        {
        case '1':
            dealWithLogin(request);
            break;
        case '2':
            dealWithCreateVote(request);
            break;
        case '3':
            dealWithVote(request);
            break;
        case '4':
            dealWithGetAllVotes(request);
            break;
        case '5':
            dealWithGetVotesByOneJudge(request);
            break;
        case '6':
            dealWithGetVoteResult(request);
            break;
        default:
            break;
        }
    }
}
//往工作队列中添加任务
bool CacheServer::append(string request)
{
    m_queuelocker.lock();
    if (m_workqueue.size() >= m_max_requests)
    {
        m_queuelocker.unlock();
        return false;
    }
    m_workqueue.push_back(request);
    m_queuelocker.unlock();
    m_queuestat.post();
    return true;
}

//业务逻辑处理函数
void CacheServer::dealWithCreateVote(string &request)//新建投票
{
    protoMsg::CreateVote protoRequest;
    protoMsg::CreateVoteResponse protoResponse;
    protoRequest.ParseFromString(request);
    string voteName = protoRequest.votename();
    float dazhongWeight = atof(protoRequest.dazhongweight().c_str());
    float zhuanyeWeight = atof(protoRequest.zhuanyeweight().c_str());
    google::protobuf::RepeatedPtrField<protoMsg::CreateVote_Judge> judgeChoose = protoRequest.judgechoose();
    google::protobuf::RepeatedPtrField<string> playerChoose = protoRequest.playerchoose();
    long deadline = atol(protoRequest.deadline().c_str());
    long realTime = time(nullptr);
    long voteID = realTime;
    Vote newVote;
    newVote.setVoteName(voteName);
    newVote.setVoteID(voteID);
    newVote.setStartTime(realTime);
    newVote.setStopTime(deadline);
    newVote.setNormalWeight(dazhongWeight);
    newVote.setProfessionWeight(zhuanyeWeight);
    for (int i = 0; i < judgeChoose.size(); i++)
    {
        string name = judgeChoose[i].name();
        int id = atoi(judgeChoose[i].id().c_str());
        if (id == 0)
        {
            newVote.addNormalJudge(name);
            normalJudgeVotes[name].push_back(voteID);
        }
        else if (id == 1)
        {
            newVote.addProfessionalJudge(name);
            professionalJudgeVotes[name].push_back(voteID);
        }
    }
    for (int i = 0; i < playerChoose.size(); i++) 
    {
        newVote.addCandidate(playerChoose[i]);
    }
    Votes[voteID] = newVote;
    protoResponse.set_result("ok");
    string response;
    protoResponse.SerializeToString(&response);
    send(cfd, response.c_str(), response.size(), 0);
}
void CacheServer::dealWithLogin(string &request)    //登录
{
    protoMsg::LoginRequest protoRequest;
    protoMsg::LoginResponse protoResponse;
    protoRequest.ParseFromString(request);
    string uname = protoRequest.uname();
    string upwd = protoRequest.upwd();
    protoResponse.set_uname("htsc");
    if (uname == "admin")   //管理员
    {
        protoResponse.set_id("2");
    }
    else
    {
        if (professionalJudgeVotes.count(uname) != 0) //专业评委
        {
            protoResponse.set_id("1");
        }
        else if (normalJudgeVotes.count(uname) != 0) //大众评委
        {
            protoResponse.set_id("0");
        }
    }
    string response;
    protoResponse.SerializeToString(&response);
    cout << "send:" << response << endl;
    send(cfd, response.c_str(), response.size(), 0);
}
void CacheServer::dealWithVote(string &request)     //投票
{
    protoMsg::Vote protoRequest;
    protoMsg::VoteResponse protoResponse;
    protoRequest.ParseFromString(request);
    long voteID = atol(protoRequest.voteid().c_str());
    string name = protoRequest.uname();
    int status = atoi(protoRequest.ustatus().c_str());
    google::protobuf::RepeatedPtrField<protoMsg::Vote_Plaer_score> player_score = protoRequest.plaerpoints();
    if (status == 0)
    {
        for (int i = 0; i < player_score.size(); i++)
        {
            if (player_score[i].score() == "1")
            {
                Votes[voteID].voteByNormalJudge(player_score[i].name());
            }
        }
    }
    else if (status == 1)
    {
        for (int i = 0; i < player_score.size(); i++)
        {
            if (player_score[i].score() == "1")
            {
                Votes[voteID].voteByProfessionalJudge(player_score[i].name());
            }
        }
    }
    CNode *head = Votes[voteID].getCandidateList().head;
    CNode *tail = Votes[voteID].getCandidateList().tail;
    CNode *cur = head;
    while (cur != tail)
    {
        protoMsg::VoteResponse_Plaerscore *temp =  protoResponse.add_playerscores();
        temp->set_name(cur->name);
        char chs[10] = {0};
        sprintf(chs, "%.2f", cur->score);
        temp->set_score(chs);
        cur = cur->next;
    }
    string response;
    protoResponse.SerializeToString(&response);
    send(cfd, response.c_str(), response.size(), 0);
}
void CacheServer::dealWithGetVoteResult(string &request) //获取投票结果
{
    protoMsg::GetVoteResult protoRequest;
    protoMsg::VoteResponse protoResponse;
    protoRequest.ParseFromString(request);
    long voteID = atol(protoRequest.voteid().c_str());
    CNode *head = Votes[voteID].getCandidateList().head;
    CNode *tail = Votes[voteID].getCandidateList().tail;
    CNode *cur = head;
    while (cur != tail)
    {
        protoMsg::VoteResponse_Plaerscore *temp =  protoResponse.add_playerscores();
        temp->set_name(cur->name);
        char chs[10] = {0};
        sprintf(chs, "%.2f", cur->score);
        temp->set_score(chs);
        cur = cur->next;
    }
    string response;
    protoResponse.SerializeToString(&response);
    send(cfd, response.c_str(), response.size(), 0);

}
void CacheServer::dealWithGetAllVotes(string &request)  //管理员获取所有投票
{
    protoMsg::GetAllVotes protoRequest;
    protoRequest.ParseFromString(request);
    protoMsg::GetAllVotesResponse protoResponse;
    for (auto iter : Votes)
    {
        protoMsg::GetAllVotesResponse_Vote *temp = protoResponse.add_votes();
        temp->set_voteid(to_string(iter.second.getVoatID()));
        temp->set_votename(iter.second.getVoteName());
        long realTime = time(nullptr);
        if (realTime < iter.second.getStopTime())
        {
            temp->set_isvalid("1");
        }
        else
        {
            temp->set_isvalid("0");
        }
    }
    string response;
    protoResponse.SerializeToString(&response);
    send(cfd, response.c_str(), response.size(), 0);
}
void CacheServer::dealWithGetVotesByOneJudge(string &request) //评委获取自己的投票
{
    protoMsg::GetVoteResultByOneJudge protoRequest;
    protoRequest.ParseFromString(request);
    protoMsg::GetVoteResultByOneJudgeResponse protoResponse;
    string name = protoRequest.uname();
    string status = protoRequest.ustatus();
    vector<long> voteIDs;
    if (status == "0")
    {
        voteIDs = normalJudgeVotes[name];
    }
    else if (status == "1")
    {
        voteIDs = professionalJudgeVotes[name];
    }
    for (auto i : voteIDs)
    {
        protoMsg::GetVoteResultByOneJudgeResponse_Vote *temp = protoResponse.add_votes();
        temp->set_voteid(to_string(Votes[i].getVoatID()));
        temp->set_votename(Votes[i].getVoteName());
        long realTime = time(nullptr);
        if (realTime < Votes[i].getStopTime())
        {
            temp->set_isvalid("1");
        }
        else
        {
            temp->set_isvalid("0");
        }
    }
    string response;
    protoResponse.SerializeToString(&response);
    send(cfd, response.c_str(), response.size(), 0);
}
