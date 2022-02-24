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
        LinkedNode<T>* CreateRoot(const T& x)
        void clear();
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
    cout<<
}





#endif