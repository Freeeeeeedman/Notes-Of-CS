#ifndef _LINKEDBINTREE_
#define _LINKEDBINTREE_
#include <iostream>
#include "LinkQueue.h"
#include "LinkStack.h"
using namespace std;

template<class T>
class LinkedNode
{
    template<class T>
    friend class LinkedBinTree;
public:
    LinkedNode(){m_pLeftChild=m_pRightChild=NULL;}
    LinkedNode(const T& x)
    {
        m_pLeftChild=m_pRightChild=NULL;
        m_data=x;
    }
private:
    T m_data;
    LinkedNode<T>* m_pLeftChild,*m_pRightChild;
};



template<class T>
class LinkedBinTree
{
    public:
        LinkedBinTree();
        ~LinkedBinTree();
        bool IsEmpty();
        LinkedNode<T>* CreateRoot(const T& x);
        void Clear();
        LinkedNode<T>* GetRoot();
        LinkedNode<T>* InsertLeftChild(LinkedNode<T>* pNode,const T& x);
        LinkedNode<T>* InsertRightChild(LinkedNode<T>* pNode,const T& x);
        bool ModifyNodeValue(LinkedNode<T>* pNode,const T& x);
        bool GetNodeValue(LinkedNode<T>* pNode,T& x);
        LinkedNode<T>* GetLeftChild(LinkedNode<T>* pNode);
        LinkedNode<T>* GetRightChild(LinkedNode<T>* pNode);
        void PreOrderTraverse(LinkedNode<T>* pNode);
        void InOrderTraverse(LinkedNode<T>* pNode);
        void PostOrderTraverse(LinkedNode<T>* pNode);
        void PreOrderTraverse();
        void InOrderTraverse();
        void PostOrderTraverse();
        void LevelOrderTraverse();
        LinkedNode<T>* GetParent(LinkedNode<T>* pNode);
        void DeleteSubTree(LinkedNode<T>* pNode);
        void DeleteSubTreeNode(LinkedNode<T>* pNode);
        LinkedNode<T>* SearchByKey(const T& x);

    private:
        LinkedNode<T>* m_pRoot;
};


template<class T>
LinkedBinTree<T>::LinkedBinTree()
{
    m_pRoot=NULL;
}

template<class T>
LinkedNode<T>* LinkedBinTree<T>::CreateRoot(const T& x)
{
    if(m_pRoot!=NULL)
        m_pRoot->m_data=x;
    else
        m_pRoot=new LinkedNode<T>(x);
    return m_pRoot;
}

template<class T>
bool LinkedBinTree<T>::IsEmpty()
{
    return m_pRoot==NULL;
}

template<class T>
LinkedNode<T>* LinkedBinTree<T>::GetRoot()
{
    return m_pRoot;
}

template<class T>
LinkedNode<T>* LinkedBinTree<T>::InsertLeftChild(LinkedNode<T>* pNode,const T& x)
{
    LinkedNode<T>* pNewNode;
    if(pNode==NULL)
        return NULL;
    pNewNode=new LinkedNode<T>(x);
    if(pNewNode==NULL) return NULL;
    pNode->m_pLeftChild=pNewNode;
    return pNewNode;
}

template<class T>
LinkedNode<T>* LinkedBinTree<T>::InsertRightChild(LinkedNode<T>* pNode,const T& x)
{
    LinkedNode<T>* pNewNode;
    if(pNode==NULL)
        return NULL;
    pNewNode=new LinkedNode<T>(x);
    if(pNewNode==NULL) return NULL;
    pNode->m_pRightChild=pNewNode;
    return pNewNode;
}

template<class T>
bool LinkedBinTree<T>::ModifyNodeValue(LinkedNode<T>* pNode,const T& x)
{
    if(pNode==NULL)
        return false;
    pNode->m_data=x;
    return true;
}

template<class T>
bool LinkedBinTree<T>::GetNodeValue(LinkedNode<T>* pNode, T& x)
{
    if(pNode==NULL)
        return false;
    x=pNode->m_data;
    return true;
}

template<class T>
LinkedNode<T>* LinkedBinTree<T>::GetLeftChild(LinkedNode<T>* pNode)
{
    if(pNode==NULL)
        return NULL;
    return pNode->m_pLeftChild;
}

template<class T>
LinkedNode<T>* LinkedBinTree<T>::GetRightChild(LinkedNode<T>* pNode)
{
    if(pNode==NULL)
        return NULL;
    return pNode->m_pRightChild;
}

template<class T>
void LinkedBinTree<T>::PreOrderTraverse(LinkedNode<T>* pNode)
{
    if(pNode==NULL)
        return;
    cout<<pNode->m_data<<" ";
    PreOrderTraverse(pNode->m_pLeftChild);
    PreOrderTraverse(pNode->m_pRightChild);
}

template<class T>
void LinkedBinTree<T>::PreOrderTraverse()
{
    LinkStack<LinkedNode<T>*>s;
    LinkedNode<T>* pNode=NULL;
    if(m_pRoot==NULL)
        return;
    s.Push(m_pRoot);
    while(!s.IsEmpty)
    {
        s.Pop(pNode)
        cout<<pNode->m_data<<" ";
        if(pNode->m_pRightChild)
            s.Push(pNode->m_pRightChild);
        if(pNode->m_pLeftChild)
            s.Push(pNode->m_pLeftChild)
    }
}

