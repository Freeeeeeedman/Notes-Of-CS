/*
    ��¼һЩ�����лῼ������Ҫ�Ĵ���
*/

#include <iostream>
using namespace std;

// ����ָ��

//auto_ptr
/*
    ���÷�ʽ
    auto_ptr<int> a1(new int(1));
    auto_ptr<int> a2(a1);

*/
template <class T>
class auto_ptr {
    private:
        T *_ptr;
    public:
        auto_ptr(T *ptr = nullptr):_ptr(ptr) {}
        
        ~auto_ptr() {
            if(_ptr != nullptr) {
                delete _ptr;
            }
        }
        
        //����
        auto_ptr(auto_ptr<T> &ap):_ptr(ap._ptr) {
            ap._ptr = nullptr;
        }
        
        //��ֵ
        auto_ptr<T>& operator=(auto_ptr<T> &ap) {
            if(this != &ap) {
                delete _ptr;
                _ptr = ap._ptr;
                ap._ptr = nullptr;
            }
            return this*;
        } 

        //����
        T& operator*() {
            return *_ptr;
        }

        T& operator->() {
            return _ptr;  
        }
        
};

//unique_ptr

template <class T> 
class unique_ptr {
    public:
        //��ֹ�����븳ֵ
        unique_ptr(unique_ptr<T> &up) = delete;
        unique_ptr<T> &operator=(unique_ptr<T> &up) = delete;
};

//shared_ptr

template <class T> 
class shared_ptr {
    private:
        T *_ptr;
        int *_pcount;
    public:
        shared_ptr(T *ptr = nullptr):_ptr(ptr), _pcount(new int(1)) {}

        ~shared_ptr() {
            --(*_pcount);
            if((*_pcount) == 0) {
                delete _ptr;
                _ptr = nullptr;
                delete _pcount;
                _pcount = nullptr;
            }
        }

        //����
        shared_ptr(shared_ptr<T> &sp):_ptr(sp._ptr), _pcount(sp._pcount) {
            ++(*_pcount);
        }

        //��ֵ
        shared_ptr<T> &operator=(const shared_ptr<T> &sp) {
            if(this != &sp) {
                if(*(_pcount) == 0) {
                    delete _ptr;
                    delete _pcount;
                }
                _ptr = sp._ptr;
                _pcount = sp._pcount;
                ++(*_pcount);
            }
            return this;
        }
};