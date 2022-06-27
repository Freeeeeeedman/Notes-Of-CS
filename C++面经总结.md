#### C++面经总结
#### 1. C++基础

#### 2. C++标准库
1. 一般数组
   - 定义
        int arr[10];
        int arr[10] = {1, 2, 3, 4, 5};剩下的默认用0填充
        int arr[] = {1, 2, 3, 4, 5};
   - 注意
     - 统计整个数组的长度：sizeof(arr) / sizeof(arr[0])
     - 获取数组首地址：arr 或 &arr[0]
   - 二维数组
        int arr[2][3] = { {1,2,3}, {4,5,6} };
2. 字符串数组
   - 定义
        char c[3];
        char c[3] = {'a','b','c'};剩下的默认用'\0'填充
        char c[] = {'a','b','c'};
        char c[] = {"abc"};
        char c[] = "abc";注意数组长度为4，编译器默认最后加'0'
   - 获取字符串长度 strlen(c);结果为3
3. vector
   - 简介
       #include <vector>
       可变数组，内存空间连续，支持随机访问，不支持在任意位置O(1)插入。 
       在中间进行插入和删除会造成内存块的拷贝，另外，当插入较多的元素后，预留内存空间可能不够，需要重新申请一块足够大的内存并把原来的数据拷贝到新的内存空间。
   - 定义
        vector<int>num;
        vector<int> v(n);//定义一个长度为n的数组，动态定义
        vector<int> v(n，0);//所有的元素均为0
        vector<int> a{1, 2, 3, 4, 5};
        vector<int> b(a);//拷贝初始化, 两个数组中的类型必须相同
        vector<int>num[5];//定义可变长二维数组
        //注意：行是不可变的（只有5行），而列可变可以在指定行添加元素
        //第一维固定长度为5，第二维长度可以改变
        vector<vectot<int>>num;//定义一个行和列均可变的二维数组
        vector<vector<int>> a(n + 1, vector<int>(m + 1, 0));
   - 方法
        c.front()	返回第一个数据
        c.pop_back()	删除最后一个数据 O(1)
        c.push_back(element)	在尾部加一个数据 O(1)
        c.size()	返回实际数据个数（unsigned类型） O(1)
        c.clear()	清除元素个数 O(N),N为元素个数
        c.resize(n) 改变数组大小为n,如果没有默认赋值为0
        c.resize(n,v)	改变数组大小为n,n个空间数值赋为v，如果没有默认赋值为0
        c.insert(it,x)	向任意迭代器it插入一个元素x O(N)
        例：c.insert(c.begin()+2,-1)	将-1插入c[2]的位置
        c.erase(first,last)	删除[first,last)的所有元素
        c.begin()	返回首元素的迭代器（通俗来说就是地址）
        c.end()	返回最后一个元素后一个位置的迭代器（地址）
        c.empty()	判断是否为空，为空返回真，反之返回假
   - 访问
     - 下标访问
        v[i]
     - 迭代器访问
        vector<int>::iterator it;
        for(it = v.begin(); it != v.end(); it++) {
            cout << *it << ' ';
        }
     - 智能指针访问
        for(const auto &a : v) {
            cout << a << ' ';
        }
4. stack
   - 简介
        #include<stack>
        栈，先进后出，后进先出
        栈底，栈顶
   - 方法
        push()	压栈，增加元素 O(1)
        pop()	移除栈顶元素 O(1)
        top()	取得栈顶元素（但不删除）O(1)
        empty()	检测栈内是否为空，空为真 O(1)
        size()	返回stack内元素的个数 O(1)
   - 访问
      - 栈只能对栈顶元素进行操作，如果想要进行遍历，只能将栈中元素一个个取出来存在数组中
      - 可以通过一个数组对栈进行模拟，一个存放下标的变量top模拟指向栈顶的指针
        ```
            vector<int> a(100);
            int top = 0;
            for(int i = 0; i < 5; i++) {
                a[top++] = i;
            }
            int k = 5;
            while(k--) {
                cout << a[--top];
            }
        ```
5. queue
   - 简介
        #include<queue>
        队列，先进先出，后进后出
        只能尾进，头出
   - 方法
        front()	返回队首元素 O(1)
        back()	返回队尾元素 O(1)
        push()	尾部添加一个元素副本 进队O(1)
        pop()	删除第一个元素 出队 O(1)
        size()	返回队列中元素个数，返回值类型unsigned int O(1)
        empty()	判断是否为空，队列为空，返回true O(1)
6. deque
   - 简介
          #include<deque>
          双端队列，首尾都可以插入和删除
   - 方法
          push_back(x)/push_front(x)	把x压入后/前端
          back()/front()	访问(不删除)后/前端元素
          pop_back() pop_front()	删除后/前端元素
          erase(iterator it)	删除双端队列中的某一个元素
          erase(iterator first,iterator last)	删除双端队列中[first,last）中的元素
          empty()	判断deque是否空
          size()	返回deque的元素数量
          clear()	清空deque
   - 排序
          deque可以排序
          sort(d.begin(),d.end())
          //从大到小排序
          sort(q.begin(), q.end(), greater());
7. priority_queue
   - 简介
          #include <queue>
          priority_queue<int> pq;
   - 方法
          top()	访问队首元素
          push()	入队
          pop()	堆顶（队首）元素出队
          size()	队列元素个数
          empty()	是否为空
   - 设置优先级
     - priority_queue<int, vector<int>, less<int> >pq;//最后两个>之间要有空格
     - 第二个参数
          vector< int > 是用来承载底层数据结构堆的容器，若优先队列中存放的是double型数据，就要填vector< double >
     - 第三个参数
          大顶堆：less< int > 表示数字大的优先级大，堆顶为最大的数字
          小顶堆：greater< int >表示数字小的优先级大，堆顶为最小的数字
     - 自定义排序
          大顶堆: < 小于号
          小顶堆: > 大于号
          ```
          struct cmp1
          {
               bool operator()(int x,int y)
               {
                    return x>y;//小的优先级高 ,从小到大排 
               }
          }; 
          struct cmp2
          {
               bool operator()(const int x,const int y)
               {
                    return a[x]>a[y];
               }
          }; 
          priority_queue<int,vector<int>,cmp1>pq1;
          priority_queue<int,vector<int>,cmp2>pq2;
          ```
     - **sort的排序规则和优先队列的排序规则是相反的**

         
















#### 3. C++新特性

#### 4. C++泛型编程