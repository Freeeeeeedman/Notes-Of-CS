#ifndef _LINEARLIST_
#define _LINEARLIST_
#include <iostream>
using namespace std;
template <class T>
class LinearList
{
    public:
        LinearList(int LLMaxSize);
        ~LinearList();
        LinearList<T>& Insert(int k,const T& x);
        bool IsEmpty()const;
        int GetLength()const;
        bool GetData(int k,T& x);
        bool ModifyData(int k,const T& x);
        int Find(const T& x);
        LinearList<T>& DeleteByIndex(int k,T& x);
        LinearList<T>& DeleteByKey(const T& x,T& y);
        void OutPut(ostream& out)const;
    private:
        int length;
        int MaxSize;
        T* element;
};

template <class T>
LinearList<T>::LinearList(int LLMaxSize):MaxSize(LLMaxSize)
{
    element = new T[LLMaxSize];
    length=0;
}

template<class T>
LinearList<T>::~LinearList()
{
    delete []element;
}

template<class T> 
LinearList<T>& LinearList<T>::Insert(int k,const T& x)
{
    if(k<1||k>length+1){cout<<"元素下标越界,添加元素失败"<<endl;}
    else if (length==MaxSize){cout<<"此表已满,无法添加新元素"<<endl;}
    else
    {
        for(int i=length;i>k-1;i--)
            element[i]=element[i-1];
        element[k-1]=x;
        length++;        
    }
    return *this;
}

template<class T>
bool LinearList<T>::IsEmpty()const
{
    return length==0;
}

template<class T>
int LinearList<T>::GetLength()const
{
    return length;
}

template<class T>
bool LinearList<T>::GetData(int k,T& x)
{
    if(k<1||k>length)
        return false;
    else
    {
        x=element[k-1];
        return true;
    }
}

template<class T>
bool LinearList<T>::ModifyData(int k,const T& x)
{
    if(k<1||k>length)
        return false;
    else
    {
        element[k-1]=x;
        return true;
    }
}

template<class T>
int LinearList<T>::Find(const T& x)
{
    for(int i=0;i<length;i++)
        if(element[i]==x)
            return i+1;
    return 0;
}

template<class T>
LinearList<T>& LinearList<T>::DeleteByIndex(int k,T& x)
{
    if(GetData(k,x))
    {
        for(int i=k-1;i<length;i++)
            element[i]=element[i+1];
        length--;   
    }
    else 
        cout<<"元素下标越界,删除失败"
    return *this;
}

template<class T>
LinearList<T>& LinearList<T>::DeleteByKey(const T& x,T& y)
{
    int index=Find(x);
    if(index!=0)
        return DeleteByIndex(index,y);
    else 
    {
        cout<<"没有此元素,删除失败"<<endl;
        return *this;
    }
}

template<class T>
void LinearList<T>::OutPut(ostream& out)const
{
    for(int i=0;i<length;i++)
        out<<element[i]<<endl;      //element[i]若为复杂元素需要再重载<<
}

template<class T>
ostream& operator<<(ostream& out,const LinearList<T>& x)
{
    x.OutPut(out);
    return out;
}


#endif