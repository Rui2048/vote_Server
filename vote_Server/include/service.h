#ifndef CACHE_SERVICE
#define CACHE_SERVICE

#include <arpa/inet.h>
#include <sys/epoll.h>
#include <list>
#include <string>
#include <vector>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <thread>
#include <unistd.h>
#include <stdlib.h>
#include "log.h"
#include "config.h"
#include "vote.h"

class VoteServer;

//cache_server类
class VoteServer
{
    public:
    VoteServer();
    ~VoteServer();
    //初始化cache_server
    int init();
    void setPort(int port) {cache_server_port = port;}  //设置监听端口
    int startListen();  //开启监听
    int connectToServer(); //连接服务器
    int eventLoop();  //开启事件循环
    
    //epoll相关
    private:
    int epfd; //epoll文件描述符
    int epollAddfd(int fd); //向epoll中添加文件描述符
    int epollDelfd(int fd); //从epoll中删除文件描述符

    //日志
    private:
    int m_close_log = 0;  // 0:开启日志  1:关闭日志
    //int m_log_write_model = 0;  // 0:异步日志  1:同步日志

    int lfd;
    sockaddr_in cache_server_sockaddr; //cache_server本地监听地址
    int cache_server_port; //cache_server本地监听默认端口9000

    //与服务器通信
    int cfd;
    int serverPort = 6343;
    string server_ip = "172.20.10.3";
    sockaddr_in server_sockaddr;

    std::map<int, std::string> connectedMap;
    //unordered_set<int> sockfd_set;
    locker sockfd_mutex;

    //线程池
    private:
    int m_thread_number = 8;        //线程池中的线程数
    int m_max_requests = 20;         //请求队列中允许的最大请求数
    pthread_t *m_threads;       //描述线程池的数组，其大小为m_thread_number
    std::list<string> m_workqueue; //请求队列
    locker m_queuelocker;       //保护请求队列的互斥锁
    sem m_queuestat;            //是否有任务需要处理

    //初始化线程池
    int threadInit(int thread_number = 8, int max_requests = 20);
    /*工作线程运行的函数，它不断从工作队列中取出任务并执行之*/
    static void *worker(void *arg);
    void run(); 
    bool append(string request); //往工作队列中添加任务

    public:
    //业务逻辑处理函数
    void dealWithCreateVote(string &request, bool testFlag = false);
    void dealWithLogin(string &request, bool testFlag = false);
    void dealWithVote(string &request, bool testFlag = false);
    void dealWithGetVoteResult(string &request, bool testFlag = false);
    void dealWithGetAllVotes(string &request, bool testFlag = false);
    void dealWithGetVotesByOneJudge(string &request, bool testFlag = false);

    //投票任务
    unordered_map<long, Vote> Votes;
    unordered_map<string, vector<long>> professionalJudgeVotes; //专业评委->[参与了哪些投票]
    unordered_map<string, vector<long>> normalJudgeVotes; //大众评委->[参与了哪些投票]

    //全局
    private:
    bool shutdown = false; //true:关闭服务器  false:不关闭
};

#endif //CACHE_SERVICE