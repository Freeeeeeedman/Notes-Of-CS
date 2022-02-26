#ifndef _ADJLINKEDGRAPH_
#define _ADJLINKEDGRAPH_
#include <iostream>
#include "LinkQueue.h"
using namespace std;

const int INFINITY=INT_MAX;
const int MAX_VERTEX_NUM=30;

template<class T>
class AdjLinkedGraph
{   
    public:
        bool BFSTraverse(int nV);
        bool DFSTraverse(int nV,int);
        void DFS(int nV,bool bVisited[]);
        bool GetVertexValue(int nV,T& vertex);
        int GetVertexNum();
        int GetFirstEdge(int nV); 
        int GetNextEdge(int nV1,int nV2);
        bool AddOneVertex(const T& vertex);
        bool AddOneEdge(int nV1,int nV2,int nWeight);
        bool GetVertexValue(int nV,T& vertex);
        bool IsEdge(int nV1,int nV2);
        bool SetEdgeWeight(int nV1,int nV2,int nWeight);
        bool GetEdgeWeight(int nV1,int nV2,int& nWeight);
    private:
        int m_nVertexNum;
};

template<class T>
bool AdjLinkedGraph<T>::BFSTraverse(int nV)
{
    LinkQueue<int> queue;
    int nVisitVertex,nVertex,nBegVertex=nV;
    bool bVisited[MAX_VERTEX_NUM];
    T vertex;
    if(nV<0||nV>=m_nVertexNum)
        return false;
    memset(bVisited,0,sizeof(bVisited));    
    while(1)
    {
        queue.Insert(nBegVertex);
        bVisited[nBegVertex]=true;
        while(!queue.IsEmpty())
        {
            queue.Delete(nVisitVertex);
            GetVertexValue(nVisitVertex,vertex);
            cout<<vertex<<' ';
            nVertex=GetFirstEdge(nVisitVertex);
            while(nVertex!=-1)
            {
                if(bVisited[nVertex]==false)
                {
                    queue.Insert(nVertex);
                    bVisited[nVertex]=true;
                }
                nVertex=GetNextEdge(nVisitVertex,nVertex);

            }

        }
        int n=nBegVertex+1;
        for(;n<m_nVertexNum+nV;n++)
        {
            if(bVisited[n%m_nVertexNum]==false)
            {
                nBegVertex=n%m_nVertexNum;
                break;
            }
        }
        if(n==m_nVertexNum+nV) break;
    }
    return true;
}

template <class T>
bool AdjLinkedGraph<T>::DFSTraverse(int nV,int)
{
    int nBegVertex;
    bool bVisited[MAX_VERTEX_NUM];
    if(nV<0||nV>=m_nVertexNum)
        return false;
    memset(bVisited,0,sizeof(bVisited));
    for(nBegVertex=nV;nBegVertex<m_nVertexNum+nV;nBegVertex++)
    {
        if(bVisited[nBegVertex%m_nVertexNum]==false)
            DFS(nBegVertex,bVisited);
    }
    return true;

}

template<class T>
void AdjLinkedGraph<T>::DFS(int nV,bool bVisited[])
{
    T vertex;
    int nVertex;
    GetVertexValue(nV,vertex);
    cout<<vertex<<' ';
    bVisited[nV]=true;
    nVertex=GetFirstEdge(nV);
    while(nVertex!=-1)
    {
        if(bVisited[nVertex]==false)
            DFS(nVertex,bVisited);
        nVertex=GetNextEdge(nV,nVertex);
    }
}

#endif