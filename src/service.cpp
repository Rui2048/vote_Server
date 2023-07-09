#include "service.h"
#include <assert.h>
#include <iostream>
#include <string.h>
#include <fstream>
#include "../protobuf/voteServer_proto.pb.h"

void testCreateVote(VoteServer *server);
void testLogin(VoteServer *server);

VoteServer::VoteServer() 
{
    
}
VoteServer::~VoteServer()
{

}

int VoteServer::epollAddfd(int fd)
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

int VoteServer::epollDelfd(int fd)
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

int VoteServer::init()
{
    //初始化日志：默认为异步日志,阻塞队列的容量为100
    //std::string logName = "log_";
    std::string logName = "../log/log_";
    bool flag = Log::get_instance()->init(logName.c_str(), m_close_log, 8000, 50000, 0);
    if (flag == false)
    {
        std::cout << "日志初始化失败" << endl;
        return -1;
    }
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
int VoteServer::startListen()
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

int VoteServer::connectToServer()
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

int VoteServer::eventLoop()
{
    //testCreateVote(this);
    //testLogin(this);
    //cout << "over" << endl;
    //return 0;

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
            else
            {
                cfd = cur_fd;
                memset(buf, 0, sizeof(buf));
                int len = recv(cur_fd, buf, sizeof(buf), 0);
                if (len == 0) 
                {
                    //LOG_INFO("server disconnected");
                    epollDelfd(cur_fd);
                }
                else if (len == -1) 
                {
                    LOG_ERROR("recv from master_server failed, errno is %d", errno);
                }
                else
                {
                    //cout << "recv:" << len << endl << buf << endl;
                    //cout << "recv:" << strlen(buf) << endl << buf << endl;
                    cout << "recv:" << strlen(buf) << endl;
                    string msg = buf;
                    append(msg);
                    m_queuestat.post();
                }
            }
        }
    }
    return -1;
}


