/*
    记录一些面试中会考到的重要的代码
*/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// 智能指针

//auto_ptr
/*
    调用方式
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
        
        //拷贝
        auto_ptr(auto_ptr<T> &ap):_ptr(ap._ptr) {
            ap._ptr = nullptr;
        }
        
        //赋值
        auto_ptr<T>& operator=(auto_ptr<T> &ap) {
            if(this != &ap) {
                delete _ptr;
                _ptr = ap._ptr;
                ap._ptr = nullptr;
            }
            return *this;
        } 

        //重载
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
        //禁止拷贝与赋值
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

        //拷贝
        shared_ptr(shared_ptr<T> &sp):_ptr(sp._ptr), _pcount(sp._pcount) {
            ++(*_pcount);
        }

        //赋值
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









//冒泡排序
void bubbleSort(vector<int> &vec) {
    int n = vec.size() - 1;
    bool order = false;
    for(int i = 0; i <= n && !order; ++i) {
        order = true;
        for(int j = 0; j < n - i; ++j) {
            if(vec[j] > vec[j + 1]) {
                order = false;
                swap(vec[j], vec[j + 1]);
            }
        }
    }
}

void selectionSort(vector<int> &vec) {
    int n = vec.size() - 1;
    int min;
    for(int i = 0; i < n; ++i) {
        min = i;
        for(int j = i + 1; j <= n; ++j) {
            if(vec[min] > vec[j]) {
                min = j;
            }
        }
        swap(vec[min], vec[i]);
    }
}










int main() {
    vector<int> vec{0, 2, 5, 6, 1, 7, 9, 4, 3, 8};
    // bubbleSort(vec);
    selectionSort(vec);
    for(auto &i : vec) {
        cout << i << ' ';
    }
    int a = 1;

}