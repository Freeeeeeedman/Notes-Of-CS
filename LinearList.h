#ifndef _LINEARLIST_
#define _LINEARLIST_

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




#endif