template<class T>
void LinkedBinTree<T>::InOrderTraverse(LinkedNode<T>* pNode)
{
    if(pNode==NULL)
        return;
    InOrderTraverse(pNode->m_pLeftChild);
    cout<<pNode->m_data<<" ";
    InOrderTraverse(pNode->m_pRightChild);
}


template<class T>
void LinkedBinTree<T>::PostOrderTraverse(LinkedNode<T>* pNode)
{
    if(pNode==NULL)
        return;
    InOrderTraverse(pNode->m_pLeftChild);
    InOrderTraverse(pNode->m_pRightChild);
    cout<<pNode->m_data<<" ";
}

template<class T>
void LinkedBinTree<T>::LevelOrderTraverse()
{
    LinkQueue<LinkedNode<T>*>q;
    LinkedNode<T>* pNode = NULL;
    if(m_pRoot==NULL)
        return;
    q.Insert(m_pRoot);
    while(!q.IsEmpty())
    {
        q.Delete(pNode);
        cout<<pNode->m_data<<" ";
        if(pNode->m_pLeftChild)
            q.Insert(pNode->m_pLeftChild);
        if(pNode->m_pRightChild)
            q.Insert(pNode->m_pRightChild);        
        
    }
}

template<class T>
LinkedNode<T>* LinkedBinTree<T>::GetParent(LinkedNode<T>* pNode)
{
    LinkQueue<LinkedNode<T>*>q;
    LinkedNode<T>* pCurNode=NULL;
    if(pNode==m_pRoot)
        return NULL;
    if(m_pRoot==NULL)
        return NULL;
    q.Insert(m_pRoot);
    while(!q.IsEmpty())
    {
        q.Delete(pCurNode);
        if(pCurNode->m_pLeftChild==pNode||pCurNode->m_pRightChild==pNode)
            return pCurNode;
        if(pCurNode->m_pLeftChild)
            q.Insert(pCurNode->m_pLeftChild);
        if(pCurNode->m_pRightChild)
            q.Insert(pCurNode->m_pRightChild);
    }
    return NULL;
}


template<class T>
void LinkedBinTree<T>::DeleteSubTree(LinkedNode<T>* pNode)
{
    LinkedNode<T>* pParentNode=NULL;
    if(pNode==NULL)
        return;
    if(m_pRoot==NULL)
        return;
    else if((pParentNode=GetParent(pNode))!=NULL)
    {
        if(pParentNode->m_pLeftChild==pNode)
            pParentNode->m_pLeftChild=NULL;
        else
            pParentNode->m_pRightChild=NULL;
    }  
    else 
        return;
    DeleteSubTreeNode(pNode);
}

template<class T>
void LinkedBinTree<T>::DeleteSubTreeNode(LinkedNode<T>* pNode)
{
    LinkQueue<LinkedNode<T>*>q;
    LinkedNode<T>* pCurNode=NULL;
    if(pNode==NULL)
        return;
    q.Insert(pNode);
    while(q.IsEmpty())
    {
        q.Delete(pCurNode);
        if(pCurNode->m_pLeftChild)
            q.Insert(pCurNode->m_pLeftChild);
        if(pCurNode->m_pRightChild)
            q.Insert(pCurNode->m_pRightChild);
        delete pCurNode;

    }

}

template<class T>
LinkedNode<T>* LinkedBinTree<T>::SearchByKey(const T& x)
{
    LinkQueue<LinkedNode<T>*>q;
    LinkedNode<T>* pMatchNode=NULL;
    if(m_pRoot==NULL)
        return NULL;
    q.Insert(m_pRoot);
    while(q.IsEmpty())
    {
        q.Delete(pMatchNode);
        if(pMatchNode->m_data==x)
            return pMatchNode;
        if(pMatchNode->m_pLeftChild)
            q.Insert(pMatchNode->m_pLeftChild);
        if(pMatchNode->m_pRightChild)
            q.Insert(pMatchNode->m_pRightChild);

    }
    return NULL;
}

template<class T>
void LinkedBinTree<T>::Clear()
{
    DeleteSubTree(m_pRoot);
}

template<class T>
LinkedBinTree<T>::~LinkedBinTree()
{
    Clear();
}

template<class T>
void InsertBST(LinkedBinTree<T>& btree,T K)
{
    LinkedNode<T>* pNode=NULL,*pChild=NULL;
    T x;
    if(btree.IsEmpty())
    {
        btree.CreateRoot(K);
        return;
    }
    pNode=btree.GetRoot;
    while(pNode)
    {
        btree.GetNodeValue(pNode,x);
        if(K == x)
            return;
        if(K < x)
        {
            if((pChild=btree.GetLeftChild(pNode))!=NULL)
                pNode = pChild;
            else
            {
                btree.InsertLeftChild(pNode,K);
                return;
            }
        }
        else
        {
            if((pChild=btree.GetRightChild(pNode))!=NULL)
            pNode = pChild;
            else
            {
                btree.InsertRightChild(pNode,K);
                return;
            }
        }
    }
}

template<class T>
void CreateBST(T R[],int nSize,LinkedBinTree<T>& btree)
{
    for(int n=1;n<=nSize;n++)
    {
        InsertBST(btree,R[n]);
    }

}

template<class T>
LinkedNode<T>* SearchBST(LinkedNode<T>*pRoot,T K)
{
    LinkedBinTree<T>btree;
    T x;
    btree.GetNodeValue(pRoot,x);
    if(K==x)
        return pRoot;
    else if(K<x)
        return SearchBST(btree.GetLeftChild(pRoot),K);
    else
        return SearchBST(btree.GetRightChild(pRoot),K);
}








#endif