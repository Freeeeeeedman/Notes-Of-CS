/*
    记录一些面试中会考到的重要的代码
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;


//大小端转换
/*
    int a = 0x1234;
    char c = (char)(a);
    if(c == 0x12)
        cout << "big endian" << endl;
    else if(c == 0x34)
        cout << "little endian" << endl;
*/


//异常处理
/*
    double m ,n;
    cin >> m >> n;
    try {
        if( n == 0)
            throw -1; //抛出int类型异常
        else
            cout << m / n << endl;
    }
    catch(double d) {
        cout << "catch(double) " << d <<  endl;
    }
    catch(int e) {
        cout << "catch(int) " << e << endl;
    }
*/


//比较规范的类代码
class Complex {
    private:
        double real_;
        double imag_;
    
    public:
        Complex(double real, double imag): real_(real), imag_(imag){cout << "调用了构造函数" << endl;}
        Complex(double real): real_(real), imag_(0){cout << "调用了单参数构造函数" << endl;}
        Complex(const Complex &c);
        ~Complex(){}
        const double &getReal() const{return real_;}
        const double &getImag() const{return imag_;} 
        Complex operator+(const Complex &a);
        friend Complex operator-(const Complex &a, const Complex &b);
        friend ostream& operator<< (ostream &output, const Complex &a);
        operator double() const; 
};

inline 
Complex::Complex(const Complex &c) {
    cout << "调用了拷贝构造函数" << endl;
    this->real_ = c.real_;
    this->imag_ = c.imag_;
}

inline Complex
Complex::operator+(const Complex &a) {
    return Complex(a.real_ + this->real_, a.imag_ + imag_);
}

Complex operator-(const Complex &a, const Complex &b) {
    return Complex(a.real_ - b.real_, a.imag_ - b.imag_);
}

ostream& operator<<(ostream &output, const Complex &a) {
    output << "real = " << a.real_ << endl;
    output << "imag = " << a.imag_ << endl;
    return output;
}

inline 
Complex::operator double() const {
    return this->real_;
}


//深拷贝，移动构造函数
/*
    A a = getA();
    A(A& a): m_ptr(new int(a.m_data)){} //拷贝构造函数深拷贝,从堆中分配内存，用h.m_data初始化
    A(A&& a):m_ptr(a.m_ptr){a.m_ptr = nullptr;}

*/


//比较大小的函数模板
template <class T, class U>
bool compare(T a, U b) {
    return a > b ? true : false;//不同类型的比较需要重载>
}
//模板特例化
template <>
bool compare(int, int) {
    cout << "模板特例化" << endl;
    return true;
}
//部分特例化
template<class T, class U> 
class ClassA {
    T a;
    U b;
};
template<class T> 
class ClassA<T, int> {
    
};


//placement new
class Foo {
    public:
        int x;
        double y;
        ~Foo() {cout << "调用析构函数" << endl;}

};

//仿函数
/*
int a = 0, b = 1;
auto f1 = [a, b] {return a + b;}
*/


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

//插入排序
void insertSort(vector<int> &vec) {
    int n = vec.size() - 1;
    for(int i = 1; i <= n; i++) {
        int temp = vec[i];
        for(int j = i; j >= 1 && temp < vec[j - 1]; --j) {
            vec[j] = vec[j - 1];
            vec[j - 1] = temp;
        }
    }
}

//希尔排序
void shellSort(vector<int> &vec) {
    int n = vec.size() - 1;
    for(int gap = n / 2; gap > 0; gap /= 2) {
        for(int i = gap; i <= n; i++) {
            for(int j = i; j >= gap &&  vec[j] < vec[j - gap]; j-=gap) {
                swap(vec[j - gap], vec[j]);
            }
        }
    }
}

//归并排序
void merge(int *arr, int n) {
    int temp[n];//n为数组长度
    int i = 0;
    int mid = n / 2;
    int left = 0, right = mid;
    while(left < mid && right < n) {
        if(arr[left] < arr[right]) {
            temp[i++] = arr[left++];
        }else {
            temp[i++] = arr[right++];
        }
    }
    while(left < mid) {
        temp[i++] = arr[left++];
    }
    while(right < n) {
        temp[i++] = arr[right++];
    }
    for(int i = 0; i < n; i++) {
        arr[i] = temp[i];
    }
}

void mergeSort(int *arr, int n) {
    if(n <= 1) return;
    else {
        mergeSort(arr, n / 2);//分
        mergeSort(arr + n / 2, n - n / 2);
        merge(arr, n);//治
    }
    
}

//快速排序
void quickSort(vector<int> &vec, int left, int right) {
    if(left >= right) return;
    int first = left;
    int last = right;
    int key = vec[first];
    while(first < last) {
        while(first < last && vec[last] >= key) last--;
        if(first < last) vec[first++] = vec[last];
        while(first < last && vec[first] <= key) first++;
        if(first < last) vec[last--] = vec[first];
    }
    vec[first] = key;
    quickSort(vec, left, first - 1);
    quickSort(vec, first + 1, right);
}