//初始化线程池
int VoteServer::threadInit(int thread_number, int max_requests)
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
void *VoteServer::worker(void *arg)
{
    VoteServer *Server = (VoteServer*)arg;
    Server->run();
    return Server;
}
void VoteServer::run()
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
bool VoteServer::append(string request)
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
void VoteServer::dealWithCreateVote(string &request, bool testFlag)//2、新建投票
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
    LOG_INFO("[create new vote] voteName:%s", voteName.c_str());
    Vote newVote;
    newVote.setVoteName(voteName);
    newVote.setVoteID(voteID);
    newVote.setStartTime(realTime);
    newVote.setStopTime(deadline);
    newVote.setNormalWeight(dazhongWeight);
    newVote.setProfessionWeight(zhuanyeWeight);
    cout << voteName << endl;
    cout << dazhongWeight << endl;
    cout << zhuanyeWeight << endl;
    cout << "deadline str:" << protoRequest.deadline() << ' ' << "deadline long:" << deadline << endl;
    cout << "评委:" << endl;
    cout << "voteID:" << voteID << endl;
    for (int i = 0; i < judgeChoose.size(); i++)
    {
        string name = judgeChoose[i].name();
        int id = atoi(judgeChoose[i].id().c_str());
        cout << name << ' ' << id << endl;
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
    cout << "选手:" << endl;
    for (int i = 0; i < playerChoose.size(); i++) 
    {
        newVote.addCandidate(playerChoose[i]);
        cout << playerChoose[i] << endl;
    }
    Votes[voteID] = newVote;
    protoResponse.set_result("ok");
    string response;
    protoResponse.SerializeToString(&response);
    if (testFlag == false) 
    {
        send(cfd, response.c_str(), response.size(), 0);
    }
    else
    {
        cout << response << endl;
    }
}
void VoteServer::dealWithLogin(string &request, bool testFlag)    //1、登录
{
    protoMsg::LoginRequest protoRequest;
    protoMsg::LoginResponse protoResponse;
    protoRequest.ParseFromString(request);
    string uname = protoRequest.uname();
    string upwd = protoRequest.upwd();
    cout << uname << endl;
    cout << upwd << endl;
    LOG_INFO("[user login] uname:%s, upwd:%s", uname.c_str(), upwd.c_str());
    protoResponse.set_uname(uname);
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
        else
        {
            protoResponse.set_id("uknown id");
        }
    }
    cout << protoResponse.id() << endl;
    string response;
    protoResponse.SerializeToString(&response);
    //cout << "send:" << response << endl;
    send(cfd, response.c_str(), response.size(), 0);
}
void VoteServer::dealWithVote(string &request, bool testFlag)     //3、投票
{
    protoMsg::Vote protoRequest;
    protoMsg::VoteResponse protoResponse;
    protoRequest.ParseFromString(request);
    long voteID = atol(protoRequest.voteid().c_str());
    if (Votes.count(voteID) == 0)
    {
        cout << "VoteID:" << voteID << "不存在" << endl;
        send(cfd, "error", 6, 0);
        return;
    }
    string name = protoRequest.uname();
    int status = atoi(protoRequest.ustatus().c_str());
    Votes[voteID].setVoted(name);
    cout << voteID << endl;
    cout << "评委:" << name  << ' ' << status << endl << "得分选手：" << endl;
    LOG_INFO("[Vote] name:%s voteID:%d", name.c_str(), voteID);
    google::protobuf::RepeatedPtrField<protoMsg::Vote_Plaer_score> player_score = protoRequest.plaerpoints();
    if (status == 0)
    {
        for (int i = 0; i < player_score.size(); i++)
        {
            if (player_score[i].score() == "1")
            {
                Votes[voteID].voteByNormalJudge(player_score[i].name());
                cout << player_score[i].name() << endl;
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
                cout << player_score[i].name() << endl;
            }
        }
    }
    CNode *head = Votes[voteID].getCandidateList().head;
    CNode *tail = Votes[voteID].getCandidateList().tail;
    CNode *cur = head->next;
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
    if (testFlag == false)
    {
        send(cfd, response.c_str(), response.size(), 0);
    }
    else
    {
        cout << response << endl;
    }
}
void VoteServer::dealWithGetVoteResult(string &request, bool testFlag) //6、获取投票结果
{
    protoMsg::GetVoteResult protoRequest;
    protoMsg::VoteResponse protoResponse;
    protoRequest.ParseFromString(request);
    long voteID = atol(protoRequest.voteid().c_str());
    cout << "VoteID:" << voteID << endl << "***选手得分:" << endl;
    LOG_INFO("[Get vote result] voteID:%d", voteID);
    if (Votes.count(voteID) == 0)
    {
        cout << "VoteID:" << voteID << "不存在" << endl;
        send(cfd, "error", 6, 0);
        return;
    }
    CNode *head = Votes[voteID].getCandidateList().head;
    CNode *tail = Votes[voteID].getCandidateList().tail;
    CNode *cur = head->next;
    while (cur != tail)
    {
        protoMsg::VoteResponse_Plaerscore *temp =  protoResponse.add_playerscores();
        temp->set_name(cur->name);
        char chs[10] = {0};
        sprintf(chs, "%.2f", cur->score);
        temp->set_score(chs);
        cout << cur->name << ":" << chs << endl;
        cur = cur->next;
    }
    string response;
    protoResponse.SerializeToString(&response);
    cout << "***响应:" << endl << response << endl;
    send(cfd, response.c_str(), response.size(), 0);

}
void VoteServer::dealWithGetAllVotes(string &request, bool testFlag)  //4、管理员获取所有投票
{
    protoMsg::GetAllVotes protoRequest;
    protoRequest.ParseFromString(request);
    protoMsg::GetAllVotesResponse protoResponse;
    LOG_INFO("[Get all votes]");
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
void VoteServer::dealWithGetVotesByOneJudge(string &request, bool testFlag) //5、评委获取自己的投票
{
    protoMsg::GetVoteResultByOneJudge protoRequest;
    protoRequest.ParseFromString(request);
    protoMsg::GetVoteResultByOneJudgeResponse protoResponse;
    string name = protoRequest.uname();
    //string status = protoRequest.ustatus();
    cout << "评委：" << name << ' ' << endl;
    LOG_INFO("[Get votes by one judge] name:%s", name.c_str());
    vector<long> voteIDs;
    if (normalJudgeVotes.count(name) == 0 && professionalJudgeVotes.count(name) == 0)
    {
        cout << "评委:" << name << "不存在" << endl;
        send(cfd, "error", 6, 0);
        return;
    }
    if (normalJudgeVotes.count(name) != 0)
    {
        voteIDs = normalJudgeVotes[name];
    }
    else if (professionalJudgeVotes.count(name) != 0)
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
        if (Votes[i].isVoted(name) == true)
        {
            temp->set_isvoted("1");
        }
        else
        {
            temp->set_isvoted("0");    
        }
    }
    string response;
    protoResponse.SerializeToString(&response);
    send(cfd, response.c_str(), response.size(), 0);
}

void testCreateVote(VoteServer *server)
{
    protoMsg::CreateVote req;
    req.set_type("创建投票");
    req.set_votename("vote1");
    req.set_zhuanyeweight("0.1");
    req.set_dazhongweight("0.2");
    req.set_deadline("1234");
    protoMsg::CreateVote_Judge* judge = req.add_judgechoose();
    judge->set_name("大众评委1");
    judge->set_id("0");
    judge = req.add_judgechoose();
    judge->set_name("专业评委1");
    judge->set_id("1");
    string *player = req.add_playerchoose();
    *player = "选手1";
    
    string s;
    req.SerializeToString(&s);
    server->dealWithCreateVote(s, true);
    //delete judge;
    //delete player;
}
void testLogin(VoteServer *server)
{
    protoMsg::LoginRequest req;
    req.set_uname("admin");
    req.set_upwd("admin");
    string s;
    req.SerializeToString(&s);
    server->dealWithLogin(s, true);
}
void testVote()
{
    protoMsg::Vote req;
    req.set_uname("大众评委1");
    req.set_ustatus("0");
    
}