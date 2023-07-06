#ifndef VOTE_H
#define VOTE_H

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

struct CNode{

public:
    string name;
    float score;
    CNode *pre;
    CNode *next;
    CNode(){}
    CNode(string _name) : name(_name), score(0.0), pre(nullptr), next(nullptr){}
    ~CNode(){
        delete pre;
        delete next;
    }
};

class DLinkList
{
public:
    CNode *head;
    CNode *tail;
public:
    DLinkList();
    ~DLinkList();

    void update(CNode *node);
    void addNode(CNode *node);
    string getTop3();
};

class Vote{

public:
    Vote();
    ~Vote();
    long getVoatID(){return m_voteID;}
    void setVoteID(long id);
    string getVoteName(){return m_voteName;}
    void setVoteName(string votename);
    void setStartTime(long startTime);
    long getStopTime(){return m_stopTime;}
    void setStopTime(long stopTime);
    void setNormalWeight(float normalWeight);
    void setProfessionWeight(float professionWeight);
    int addCandidate(string name);
    int addNormalJudge(string name);
    int addProfessionalJudge(string name);
    float voteByNormalJudge(string name);
    float voteByProfessionalJudge(string name);

    DLinkList getCandidateList() {return candidateList;}

private:
    long m_voteID;
    string m_voteName; //投票名称
    time_t m_stratTime;  //投票开始时间
    time_t m_stopTime; //投票截止时间

    long m_candidateNum; //候选人人数
    unordered_map<string, CNode*> candidates;  //候选人及得票信息
    DLinkList candidateList;
    
    long m_normalJudgeNum;    //大众评委人数
    float m_normalWeight;
    unordered_map<string, int> normalJudges; //大众评委
    long m_professionalJudgeNum;  //专业评委数量
    float m_professionalWeight;
    unordered_map<string, int> professionalJudges; //专业评委


};

#endif