//堆排序
void heapify(int *arr, int start, int end) {
    int father = start;
    int son = father * 2 + 1;
    while(son <= end) {
        if(son + 1<= end && arr[son] < arr[son + 1]) {
            son++;
        }
        if(arr[father] > arr[son]) return; //如果父节点值大于子节点值，因为是由底到顶构造的，
        else {                             //那么父节点就大于所有子节点
            swap(arr[father], arr[son]);//否则需要再循环查找子树
            father = son;
            son = father * 2 + 1;
        }
    }
}

void heapSort(int *arr, int n) {
    for(int i = n / 2 - 1; i >= 0; i--) { //由底到顶初始化子树
        heapify(arr, i, n - 1);
    }
    for(int i = n - 1; i > 0; i--) {//由顶到底取最大值
        swap(arr[0], arr[i]);
        heapify(arr, 0, i - 1);
    }
}

//计数排序
void countSort(vector<int> &vec) {
    int n = vec.size();
    if(n == 0) return;
    int mx = vec[0], mn = vec[0];
    vector<int> tmp(vec);
    for(int i = 0; i < n; ++i) {
        mx = max(mx, tmp[i]);
        mn = min(mn, tmp[i]);
    }
    int k = mx - mn + 1;
    int count[k]  = {0};
    for(int i = 0; i < n; ++i) {
        ++count[tmp[i] - mn];
    }
    for(int i = 1; i < k; ++i) {
        count[i] += count[i - 1];
    }
    for(int i = n - 1; i >= 0; --i) {
        vec[count[tmp[i] - mn]--] = tmp[i];//从后往前填数字
                                        //--count或者count--都可以都是先减再取值
                                            //因为count记录的是比自己小包括自己的数字的数目  
    }

}

//桶排序
void bucketSort(vector<int> &vec) {
   int n = vec.size();
   if(n == 0) return;
   int mx = vec[0], mn = vec[0];
   for(int i = 0; i < n; i++) {
        mx = max(mx, vec[i]);
        mn = min(mn, vec[i]);
   } 
   int k = mx - mn + 1;
   vector<int> buckets(k, 0);
   for(int i = 0; i < n; i++) {
        ++buckets[vec[i] - mn];
   }
   int num = 0;
   for(int i = 0; i < k; i++) {
        for(int j = 0; j < buckets[i]; j++) {
            vec[num++] = i + mn;
        }
   }
}

//基数排序
void radixSort(vector<int> &vec) {
    int n = vec.size();
    int mx = vec[0];
    for(int i = 0; i < n; i++) {
        mx = max(mx, vec[i]);
    }
    int bit = 0;
    while(mx) {
        mx /= 10;
        ++bit;
    }
    int div = 1;
    for(int i = 0; i < bit; i++) {
        int count[10] = {0};
        vector<int> tmp(n, 0);
        for(int i = 0; i < n; i++) {
            ++count[vec[i] / div % 10];
        }
        for(int i = 0; i < 10; i++) {
            count[i] += count[i - 1];
        }
        for(int i = n - 1; i >= 0; i--) {
            tmp[--count[vec[i] / div % 10 - 0]] = vec[i];//这里相当于数组内最小值为0，所以不能排序负数值
                                                        //如果要排序，则需要对数组整体加上一个偏移量，使得数组都为f非负整数，
                                                       //排序完成后再整体减去这个偏移量
        }
        div *= 10;
        vec = tmp;
    }

}


//LRU算法
struct DLinkedNode {
    int key, value;
    DLinkedNode *prev;
    DLinkedNode *next;
    DLinkedNode():key(0), value(0), prev(nullptr), next(nullptr){}
    DLinkedNode(int _key, int _value):key(_key), value(_value), prev(nullptr), next(nullptr){}
};

class LRUCache {
    private:
        int size;
        int capacity;
        unordered_map<int, DLinkedNode*> cache;//这里的key就是节点中的key值，但value为指向节点的指针
        DLinkedNode *head;
        DLinkedNode *tail;
    
    public:
        LRUCache(int _capacity):capacity(_capacity), size(0){
            head = new DLinkedNode();
            tail = new DLinkedNode();
            head->next = tail;
            tail->prev = head;
        }

        int get(int key) {
            if(!cache.count(key)) {
                return -1;
            }
            DLinkedNode *node = cache[key];
            moveToHead(node);//获取后移动到前端
            return node->value;
        }

        void put(int key, int value) {
            if(!cache.count(key)) {
                DLinkedNode *node = new DLinkedNode(key, value);
                cache[key] = node;
                node->prev = head;
                head->next->prev = node;
                node->next = head->next;
                head->next = node;//在前端添加新的节点
                ++size;               
                if(size > capacity) {
                    DLinkedNode *tmp = removeTail();
                    cache.erase(tmp->key); //在给链表添加或删除以及修改value时也要对cache做修改
                    delete tmp;
                    --size;

                }            
            }else {
                DLinkedNode *node = cache[key];
                node->value = value;
                moveToHead(node);//修改后移动到前端
            }

        }

