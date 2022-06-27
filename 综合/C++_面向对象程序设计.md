[toc]
#C++面向对象程序设计

####课程简介
1. C++
   - C++由C++语言和C++标准库组成
2. 基于对象与面向对象
   - **培养正规大气的编程习惯**
3. 书籍
   - 百科全书
     - C++ Primer
     - The C++ Prorgramming Language
   - 专家经验
     - Effective C++_Scott Meyers
     - Effective C++_侯捷
   - 标准库
     - THE C++ STANDARD LIBRARY
     - STL源码剖析


####头文件与类的声明
1. C与C++
   - C面向过程,没有关键词,所有数据都是全局的
   - C++面向对象,数据和函数在一起构成对象
2. class
   - 不包含指针:complex
   - 包含指针:string
3. 基于对象与面向对象
   - 面对单一class设计
   - 面对多个class设计及其关系
4. **防卫式声明**
   - 防止同一个头文件被包含多次,重复定义
    ```
     #ifndef __**__
     #define __**__
     #endif
    ```
5. 头文件布局
   - 前置声明
   - 类声明
   - 类定义
6. 类与模板
    ```
    template<typename T>
    class{T value}
    complex<double>..
    ```


####构造函数
1. 内联函数
   - class内定义的函数自动成为inline函数
   - 或者class外加inline定义
2. 访问级别
   - public
   - private
     - **数据一定放在private**
3. 构造函数
   - 创建对象时自动运行的函数(来创建对象)
   - 没有返回值
   - 特别语法:**初始列**,`complex(..):re(r),im(i){}`,不要写在函数内,两个阶段,初始化和赋值,放在赋值效率低
   - 不带指针的函数多半不用写析构函数
   - 重载:多个函数明面上同名,构造函数也可以有很多个,但是有时会发生冲突(当编译器无法区分调用哪个函数时)
   - 构造函数一般不放在private区,但当需要只能创建一个对象的情况时(如singleton)可以这么做


####参数传递与返回值
1. class内函数分为改变数据和不改变数据的
2. **常量成员函数**
   - 使用者创建常量对象时`const complex c1(2,1)`表示其内容不可修改
   - 定义者设计函数时也要规定`double real() const{}`,表示不修改数据
   - 两者要一致,否则报错
3. 参数传递
   - by value
    `double r = 0`
   - by reference(to const)
     - 引用底层相当于指针,像指针那么快
     - 传引用速度快,传值若几百个字节速度慢
     - ** 尽量传引用,除了小于4个字节**
     - 加const防止修改原数据
     - `complex& operator +=(const complex&)`
   - return by value
   - return by reference(to const)
     - `complex& operator+=(const complex&)`
     - 不能返回传回局域变量的引用,函数结束局域变量消失
     - 传递者无需知道接收者是以reference形式接收`inline complex&`
4. 友元
   - C++强调封装
   - 自由取得private成员
   - 相同class的各个objects互为friends


####操作符重载与临时对象
1. 操作符重载(成员函数)
   - 任何成员函数都存在this指针,指向调用者本身的地址`c2 += c1`,这里this指向左值c2,谁调用程序函数,谁就是'this',其通常作为参数时省略
   - 成员函数作用在左边,而非右边,左边作为隐藏参数放入函数定义内
   - +=操作符返回类型不可以是void`c3+=c2+=c1`
   - complex::function...
2. 操作符重载(非成员函数)
   - 全局函数,不存在this
   - 能不能return by reference,看它返回的object是不是个local object(产不产生新空间新数据),是就不能返回索引
   - 编译器通过参数的个数,类型区分重载的函数
3. 临时对象
   - typename()
   - `complex(),complex(4,5)`,生命只存在于当前行
4. 特殊操作符
   - 任何一个函数都可以被设计成成员或非成员函数,取决于具体情况
     - ?如+设计为全局函数,为的是也可以复数+实数
   - ?特殊操作符如'<<'不能作为成员函数而只能为全局函数,否则time对象将为第一个操作符如`trip << cout`,与习惯不符


####三大函数:拷贝构造,拷贝赋值,析构函数(Big Three)
1. 构造函数与析构函数
   - 字符串经典写法
     - 定义一个单独变量记录长度
     - 使用'\0'代表字符串末尾`strlen(cstr)+1`
   - 析构函数
     - 在对象死亡前,离开作用域自动调用
     - 防止内存泄漏(memort leak)delete[] 
