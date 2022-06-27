#ifndef _LINEARSTACK_
#define _LINEARSTACK_
#include <iostream>
using namespace std;


template<class T>
class LinearStack
{
    public:
        LinearStack(int LSMaxSize);
        ~LinearStack();
        bool IsEmpty();
        bool IsFull();
        int GetElementNumber();
        bool Push(const T& x);
        bool Top(T& x);
        bool Pop(T& x);
        void OutPut(ostream& out)const;
    private:
        int top;
        int MaxSize;
        T* element;
};

template<class T>
LinearStack<T>::LinearStack(int LSMaxSize):MaxSize(LSMaxSize)
{
    element=new T[LSMaxSize];
    top=-1;
}

template<class T>
LinearStack<T>::~LinearStack()
{
    delete []element;
}

template<class T>
bool LinearStack<T>::IsEmpty()
{
    return top==-1;
}

template<class T>
bool LinearStack<T>::IsFull()
{
    return top+1==MaxSize;
}

template<class T>
bool LinearStack<T>::Push(const T& x)
{
    if(IsFull())
        return false;
    else
    {
        top++;
        element[top]=x;
        return true;
    }
}

template<class T>
bool LinearStack<T>::Top(T& x)
{
    if(IsEmpty())
        return false;
    else
    {        
        x=element[top];
        return true;
    }
}

template<class T>
bool LinearStack<T>::Pop(T& x)
{
    if(IsEmpty())
        return false;
    else
    {
        x=element[top];
        top--;
        return true;

    }
}

template<class T>
void LinearStack<T>::OutPut(ostream& out)const
{
    for(int i=0;i<=top;i++)
        out<<element[i]<<endl;

}

template<class T>
ostream& operator<<(ostream& out,LinearStack<T>& x)
{
    x.OutPut(out);
    return out;
} 



#endif