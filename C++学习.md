#### C++基础
1. atexit函数
   - 当进程正常退出时，将调用使用atexit注册过的函数
   - 注册过的函数的执行顺序就像压栈一样，先进后出，也就是最先注册的最后执行，最后注册的最先执行
   - 必须是进程正常退出时才会调用atexit注册过的函数，例如进程调用_exit或_Exit退出时就不会调用atexit注册过的函数
2. __attribute__详解
   - attribute是一个编译属性，用于向编译器描述特殊的标识、错误检查或高级优化
   - attribute可以设置函数属性（Function Attribute ）、变量属性（Variable Attribute ）和类型属性（Type Attribute)
   - 例__attribute__ ((attribute-list))
     - format
            使编译器检查函数声明和函数实际调用参数之间的格式化字符串是否匹配
     - constructor与destructor
            constructor属性可以指定函数在main函数执行之前进行调用，与之对应destructor可以指定某个函数在main函数执行结束之后再执行
     - objc_subclassing_restricted
            指明当前类型不能有子类，相当于final关键字
3. 头文件中全局变量，extern，const，static
   - extern 全局变量
      A.h:extern int a;声明
      A.cpp: int a = 1;定义
      B.cpp: include "A.h"包含
      否则直接在头文件定义a，在多处include该头文件，会导致重复定义而无法编译
   - const 常量
      定义在头文件中，在多处include该头文件，对于const全局变量，C++会默认认为其为内部连接，不会导致重复定义
   - static 静态变量
      定义在源文件.cpp中
      如果定义在头文件.h中，不会出现重定义错误，因为在每个编译单元都对它开辟了额外的空间进行存储。每个值互相不影响。
      

#### C++标准库
1. 万用头文件
     #include<bits/stdc++.h>
2. 一般数组
   - 定义
        int arr[10];
        int arr[10] = {1, 2, 3, 4, 5};剩下的默认用0填充
        int arr[] = {1, 2, 3, 4, 5};
   - 注意
     - **统计整个数组的长度**：sizeof(arr) / sizeof(arr[0])
     - 获取数组首地址：arr 或 &arr[0]
   - 二维数组
        int arr[2][3] = { {1,2,3}, {4,5,6} };
3. 字符串数组
   - 定义
        char c[3];
        char c[3] = {'a','b','c'};剩下的默认用'\0'填充
        char c[] = {'a','b','c'};
        char c[] = {"abc"};
        char c[] = "abc";注意数组长度为4，编译器默认最后加'0'
   - 获取字符串长度 strlen(c);结果为3
   - 如果sizeof(c)结果为4，因为包括一个'\0'，4个字符 * 1个字节，大小为4字节
4. vector
   - 简介
       #include <vector>
       可变数组，内存空间连续，支持随机访问，不支持在任意位置O(1)插入。 
       在中间进行插入和删除会造成内存块的拷贝，另外，当插入较多的元素后，预留内存空间可能不够，需要重新申请一块足够大的内存并把原来的数据拷贝到新的内存空间。
   - 定义
        vector<int>num;
        vector<int> v(n);//定义一个长度为n的数组，动态定义
        **vector<int> v(n, 0);**
        vector<int> a{1, 2, 3, 4, 5};
        vector<int> b(a);//拷贝初始化, 两个数组中的类型必须相同
        vector<int>num[5];//定义可变长二维数组
        //注意：行是不可变的（只有5行），而列可变可以在指定行添加元素
        //第一维固定长度为5，第二维长度可以改变
        vector<vectot<int>>num;//定义一个行和列均可变的二维数组
        **vector<vector<int>> a(n + 1, vector<int>(m + 1, 0));**
   - 方法
        **c.front()	返回第一个数据**
        **c.pop_back()	删除最后一个数据 O(1)**
        **c.push_back(element)	在尾部加一个数据 O(1)**
        **c.size()	返回实际数据个数（unsigned类型） O(1)**
        c.clear()	清除元素个数 O(N),N为元素个数
        c.resize(n) 改变数组大小为n,如果没有默认赋值为0
        c.resize(n,v)	改变数组大小为n,n个空间数值赋为v，如果没有默认赋值为0
        **c.insert(it,x)	向任意迭代器it之前插入一个元素x，并返回表示新插入元素位置的迭代器 O(N)**
        例：c.insert(c.begin()+2,-1)	将-1插入c[2]的位置
        c.erase(first,last)	删除[first,last)的所有元素
        **c.erase(pos)删除 vector 容器中 pos 迭代器指定位置处的元素，并返回指向被删除元素下一个位置元素的迭代器。该容器的大小（size）会减 1**
        **c.begin()	返回首元素的迭代器（通俗来说就是地址）**
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
     - **通过迭代器删除元素会导致迭代器失效，那么如何通过迭代器删除特定元素？**
           ``` 
            while( itor != vec.end() )
            {
                  if( *itor == 300 )
                  {
                        itor = vec.erase(itor);//重新获取迭代器，之前的itor指向状态不确定
                  }
                  else
                  {
                        itor++;
                  }
            }
           ```