2. 拷贝构造与拷贝赋值
   - class带有指针必须有拷贝构造与拷贝赋值
   - 使用系统默认的拷贝只拷贝指针(浅拷贝),导致两个指针指向同一块内存,并导致之前指向的内存产生泄漏
   - 拷贝构造
     - `String s2(s1)`与`String s2=s1`等价
     - 直接取另一个object的private data(互为friend)
   - 拷贝赋值
     - **先检测自我赋值**`if(this == &str)return *this;`
         - 为了效率与正确性
     - 再删除原有数据
     - 最后拷贝数据(深拷贝)


####堆,栈与内存管理
1. stack(栈)
     - 是存在于某种作用域(scope)的一块内存空间(memory space)
     - 调用函数时,函数本身形成一个stack用来防止参数,返回值,返回地址以及local object
     - auto object,离开作用域自动调用析构函数
     - static object,作用域结束后依然存在,直到程序结束时自动调用析构函数`static Complex c2 `
     - global object,程序结束时自动调用析构函数,相当于作用域是全局的static object
2. heap(堆)
     - system heap,指由操作系统提供的一块global内存空间,程序可动态分配(dynamic allocated)从中获得若干区块(block)
     - new:先分配memory，再调用构造函数
      `Complex* pc = new Complex(1,2)`
       - 分配内存:void *mem = operator new (sizeof(Complex)),operator new 内部调用malloc(n)
       - 转型:pc = static_cast<Complex*>(mem);
       - 构造函数:pc->Complex::Complex(1,2)
     - delete:先调用析构函数,再释放内存
       - ?对于Complex类,析构函数没有内容使用系统默认的,因为其离开作用域自动死亡
      `delete ps`
       - 析构函数:String::~String(ps),释放动态分配的内存
       - 释放内存:operator delete(ps),释放ps指针的内存,内部调用free(ps)
     - 动态分配所获得的内存块(in VC,以Complex为例)
       - 调试模式
           - cookie(00000041)4*2byte,记录分配内存长度,1代表分配,0代表释放
           - 调试模式给的内存(Debugger Header)4\*8+4\*1byte
           - 数据4*2
           - 填补内存pad,52+12=16\*4,所以4\*3byte(16倍数则cookie前几位为0)
       - 非调试模式
           - 8+4*2=16byte,不用pad
       - 对于array(in VC)
         `Complex*p = new Complex[3]`
           - 增加一个记录array长度的整数值4*1byte
           - array new 一定要搭配array delete
           - delete[] p,delete p,前者调用三次析构函数,后者调用一次析构函数,这里的内存泄漏是指少释放了4\*2\*2byte数据,而不是所有数据！
           - ?对于Complex的动态分配没有[]也可以,但是规范起见都要写  


####扩展补充:类模板,函数模板,及其他
1. static
   - 静态数据
     - 只有一份,若一个数据与哪个object无关,则使用静态数据
     - 在类里声明
     - 一定要在类外定义(分配内存):`double Account::m_rate=8.0`
   - 静态函数
     - 没有this指针
     - 只能处理静态数据
     - 调用静态函数
       - 无实例时:通过class调用:`Account::set_rate(5.0)`
       - 有实例时:通过object调用:`a.set_rate(5.0)`,实际()内无this参数
     - 函数内static只有当人调用时才创建,函数结束时也存在
   - 非静态有this指针
      `cout<<c1.real()`,实际()内有this参数
      `cout<<complex::real(&c1)`
   - 静态实现Singleton
2. cout
   - cout有很多重载
3. class template类模板
   - `template<typename T>`
   - `complex<double>c1(2.5,1.5)`
   - 模板会造成代码的膨胀,但是是必要的膨胀
4. function template函数模板
   - `template <class T>`
   - `r3=min(r1,r2)`,编译器会对函数模板进行引数推导(argument deduction)
   - 好处在于将程序的负责部分分开,如对“<”重载设计的责任在于设计stone的人
   - C++的标准库都是这种形式
5. namespace
   - 防止同名
   - using directive:`using namespace std`,可以分段写
   - using declaration:`using std::cout;cout<<...`
   - `std::cout<<...`
6. 更多细节与深入
   - ...


####以上为基于对象(单一类)内容,以下为面向对象(多个类)内容


####组合与继承
1. Composition复合
   - has-a,容器容纳
   - Adapter设计模式
   - 创建同步
   - 构造由内而外,container的构造函数首先调用component的default构造函数,再执行自己
      `Container::Container(...):Component(){...};`
   - 析构由外向内,container的析构函数先执行自己,再调用component的析构函数
      `Container::~Container(){...~Component()};`
   - 编译器会自动管理加代码管理顺序,调用默认构造函数,若要指定构造函数,需要加参数
