#include "cache_service.h"
#include <assert.h>
#include <iostream>
#include <string.h>
#include <fstream>

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

int CacheServer::eventLoop()
{
    epoll_event evs[1024];
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
                int cfd = accept(lfd, (sockaddr*)(&addr), &addr_len);
                if (cfd < 0)
                {
                    LOG_ERROR("%s:errno is:%d", "accept error", errno);
                    return -1;
                }
                epollAddfd(cfd);
                //cout << "client connected" << endl;
                //char msg[] = "This is Server";
                //send(cfd, msg, strlen(msg), 0);
            }
            else
            {
                char buf[1024];
                memset(buf, 0, sizeof(buf));
                int len = recv(cur_fd, buf, sizeof(buf), 0);
                if (len == 0) 
                {
                    
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
                    resp += "Hello World\r\n";
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
        Request request = m_workqueue.front();
        m_workqueue.pop_front();
        m_queuelocker.unlock();
        
    }
}
//往工作队列中添加任务
bool CacheServer::append(Request request)
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
