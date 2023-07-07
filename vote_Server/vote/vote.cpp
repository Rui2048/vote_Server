#include "vote.h"

DLinkList::DLinkList()
{
    head = new CNode("head");
    tail = new CNode("tail");
    head->next = tail;
    tail->pre = head;
}

DLinkList::~DLinkList()
{
    CNode *cur = head;
    while (head != tail)
    {
        head = head->next;
        cur->next = nullptr;
        head->pre = nullptr;
        delete cur;
        cur = head;
    }
    head->next = nullptr;
    head->pre = nullptr;
    delete head;
}

void DLinkList::update(CNode *node)
{
    while (node->pre != head && node->score > node->pre->score)
    {
        CNode *tempNode = node->pre;
        tempNode->next = node->next;
        node->next->pre = tempNode;
        tempNode->pre->next = node;
        node->pre = tempNode->pre;
        node->next = tempNode;
        tempNode->pre = node;
    }
}

void DLinkList::addNode(CNode *node)
{
    node->next = head->next;
    head->next->pre = node;
    head->next = node;
    node->pre = head;
}

/*string DLinkList::getTop3()
{
    string res;
    CNode *cur = head->next;
    for (int i = 0; i < 3 && cur != tail; i++)
    {
        res += cur->name;
        res += ':';
        char sc[10] = {0};
        sprintf(sc, "%.2f", cur->score);
        res += sc;
        res += ',';
    }
    return res;
}*/

Vote::Vote()
{
    m_voteName = "null";
    m_stratTime = -1;
    m_stopTime = -1;
    m_candidateNum = 0;
    m_normalJudgeNum = 0;
    m_professionalJudgeNum = 0;
    m_normalWeight = 0.0;
    m_professionalWeight = 0.0;
}

Vote::~Vote()
{
    
}
void Vote::setVoteID(long id)
{
    m_voteID = id;
}
void Vote::setVoteName(std::string votename)
{
    m_voteName = votename;
}
void Vote::setStartTime(long startTime)
{
    m_stratTime = startTime;
}
void Vote::setStopTime(long stopTime)
{
    m_stopTime = stopTime;
}
void Vote::setNormalWeight(float normalWeight)
{
    m_normalWeight = normalWeight;
}
void Vote::setProfessionWeight(float professionWeight)
{
    m_professionalWeight = professionWeight;
}
int Vote::addCandidate(std::string name)
{
    m_candidateNum++;
    candidates[name] = new CNode(name);
    candidateList.addNode(candidates[name]);
    return m_candidateNum;
}
int Vote::addNormalJudge(std::string name)
{
    m_normalJudgeNum++;
    normalJudges[name] = 0;
    return m_normalJudgeNum;
}
int Vote::addProfessionalJudge(std::string name)
{
    m_professionalJudgeNum++;
    professionalJudges[name] = 0;
    return m_professionalJudgeNum;
}
float Vote::voteByNormalJudge(std::string name)
{
    candidates[name]->score += m_normalWeight;
    candidateList.update(candidates[name]);
    normalJudges[name] = 1;
    return candidates[name]->score;
}
float Vote::voteByProfessionalJudge(std::string name)
{
    candidates[name]->score += m_professionalWeight;
    candidateList.update(candidates[name]);
    professionalJudges[name] = 1;
    return candidates[name]->score;
}