5. list
   - 简介
       #include <list>
       双向链表
       list<T> lt;
       list<T> lt(n);
       list<T> lt(n, val);
   - 方法
       begin()和end()
       push_back() 和push_front()
       empty()
       resize()
       clear()
       front()和back()
       pop_back和pop_front()
       insert()
       erase()
6. stack
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
      - **可以通过一个数组对栈进行模拟，一个存放下标的变量top模拟指向栈顶的指针**
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
7. queue
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
8. deque
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
9.  priority_queue
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
     - **priority_queue<int, vector<int>, less<int> >pq;//最后两个>之间要有空格**
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
11. map
   - 简介
          #include <map>
          映射,键值对，key-value
          **有序且不重复，map会按照键的顺序从小到大自动排序**
   - 定义
          map<string, string> mp;
          map<string, int> mp;
   - 方法
          **mp.find(key)	返回键为key的映射的迭代器 O(logN) 注意：用find函数来定位数据出现位置，它返回一个迭代器。当数据存在时，返回数据所在位置的迭代器，数据不存在时，返回mp.end()**
          **mp.erase(it)	删除迭代器对应的键和值O(1)**
          **mp.erase(key)	根据映射的键删除键和值 O(logN)**
          mp.erase(first,last)	删除左闭右开区间迭代器对应的键和值 O(last-first)
          mp.size()	返回映射的对数 O(1)
          mp.clear()	清空map中的所有元素 O(N)
          **mp.insert()	插入元素，插入时要构造键值对**
          mp.empty()	如果map为空，返回true，否则返回false
          mp.begin()	返回指向map第一个元素的迭代器（地址）
          mp.end()	返回指向map尾部的迭代器（最后一个元素的下一个地址）
          **mp.lower_bound()	返回一个迭代器，指向键 >= key的第一个元素**
          **mp.upper_bound()	返回一个迭代器，指向键 > key的第一个元素**
   - 注意
     - 赋值方式
          mp["学习"] = "看书";
          **mp.insert(pair<string,string>("fruit","水果"));**
          **mp.insert({"hahaha","wawawa"});**
     - 访问
          下标访问：mp["菜哇菜"] = "强哇强";
          迭代器访问：map<string,string>::iterator it;
                    for(it = mp.begin(); it != mp.end(); it++) {
                         cout << it->first;
                         cout << it->second;
                    }
          智能指针访问：for(auto i : mp)
          指定元素访问:map<char,int>::iterator it = mp.find('a');
                    **cout << it -> first << " " <<  it->second << "\n";**
