/*
    ��¼һЩ�����лῼ������Ҫ�Ĵ���
*/

#include <iostream>
#include <bits/stdc++.h>
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











int main() {
    vector<int> vec{0, 2, 5, 6, 1, 7, 9, 4, 3, 8};
    int arr[] = {0, 2, 5, 6, 1, 7, 9, 4, 3, 8};
    int n = sizeof(arr) / sizeof(arr[0]);
    // bubbleSort(vec);
    // selectionSort(vec);
    // insertSort(vec);
    // shellSort(vec);
    // mergeSort(arr, n);
    // quickSort(vec, 0, vec.size() - 1);
    // heapSort(arr, n);
    // countSort(vec);
    // bucketSort(vec);
    radixSort(vec);
    for(auto &i : vec) {
        cout << i << ' ';
    }
    // for(int i = 0; i < 10; i++) {
    //     cout << arr[i] << ' ';
    // }



}