#ifndef _LINKLIST_
#define _LINKLIST_
#include<iostream>
using namespace std;


template<class T>
class LinkNode
{
    template<class T>
    friend class LinkList;
public:
    LinkNode(){next = NULL;}
private:
    T data;
    LinkNode<T>* next;
};


template<class T>
class LinkList
{
public:
    LinkList();
    ~LinkList();
    LinkList<T>& Insert(int k,const T& x);
    bool IsEmpty()const;
    int GetLength()const;
    bool GetData(int k,T& x);
    bool ModifyData(int k,const T& x);
    int Find(const T& x);
    LinkList<T>& DeleteByIndex(int k,T& x);
    LinkList<T>& DeleteByKey(const T& x,T& y);
    void OutPut(ostream& out);
private:
    LinkNode<T>* head;
};

template<class T>
LinkList<T>& LinkList<T>::Insert(int k,const T& x)
{
    LinkNode<T>* p=head;
    LinkNode<T>* newNode=new LinkNode<T>;
    newNode->data=x;
    int len=GetLength();
    if(k<1||k>len+1)
        cout<<"元素下标越界,添加元素失败"<<endl;
    else 
    {
        for(i=1;i<k;i++)
            p=p->next;
        newNode->next=p->next;
        p->next=newNode;
    }
    return *this;
}

template<class T>
LinkList<T>& LinkList<T>::DeleteByIndex(int k,T& x)
{
    if(GetData(k,x))
    {
        LinkNode<T>* p=head;
        LinkNode<T>* q=NULL;
        for(int i=1;i<k;i++)
            p=p->next;
        q=p->next;
        p->next=q->next;
        delete q;    
    }
    else
        cout<<"元素下标越界,删除失败"<<endl;
    return *this;
}

template<class T>
LinkList<T>& LinkList<T>::DeleteByKey(const T& x,T& y)
{
    int index=Find(x);
    if(index!=0)
        return DeleteByIndex(index,y);
    else
    {
        cout<<"没有此元素,删除失败"<<endl;
    }
    return *this;
    
}

template<class T>
LinkList<T>::LinkList()
{
    head=new LinkNode<T>();
}

template<class T>
LinkList<T>::~LinkList()
{
    T x;
    int len=GetLength();
    for(int i=len;i>=1;i--)
        DeleteByIndex(i,x);
    delete head;
}


template<class T>
bool LinkList<T>::IsEmpty() const
{
    return head->next=NULL;
}

template<class T>
int LinkList<T>::GetLength() const
{
    int length=0;
    LinkNode<T>* p=head->next;
    while(p)
    {
        length++;
        p=p->next;
    }
    return length;

}

template<class T>
bool LinkList<T>::GetData(int k,T& x)
{
    LinkNode<T>*p=head->next;
    int index=1;
    if(k<1||k>GetLength())
        return false;
    while(p!=NULL&&index<k)
    {
        index++;
        p=p->next;
    }
    if(p==NULL)
        return false;
    else
    {
        x=p->data;
        return true;
    }
}

template<class T>
bool LinkList<T>::ModifyData(int k,const T& x)
{
    LinkNode<T>*p=head->next;
    int index=1;
    if(k<1||k>GetLength())
        return false;
    while(p!=NULL&&index<k)
    {
        index++;
        p=p->next;
    }
    if(p==NULL)
        return false;
    else
    {
        p->data=x;
        return true;
    }
}

template<class T>
int LinkList<T>::Find(const T& x)
{
    LinkNode<T>* p=head->next;
    int index=1;
    while(p!=NULL&&p->data!=x)
    {
        p=p->next;
        index++;
    }
    if(p!=NULL)
        return index;
    else 
        return 0;
}

template<class T>
void LinkList<T>::OutPut(ostream& out)
{
    LinkNode<T>* p=head->next;
    while(p!=NULL)
    {
        out<<p->data<<endl;
        p=p->next;
    }    
}

template<class T>
ostream& operator<<(ostream& out,LinkList<T>& x)
{
    x.OutPut(out);
    return out;
}










#endif