2. Delegation委托
   - composition by reference(学术界即使用指针传也是..),拥有指针
   - Handle/body(point to implementation)
   - 创建不同步
   - 编译防火墙,不用在意指针指向的对象的实现
   - 共享内容,copy on right
3. Inheritance继承
   - is-a
   - 三种继承,`:public _List_node_base`
   - 外部为派生类,内部为父类,构造由内而外,析构由外而内
   - base class的析构函数必须是virtual,否则会出现undefined behavior
   - 函数继承的是调用权而非内存,通过子类对象调用父类函数
4. 继承+复合关系下的构造与析构
   - 子类有复合
     - 构造由内而外:Base先,再Component,最后自己
     - 析构由外而内:..
     - 实际顺序也许取决于编译器,不影响实际实现
   - 父类有复合


####虚函数与多态
1. 虚函数
   - non-virtual函数:不希望derived class重新定义(override覆写)
   - virtual函数：希望derived class重新定义,它已有默认定义(注意无动作空函数写法)
   - pure virtual函数:希望derived class一定要重新定义,它没有默认定义(实际可以有)
   - 继承搭配虚函数,template method,一般性动作写在framework框架,关键动作延缓到子类函数设计

####委托相关设计模式
1. 同一文件多窗口:Observer
2. filesystem:Composite
3. ?**创建未来的class:Prototype**(DeSign Patterns Explained Simply)


#C++程序设计兼谈对象模型
1. 简介
   - 泛型编程(Generic Programming)
   - 整个标准库都是用模板做出来的,是用模板思维而非面向对象的思维(旧标准库)
2. coversion function转换函数
   ```
   operator double() const {
      return (double)(a/b)
   }
   ```
   - 转换可以是任何type,只要其先前定义过
3. non-explicit-one-argument-constructor-function
   ```
   Fraction(int num,int den=1)
      :a(num),b(den){}
   ```
   - 可以把别的对象转换为这种对象`Fraction d2=f+4`
   - 若两者转换都存在编译器会报错
   - explict Fraction(..)禁止编译器自动转换,基本上用在构造函数前
4. pointer-like classes
   - 智能指针
     - 智能指针一定带有实际的指针
      ```
      class shared_ptr
       {
         public:
            T& operator*()const
            {return *px}
            T* operator->()const
            {return px}
            shared_ptr(T* p):px(p){}
         private:
            T* px;
         }
      ```
     - "->"操作符有特殊特性是作用后会保留继续作用
   - 迭代器
     - 仍然是智能指针,但需要迭代来遍历容器
      ```
      T& operator*()const
      {return (*node).data;}
      T* operator—>()const
      {return &(operator*());}
      ```
5. function-like classes,仿函数
   - 能接受()操作符的东西称为"像函数"
   - class内有重载"()",并且继承一些奇特的base classes
     - unary_function
     - binary_function
     - 做什么用?C++标准库课程
6. namespace 经验谈
   ```
   namespace jj01
   {

   }
   namespace jj02
   {

   }
   int main(..)
   {
      jj01::test_..();
      jj02::test_..();
   }
   ```
7. class template,类模板
   - 针对类抽出任意指定的类型
   - 泛型编程,模板
8. function template,函数模板
   - 针对函数抽出任意指定的类型
   - 函数模板可以编译一次,调用时替换模板时还要再编译一次而不一定能成功
9. member template,成员模板
   - 类模板里的成员模板
   - 用于构造函数继承赋初值
   `pair<Base1,Base2>p2(pair<Derived1,Derived2>());`\
   - 用于智能指针模拟up-cast
   `shared_ptr<Base1>sptr(new Derived)`
10. specialization,模板特化
    - 泛化就是模板,用的时候指定类型
    - 特化:面对独特类型做特殊设计,设计模板后锁定特征化
11. partial specialization,模板偏特化
    - 个数上的偏`class vector<bool,Alloc>`
    - 范围上的偏`class C<U*>`
12. template template parameter,模板模板参数
    - 只有在template<>内typename和class共通,历史因素导致
    - `template<typename T,template<typename T> class Container>`
    - 接受多个模板参数时会有问题(C++2.0内容)
    - 这不是模板模板参数`stack<int,list<int>>s2;`
13. 关于C++标准库
    - 容器Containers(数据结构):链表,数组...
    - 算法Algorithms:排序,拷贝...
    - 仿函数Functors
    - 迭代器Iterators
    - **用小程序把标准库全部测一遍,这样需要的时候就不需要自己写代码**
