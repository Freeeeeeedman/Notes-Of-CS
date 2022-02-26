#ifndef _LINKSTACK_
#define _LINKSTACK
#include <iostream>
using namespace std;


template<class T>
class LinkNode
{
    template<class T>
    friend class LinkStack;
public:
    LinkNode(){next=NULL;}
private:
    T data;
    LinkNode<T>* next;

};



template<class T>
class LinkStack
{
public:
    LinkStack();
    ~LinkStack();
    bool IsEmpty()const;
    bool Push(const T&x);
    bool Top(T& x);
    bool Pop(T& x);
    void OutPut(ostream& out)const;
private:
    LinkNode<T>* top;
    int size;
};

template<class T>
LinkStack<T>::LinkStack()
{
    top=NULL;
    size=0;
}

template<class T>
LinkStack<T>::~LinkStack()
{
    T x;
    while(top!=NULL)
        Pop(x);
}

template<class T>
bool LinkStack<T>::IsEmpty()const
{
    return top==NULL;
}

template<class T>
bool LinkStack<T>::Push(const T& x)
{
    LinkNode<T>* p=new LinkNode<T>;
    if(p==NULL)
        return false;
    else
    {
        p->data=x;
        p->next=top;
        top=p;
        size++
        return true;
    } 
}


template<class T>
bool LinkStack<T>::Top(T& x)
{
    if(IsEmpty())
        return false;
    else
    {
        x=top->data;
        return true;
    }
}


template<class T>
bool LinkStack<T>::Pop(T& x)
{
    LinkNode<T>* p;
    if(IsEmpty())
        return false;
    else
    {
        x=top->data;
        p=top;
        top=top->next;
        delete p;
        size--;
        return true;
    }
}

template<class T>
void LinkStack<T>::OutPut(ostream& out)const
{
    LinkNode<T>* p;
    p=top;
    for(int i=0;i<size;i++)
    {
        out<<p->data<<endl;
        p=p->next;
    }
}

template<class T>
ostream& operator<<(ostream& out,const LinkStack<T>& x)
{
    x.OutPut(out);
    return out;
}








#endif