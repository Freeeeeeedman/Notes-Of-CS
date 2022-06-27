#ifndef _ADJGRAPH_
#define _ADJGRAPH_
#include <iostream>
#include "LinkQueue.h"
using namespace std;

const int INFINITY=INT_MAX;
const int MAX_VERTEX_NUM=30;

template<class T>
class AdjGraph
{
    private:
        T m_vertex[MAX_VERTEX_NUM];
        int m_nAdjMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
        int m_nVertexNum;
        int m_nGraphType;
    public:
        AdjGraph(int nGraphType);
        bool DFSTraverse(int nV,int);
        void DFS(int nV,bool bVisited[]);
        bool DFSTraverse(int nV);
        void BFSTraverse(int nV);
        int GetVertexNum();
        int GetFirstEdge(int nV); 
        int GetNextEdge(int nV1,int nV2);
        bool AddOneVertex(const T& vertex);
        bool AddOneEdge(int nV1,int nV2,int nWeight);
        bool GetVertexValue(int nV,T& vertex);
        bool IsEdge(int nV1,int nV2);
        bool SetEdgeWeight(int nV1,int nV2,int nWeight);
        bool GetEdgeWeight(int nV1,int nV2,int& nWeight);
    
};

template<class T>
AdjGraph<T>::AdjGraph(int nGraphType)
{
    int nI,nJ;
    m_nGraphType=nGraphType;
    m_nVertexNum=0;
    for(nI=0;nI<MAX_VERTEX_NUM;nI++)
    for(nJ=0;nJ<MAX_VERTEX_NUM;nJ++)
        m_nAdjMatrix[nI][nJ]=INFINITY;

}

template<class T>
int AdjGraph<T>::GetVertexNum()
{
    return m_nVertexNum;
}

template<class T>
bool AdjGraph<T>::IsEdge(int nV1,int nV2)
{
    return m_nAdjMatrix[nV1][nV2]!=INFINITY;
}

template<class T>
int AdjGraph<T>::GetFirstEdge(int nV)
{
    int nJ;
    if(nV<0||nV>=m_nVertexNum)
        return -1;
    for(nJ=0;nJ<m_nVertexNum;nJ++)
        if(IsEdge(nV,nJ))
            return nJ;
    return -1;
}

template<class T>
int AdjGraph<T>::GetNextEdge(int nV1,int nV2)
{
    int nJ;
    if(!IsEdge(nV1,nV2))
        return -1;
    for(nJ=nV2+1;nJ<m_nVertexNum;nJ++)
        if(IsEdge(nV1,nJ))
            return nJ;
    return -1;
}

template<class T>
bool AdjGraph<T>::AddOneVertex(const T& vertex)
{
    if(m_nVertexNum>=MAX_VERTEX_NUM)
        return false;
    m_vertex[m_nVertexNum]=vertex;
    m_nVertexNum++;
    return true;
}

template<class T>
bool AdjGraph<T>::GetVertexValue(int nV,T& vertex)
{
    if(nV<0||nV>=m_nVertexNum)
        return false;
    vertex=m_vertex[nV];
    return true;
}

template<class T>
bool AdjGraph<T>::AddOneEdge(int nV1,int nV2,int nWeight)
{
    if(nV1<0||nV1>m_nVertexNum||nV2<0||nV2>m_nVertexNum||IsEdge(nV1,nV2))
        return false;
    m_nAdjMatrix[nV1][nV2]=nWeight;
    if(m_nGraphType==0)
        m_nAdjMatrix[nV2][nV1]=nWeight;
    return true;
}
template<class T>
bool AdjGraph<T>::SetEdgeWeight(int nV1,int nV2,int nWeight)
{
    if(!IsEdge(nV1,nV2))
        return false;
    m_nAdjMatrix[nV1][nV2]=nWeight;
    return true;
}

template<class T>
bool AdjGraph<T>::GetEdgeWeight(int nV1,int nV2,int& nWeight)
{
    if(!IsEdge(nV1,nV2))
        return false;
    nWeight=m_nAdjMatrix[nV1][nV2];
    return true;
}



#endif