14. 三个主题
    - variadic templates数量不定的模板参数(since C++11)
      ```
      template<typename T,typename... Types>
      void print(const T& firstArg,const Types&...args)
      {}
      ```
        - pack(包)
        - sizeof...(args)
    - auto(since C++11)(语法糖)
        - 定义时必须要赋值
    - ranged-base for(since C++11)(语法糖)
      `for (decl:coll) {}`
        - 过去要用容器的迭代器或者for each取
      ```
      vector<double> vec;
      ···
      for(auto elem:vec){} #pass by value 不改变原数据
      for(auto& elem:vec){} #pass by reference 改变原数据
      ```
15. reference
    - 从内存角度看变量
        - 普通变量
        - 指针:指针和地址互为一种形式
          - `int* p=&x`,point to x,指向
          - 大小取决于是32位(4byte)还是64位
        - 引用
          - `int& r=x`,reference to x,r**代表**x,类型为代表的对象的类型
          - r不能重新代表其他物体,`r=x2`,意义是将r,x值设为x2的值
          - 编译器实现引用都是用指针实现,制造一种假象sizeof(x)==sizeof(x),&x==&r,实际不是
    - reference的常见实现
        - 参数传递
          - 被调用端写法相同
          - 调用端接口相同
          - 通常不用于声明对象,而用于参数类型和返回类型的描述
        - same signature
          - 不能并存,签名相同
          -  const是函数签名的一部分,函数`func()const{}`有无const可以并存
16. 对象模型:关于vptr和vtbl
    - 只要内存里带有虚函数(无论数目多少),内存多4byte
    - 父类有虚函数,子类一定有,继承调用权
    - 子类函数与父类同门但并不是同一个函数,这样设计不好
    - 静态绑定,一定call到一段地址
    - **虚指针**
        - 有虚函数必定有虚指针,大小为4type
        - 指向虚表,其放的都是函数指针
        - 通过虚指针调用适当的虚函数,C语言风格没有虚函数就需要增加判断代码,如果需要增加判断的类型就需要重写函数
        - 动态绑定,要看p指向什么再调用什么
          - 通过指针调用
          - 指针向上转型up-cast
          - 调用的是虚函数
        - 虚机制:(*(p->vptr)[n])(p)或(\* p->vptr[n])(p)
        - 多态 
          - 同一指针有多种类型
          - list<A*>myLst,A*必须指向父类,这样可以指向各式各样的子类,再遍历调用各子类的虚函数
17. 对象模型:关于this
    - 通过对象调用函数,这个对象的地址就是this
    - 虚函数两种用处:Template Method和多态
    - Dynamic Binding:`this->Serialize();(*(this->vptr)[n])(this);`
18. 对象模型:关于Dynamic Binding\
    - static binding：通过对象调用a.vfunc1(),call xxx
    - 三个动作
      ```
      A* pa = new B;
      pa->vfunc1();
      ```
19. const
    - 成员函数后放const
        - 全局函数不行
        - 不能更改数据成员
        - 设计函数就可以判断要不要加const
    - 对象前加const
        - 数据成员不能更改
        - 常量对象不能调用非常量成员函数
    - const是签名的一部分
        - 共享数据时,有人要更改数据怎么办:Copy On Write(COW)
          - 常量字符串不用考虑COW,重载分开写,加const,效率高
        - 当成员函数的const和non-const版本同时存在时,const object只会(只能)调用const版本,non-const object只会(只能)调用non-const版本
20. new,delete(expression new,operator new,array new,placement new)
    - 直接使用的是expression(表达式)new,表达式不能重载
    - 表达式new分解的operator new可以重载
    - 重载
        - 重载的为分解后的第一个动作operator new
        - 全局重载,影响非常深远(多个不可以被声明于同一个namespace内 )
        - 成员函数重载,接管使用者的行为
        - 重载作为内存池的设计
        - 使用者刻意绕过重载,强制采用globals
         ```
         Foo *pf=::new Foo;
         ::delete pf;
         ```
        - array new,delete时,整个数组在内存内需要再增加一个整数值(4byte)记录数组大小,编译器才了解调用几次构造和几次析构
    - placement new重载
      `Foo* pf=new(300,'c')Foo;`
        - 用()表现存在额外的参数,第一参数必须是size_t,上例共存在3个参数
    - placement delete重载(placement operator delete)
        - 只有当new所调用的ctor抛出exception时,才会调用这些重载版的operator delete(),来释放对应的new分配的内存
        - 即使operator delete(...)未能一一对应operator new(...),也不会出现任何报错,会放弃处理ctor发出的异常
    - basic_string使用new(extra)扩充申请量
        - 做reference counting记录共享数
        - 借鉴这个例子,当你需要不知觉地分配一些内存记录数据重载placement new 