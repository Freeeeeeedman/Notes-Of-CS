#ifndef _LINEARQUEUE_
#define _LINEARQUEUE_
#include <iostream>
using namespace std;

template<class T>
class LinearQueue
{
    public:
        LinearQueue(int LQMaxSize);
        ~LinearQueue();
        bool IsEmpty();
        bool IsFull();
        bool Insert(const T& x);
        bool GetElement(T& x);
        bool Delete(T& x);
        void OutPut(ostream& out)const;
    private:
        int size;
        int MaxSize;
        int front,rear;
        T* element;

};


template<class T>
LinearQueue<T>::LinearQueue(int LQMaxSize):MaxSize(LQMaxSize)
{
    element=new T[MaxSize];
    size=0;
    front=0;
    rear=0;
}

template<class T>
LinearQueue<T>::~LinearQueue()
{
    delete[] element;
}

template<class T>
bool LinearQueue<T>::IsEmpty()
{
    return size==0;
}

template<class T>
bool LinearQueue<T>::IsFull()
{
    return size==MaxSize;
}

template<class T>
bool LinearQueue<T>::Insert(const T& x)
{
    if(IsFull())
        return false;
    else
    {
        element[rear]=x;
        rear=(rear+1)%(MaxSize);
        size++;
        return true;
    }
}

template<class T> 
bool LinearQueue<T>::GetElement(T& x)
{
    if(IsEmpty())
        return false;
    else
    {
        x=element[front];
        return true;
    }
}

template<class T>
bool LinearQueue<T>::Delete(T& x)
{
    if(IsEmpty())
        return false;
    else
    {
        x=element[front];
        front=(front+1)%(MaxSize);
        size--;
        return true;
    }
}

template<class T>
void LinearQueue<T>::OutPut(ostream& out)const
{
    int index;
    index=front;
    for(int i=0;i<size;i++)
    {
        out<<element[index]<<endl;
        index=(index+1)%MaxSize;
    }
}

template<class T>
ostream& operator<<(ostream& out,const LinearQueue<T>& x)
{
    x.OutPut(out);
    return out;
}











#endif