11. mutimap, unordered_map
12. set
    - 简介
          #include<set>
          set<int> se;
          **有序且不重复，由小到大排序**
    - 方法
          s.begin()	返回set容器的第一个元素的地址（迭代器）
          s.end()	返回set容器的最后一个元素的地址（迭代器）
          **s.rbegin()	返回逆序迭代器，指向容器元素最后一个位置**
          **s.rend()	返回逆序迭代器，指向容器第一个元素前面的位置**
          s.clear()	删除set容器中的所有的元素,返回unsigned int类型O(N)
          s.empty()	判断set容器是否为空
          s.insert()	插入一个元素
          s.size()	返回当前set容器中的元素个数O(1)
          **erase(iterator)	删除定位器iterator指向的值**
          erase(first,second）	删除定位器first和second之间的值
          **erase(key_value)	删除键值key_value的值**
          查找	
          **s.find(元素)	查找set中的某一元素，有则返回该元素对应的迭代器，无则返回结束迭代器**
          **s.lower_bound(k)	返回大于等于k的第一个元素的迭代器**
          **s.upper_bound(k)	返回大于k的第一个元素的迭代器**
    - 访问
        - 迭代器访问
        - 智能指针访问
        - **访问最后一个元素：**
          set<int>::iterator iter = s.end();
          iter--;
          cout<<(*iter)<<endl; 
    - **重载<运算符**
          ```
          struct cmp {
               bool operator () (const int& u, const int& v) const {
                    return u < v;
               }
          };
          set<int, cmp> se;
          ```
13. multiset:元素可以重复，且元素有序
unordered_set ：元素无序且只能出现一次
unordered_multiset ： 元素无序可以出现多次
12. pair
    - 简介
          **#include <utility>**
          pair只含有两个元素，可以看作是只有两个元素的结构体。
    - 作用
          作为map键值对进行插入
    - 定义
          pair<string,int> p("wangyaqi",1);//带初始值的
          pair<string,int> p;//不带初始值的
          p = {"wang",18};//赋值
    - 访问
          pair<int,int>p[20];
          cout << p[i].first << " " << p[i].second;    
13. string
    - 简介
          #include <string>
      字符串,其中每个字符为char类型
    - 定义
          string str1; //生成空字符串
          string str2("123456789"); //生成"1234456789"的复制品 
          string str3("12345", 0, 3);//结果为"123" ，从0位置开始，长度为3
          string str4("123456", 5); //结果为"12345" ，长度为5
          string str5(5, '2'); //结果为"22222" ,构造5个字符'2'连接而成的字符串
          string str6(str2, 2); //结果为"3456789"，截取第三个元素（2对应第三位）到最后
    - 特性
          支持比较运算符，从前往后逐一比较
          支持+运算符，代表拼接字符串
    - **string与C语言字符串（C-string）的区别**
      - string是C++的一个类，专门实现字符串的相关操作。具有丰富的操作方法，数据类型为string，字符串结尾没有\0字符
      - C-string，C语言中的字符串，用char数组实现，类型为const char *,字符串结尾以\0结尾
      - string转char[]
          string s = "xing ma qi";
          **char s2[] = s.c_str();**
    - 方法
          s.size()  返回string对象的字符个数
          **s.push_back()	在末尾插入一个字符**
          **iterator insert(iterator it, char c);//在it处插入字符c，返回插入后迭代器的位置**
          **basic_string& insert (size_type pos, const basic_string& str);在原串下标为pos的字符前插入字符串str**
          **erase(iterator p)	删除字符串中p所指的字符**
          erase(iterator first, iterator last)	删除字符串中迭代器区间[first,last)上所有字符
          **erase(pos, n)	删除字符串中从索引位置pos开始的n个字符**
          clear()	删除字符串中所有字符, 实质是把字符串空间首字符设置为了“\0”
          **s.replace(pos,n,str)	把当前字符串从索引pos开始的n个字符替换为str**
          **s.replace(it1,it2,str)	把当前字符串[it1,it2)区间替换为str**
          **tolower(s[i])	转换为小写**
          **toupper(s[i])	转换为大写**
          **s.substr(pos,n)	截取从pos索引开始的n个字符**
          **s.find (str, pos)	在当前字符串的pos索引位置(默认为0)开始，查找子串str，返回找到的位置索引，-1表示查找不到子串**
          **s.find (c, pos)	在当前字符串的pos索引位置(默认为0)开始，查找字符c，返回找到的位置索引，-1表示查找不到字符**
    - 排序：sort(s.begin(),s.end());  //按ASCII码排序
1.  bitset
    - 简介
          #include <bitset>
          类似数组，并且每一个元素只能是0或1，每个元素只用1bit空间
    - 声明
          bitset < n >a;	a有n位，每位都为0     
          bitset < n >a(s);	a是string对象s中含有的位串的副本
          bitset<4> bitset1;　　  //无参构造，长度为４，默认每一位为0
          bitset<9> bitset2(12);　//长度为9，二进制保存，前面用0补充
          bitset<10> bitset3(string("100101));　　//长度为10，前面用0补充
2.  array
    - 简介
          #include <array>
          array是C++11新增的容器，效率与普通数据相差无几，比vector效率要高，自身添加了一些成员函数。
          和其它容器不同，array 容器的大小是固定的，无法动态的扩展或收缩，**只允许访问或者替换存储的元素**。
          array的使用要在std命名空间里
    - 声明
          array<int, 100> a;元素的值不确定
          array<int, 100> a{};元素的值为0
          **array<int, 100> a{1, 2, 3};**
          array<int, 100> a({1, 2, 3});
          array<int, 100> a = {1, 2, 3};
          array<int, 100> a = {1, 2, 3};
    - 访问
      - 下标访问
      - 智能指针访问
      - 迭代器访问
      - at()成员函数访问
          array<int, 4> a = {1, 2, 3, 4};
          int res = a.at(1) + a.at(2);下标为1+下标为2
    - 方法
          begin()	返回容器中第一个元素的访问迭代器（地址）
          end()	返回容器最后一个元素之后一个位置的访问迭代器（地址）
          rbegin()	返回最后一个元素的访问迭代器（地址）
          rend()	返回第一个元素之前一个位置的访问迭代器（地址）
          size()	返回容器中元素的数量，其值等于初始化 array 类的第二个模板参数N
          empty()	判断容器是否为空
          at(n)	返回容器中 n 位置处元素的引用，函数会自动检查 n 是否在有效的范围内，如果不是则抛出 out_of_range 异常
          front()	返回容器中第一个元素的直接引用，函数不适用于空的 array 容器。引用可以作为左值
          back()	返回容器中最后一个元素的直接引用，函数不适用于空的 array 容器。
          data()	返回一个指向容器首个元素的指针。利用该指针，可实现复制容器中所有元素等类似功能
          fill(x)	将 x 这个值赋值给容器中的每个元素,相当于初始化。
          fill(a.begin(), a.end(), x)
          array1.swap(array2)	交换 array1 和 array2 容器中的所有元素，但前提是它们具有相同的长度和类型
    - 排序
          sort(a.begin(), a.end());   
3.  tuple
    - 简介
          #include <tuple>
          tuple模板是pair的泛化，可以封装不同类型任意数量的对象。
          可以把tuple理解为pair的扩展，tuple可以声明二元组，也可以声明三元组。
          tuple可以等价为结构体使用
    - 声明
          tuple<int, int, string> t1;
          tuple<int, int, int> t1(1, 2, 3, 4);
    - 获取值
          cout << get<0>(t1) << endl;
          int a, b, c, d;
          tie(a, b, c, d) = t1;
          cout << a << b << c << d;
4.  **STL函数**
    beg为序列的初始地址，end为序列的尾地址
    - accumulate(beg,end,init)
        #include <numeric>
        O(n)
        对一个序列的元素求和, 求和不包括end,init为对序列元素求和的初始值
    - fill(beg,end,num)  
        std内
        O(n)
        对一个序列进行初始化赋值
    - is_sorted(beg,end)
        #include <algorithm>  
        O(n)
        判断序列是否有序，返回bool值   
    - lower_bound() upper_bound()
        #include <algorithm>  
        O(logN) 二分查找，注意必须是有序数组或者容器     
          lower_bound(a,a+n,x);//在a数组中查找第一个大于等于x的元素，返回该元素的地址
          c = lower_bound(a.begin(), a.end(), 3) - a.begin();//返回值为3的元素的下标
          upper_bound(a,a+n,x);//在a数组中查找第一个大于x的元素，返回该元素的地址
          //如果未找到，返回尾地址的下一个位置的地址
    - max_element() min_element()
          #include <algorithm>
          O(N), 找序列内的最大最小值
          int mx = *max_element(a,a+n);//函数都是返回地址，需要加\*取值
          int mn = *min_element(a,a+n);
    - max() min()
          O(1)， 找多个元素的最大值和最小值
          mx = max(a,b);//找a，b的最大值和最小值
          mn = min(a,b);
          **mx = max({a,b,c,d});//找到a,b,c,d的最大值和最小值**
          mn = min({a,b,c,d});
    - reverse(beg,end)
          #include <algorithm>
          O(N) 对序列进行翻转
    - sort(beg, end) stable_sort()
          #include <algorithm>
          O(NlogN) 对一个序列进行排序
          stable_sort()功能和sort()基本一样区别在于stable_sort()能够保证相等元素的相对位置，排序时不会改变相等元素的相对位置 
    - to_string()
          #include <string>
          **将数字转化为字符串,支持小数（double）**
    - unique(beg,end)
          #include <algorithm>          
          **要求有序序列**
          **消除重复元素，但不实际删除元素。返回消除完重复元素的部分的末尾的下一位的地址**
          vector<int> a = {1, 2, 3, 3, 4, 4, 5, 6, 7, 7, 9};
          **auto it = unique(a.begin(), a.end());it指向9后面的一位而不是9**
          **a.erase(it, a.end());删除重复元素**

#### C++11 新特性
1. final 关键字
   - 禁止继承：c++11特性中，将类标记为final，意味着无法继承
            class test final
            {
            ......
            };
   - 禁止重写方法：当方法被标记为final时，在子类中无法重写该方法
   - final可以在派生过程中任意地阻止一个接口的可重写性，这就给面向对象带来了更大的控制力