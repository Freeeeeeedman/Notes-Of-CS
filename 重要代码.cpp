/*
    ��¼һЩ�����лῼ������Ҫ�Ĵ���
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;


//��С��ת��
/*
    int a = 0x1234;
    char c = (char)(a);
    if(c == 0x12)
        cout << "big endian" << endl;
    else if(c == 0x34)
        cout << "little endian" << endl;
*/


//�쳣����
/*
    double m ,n;
    cin >> m >> n;
    try {
        if( n == 0)
            throw -1; //�׳�int�����쳣
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


//�ȽϹ淶�������
class Complex {
    private:
        double real_;
        double imag_;
    
    public:
        Complex(double real, double imag): real_(real), imag_(imag){cout << "�����˹��캯��" << endl;}
        Complex(double real): real_(real), imag_(0){cout << "�����˵��������캯��" << endl;}
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
    cout << "�����˿������캯��" << endl;
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


//������ƶ����캯��
/*
    A a = getA();
    A(A& a): m_ptr(new int(a.m_data)){} //�������캯�����,�Ӷ��з����ڴ棬��h.m_data��ʼ��
    A(A&& a):m_ptr(a.m_ptr){a.m_ptr = nullptr;}

*/


//�Ƚϴ�С�ĺ���ģ��
template <class T, class U>
bool compare(T a, U b) {
    return a > b ? true : false;//��ͬ���͵ıȽ���Ҫ����>
}
//ģ��������
template <>
bool compare(int, int) {
    cout << "ģ��������" << endl;
    return true;
}
//����������
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
        ~Foo() {cout << "������������" << endl;}

};

//�º���
/*
int a = 0, b = 1;
auto f1 = [a, b] {return a + b;}
*/


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
            return *this;
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


//ð������
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

//��������
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

//ϣ������
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

//�鲢����
void merge(int *arr, int n) {
    int temp[n];//nΪ���鳤��
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
        mergeSort(arr, n / 2);//��
        mergeSort(arr + n / 2, n - n / 2);
        merge(arr, n);//��
    }
    
}

//��������
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

//������
void heapify(int *arr, int start, int end) {
    int father = start;
    int son = father * 2 + 1;
    while(son <= end) {
        if(son + 1<= end && arr[son] < arr[son + 1]) {
            son++;
        }
        if(arr[father] > arr[son]) return; //������ڵ�ֵ�����ӽڵ�ֵ����Ϊ���ɵ׵�������ģ�
        else {                             //��ô���ڵ�ʹ��������ӽڵ�
            swap(arr[father], arr[son]);//������Ҫ��ѭ����������
            father = son;
            son = father * 2 + 1;
        }
    }
}

void heapSort(int *arr, int n) {
    for(int i = n / 2 - 1; i >= 0; i--) { //�ɵ׵�����ʼ������
        heapify(arr, i, n - 1);
    }
    for(int i = n - 1; i > 0; i--) {//�ɶ�����ȡ���ֵ
        swap(arr[0], arr[i]);
        heapify(arr, 0, i - 1);
    }
}

//��������
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
        vec[count[tmp[i] - mn]--] = tmp[i];//�Ӻ���ǰ������
                                        //--count����count--�����Զ����ȼ���ȡֵ
                                            //��Ϊcount��¼���Ǳ��Լ�С�����Լ������ֵ���Ŀ  
    }

}

//Ͱ����
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

//��������
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
            tmp[--count[vec[i] / div % 10 - 0]] = vec[i];//�����൱����������СֵΪ0�����Բ���������ֵ
                                                        //���Ҫ��������Ҫ�������������һ��ƫ������ʹ�����鶼Ϊf�Ǹ�������
                                                       //������ɺ��������ȥ���ƫ����
        }
        div *= 10;
        vec = tmp;
    }

}


//LRU�㷨
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
        unordered_map<int, DLinkedNode*> cache;//�����key���ǽڵ��е�keyֵ����valueΪָ��ڵ��ָ��
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
            moveToHead(node);//��ȡ���ƶ���ǰ��
            return node->value;
        }

        void put(int key, int value) {
            if(!cache.count(key)) {
                DLinkedNode *node = new DLinkedNode(key, value);
                cache[key] = node;
                node->prev = head;
                head->next->prev = node;
                node->next = head->next;
                head->next = node;//��ǰ������µĽڵ�
                ++size;               
                if(size > capacity) {
                    DLinkedNode *tmp = removeTail();
                    cache.erase(tmp->key); //�ڸ�������ӻ�ɾ���Լ��޸�valueʱҲҪ��cache���޸�
                    delete tmp;
                    --size;

                }            
            }else {
                DLinkedNode *node = cache[key];
                node->value = value;
                moveToHead(node);//�޸ĺ��ƶ���ǰ��
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
   ���־����ͬ������

   1. ������������������
        ```
        sem mutex = 1;
        sem fullBuffer = n;
        sem emptyBuffer = 0;

        void producer() {
            while(1) {
                P(emptyBuffer);
                P(mutex);
                ��������������
                V(mutex);
                V(fullBuffer);
            }
        }

        void consumer() {
            while(1) {
                P(fullBuffer);
                P(mutex);
                ��������ȡ����
                V(mutex);
                V(emptyBuffer);
            }
        }
        ```

    2. ��ѧ�ҾͲ�����
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
    
    3. ������д��ģ��
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


//n����ת10����
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

//10����תn����
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
    }while(n != 0);//һ��ʼn==0�����ҲҪ����,����Ҫ�ǵü�';'
    reverse(ans.begin(), ans.end());
    return ans;
}


//��ʹ�ö���ռ������£�����������
/*
    - ������:�����ͻ��о�����ʧ
        x = x + y;
        y = x - y;
        x = x - y;
    - ���:�޷�����������
    ��a ^= b; // a=a^b
    ��b ^= a; // b=b^(a^b)=b^a^b=b^b^a=0^a=a
    ��a ^= b; // a=(a^b)^a=a^b^a=a^a^b=0^b=b
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
    // string radix8 = "0144";    //0��ͷ8����
    // string radix16 = "0x541";  //0x��ͷ10����
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