        void moveToHead(DLinkedNode *node) {
            node->prev->next = node->next;
            node->next->prev = node->prev;
            
            node->prev = head;
            head->next->prev = node;
            node->next = head->next;
            head->next = node;
        }

        DLinkedNode *removeTail() {
            DLinkedNode *node = tail->prev;
            node->prev->next = node->next;
            node->next->prev = node->prev;
            return node;            
        }

};


/* 
   三种经典的同步问题

   1. 生产者与消费者问题
        ```
        sem mutex = 1;
        sem fullBuffer = n;
        sem emptyBuffer = 0;

        void producer() {
            while(1) {
                P(emptyBuffer);
                P(mutex);
                缓冲区加入数据
                V(mutex);
                V(fullBuffer);
            }
        }

        void consumer() {
            while(1) {
                P(fullBuffer);
                P(mutex);
                缓冲区读取数据
                V(mutex);
                V(emptyBuffer);
            }
        }
        ```

    2. 哲学家就餐问题
        ```
        sem fork[5] = {1};
        void person(int i) {
            while(1) {
                think();
                if(i % 2 == 0) {
                    P(fork[i]);
                    P(fork[(i + 1) % 5]);
                }else {
                    P(fork[(i + 1) % 5]);
                    P(fork[i]);
                }
            }
            V(fork[i]);
            V(fork[(i + 1) % 5]);
        }
        ```
    
    3. 读者与写者模型
        ```
        int rCount = 0;
        sem rCountMutex = 1;
        sem wDataMutex = 1;
        sem flag = 1;

        void writer() {
            P(flag);
            P(wDataMutex);
            write();
            V(wDaraMutex);
            V(flag);
        }

        void producer() {
            P(flag);
            P(rCountMutex);
            if(rCount == 0) {
                P(wDataMutex);
            }
            rCount++;
            V(rCountMutex);
            V(flag);
            
            read();

            P(rCountMutex);
            rCount--;
            if(rCount == 0) {
                V(wDataMutex);
            }
            V(rCountMutex);
        }
        ```

*/


//n进制转10进制
int ntoi(string &str, int radix) {
    int ans = 0;
    for(int i = 0; i < str.size(); ++i) {
        char ch = str[i];
        if(ch >= '0' && ch <= '9') {
            ans = ans * radix + ch - '0'; 
        }else {
            ans = ans * radix + ch - 'a' + 10;
        }
    }
    return ans;
}

//10进制转n进制
string iton(int n, int radix) {
    string ans;
    do {
        int t = n % radix;
        if(t >= 0 && t <= 9) {
            ans += t + '0';
        }else {
            ans += t - 10 + 'a';
        }
        n /= radix;
    }while(n != 0);//一开始n==0的情况也要计算,还有要记得加';'
    reverse(ans.begin(), ans.end());
    return ans;
}


//不使用额外空间的情况下，交换两个数
/*
    - 算数法:浮点型会有精度损失
        x = x + y;
        y = x - y;
        x = x - y;
    - 异或法:无法交换浮点型
    　a ^= b; // a=a^b
    　b ^= a; // b=b^(a^b)=b^a^b=b^b^a=0^a=a
    　a ^= b; // a=(a^b)^a=a^b^a=a^a^b=0^b=b
*/




















int main() {
    // vector<int> vec{0, 2, 5, 6, 1, 7, 9, 4, 3, 8};
    // int arr[] = {0, 2, 5, 6, 1, 7, 9, 4, 3, 8};
    // int n = sizeof(arr) / sizeof(arr[0]);
    // bubbleSort(vec);
    // selectionSort(vec);
    // insertSort(vec);
    // shellSort(vec);
    // mergeSort(arr, n);
    // quickSort(vec, 0, vec.size() - 1);
    // heapSort(arr, n);
    // countSort(vec);
    // bucketSort(vec);
    // radixSort(vec);
    // for(auto &i : vec) {
    //     cout << i << ' ';
    // }
    // for(int i = 0; i < 10; i++) {
    //     cout << arr[i] << ' ';
    // }

    // string radix2 = "11001";
    // string radix8 = "0144";    //0开头8进制
    // string radix16 = "0x541";  //0x开头10进制
    // string tmp = radix8.substr(1, radix16.size() - 1);    
    // // string tmp = radix16.substr(2, radix16.size() - 2);
    // int i = ntoi(tmp, 8);

    // int n = 1345;
    // cout << iton(n, 2) << endl;
    // cout << "0x" + iton(n, 16) << endl;

    // cout << compare<int, int>(1, 2) << endl;
    
    // Foo foo;
    // char *buff = new char[sizeof(foo) * 5];
    // memset(buff, 0, sizeof(foo) * 5);
    // Foo *p = new(buff) Foo;
    // p->~Foo();
    // delete []buff;
     
}