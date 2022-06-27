#ifndef _LINKQUEUE_
#define _LINKQUEUE_
#include <iostream>
using namespace std;

template<class T>
class LinkNode
{
    template<class T>
    friend class LinkQueue;
    public:
        LinkNode(){next=NULL};
    private:
        T data;
        LinkNode<T>* next;

};

template<class T>
class LinkQueue
{
    public:
        LinkQueue();
        ~LinkQueue();
        bool IsEmpty();
        bool Insert(const T& x);
        bool GetElement(T& x);
        bool Delete(T& x);
        void OutPut(ostream& out)const;
    private:
        int size;
        LinkNode<T>*front,*rear;
};

template<class T>
LinkQueue<T>::LinkQueue()
{
    front=NULL;
    rear=NULL;
    size=0;
}


template<class T>
LinkQueue<T>::~LinkQueue()
{   
    T x;
    while(front!=NULL)
        Delete(x);
}

template<class T>
bool LinkQueue<T>::IsEmpty()
{
    return size==0;
}

template<class T>
bool LinkQueue<T>::Insert(const T& x)
{
    LinkNode<T>* p=new LinkNode<T>;
    if(p==NULL)
        return false;
    else
    {
        p->data=x;
        if(front=NULL)
        {   
            rear=p;
            front=p;
        }
        else
        {
            rear->next=p;
            rear=p;
        }
        size++;
        return true;
    }
}

template<class T>
bool LinkQueue<T>::GetElement(T& x)
{
    if(IsEmpty())
        return false;
    else
    {
        x=front->data;
        return true;
    }
}

template<class T>
bool LinkQueue<T>::Delete(T& x)
{
    LinkNode<T>* p;
    if(IsEmpty())
        return false;
    else
    {
        p=front;
        x=front->data;
        front=front->next;
        delete p;
        size--;
        return true;
    }
}

template<class T>
void LinkQueue<T>::OutPut(ostream& out)const
{
    LinkNode<T>* p;
    p=front;
    for(int i=0;i<size;i++)
    {
        out<<p->data<<endl;
        p=p->next;
    }
}

template<class T>
ostream& operator<<(ostream&,const LinkQueue<T>& x)
{
    x.OutPut(out);
    return out;
}




#endif