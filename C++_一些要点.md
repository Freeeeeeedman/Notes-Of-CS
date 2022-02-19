[toc]


####一些要点

1. 防卫式声明
2. 是否传入引用,是否返回引用
   - 函数传入引用时，输入的必须是左值
   - 引用作为函数参数可以加const
3. 传入数据是否添加const,函数是否添加const,对象定义加const
   - 成员函数后加const:不改变数据成员
   - 函数参数加const:传入为引用,不修改原数据
   - const对象只能调用const成员函数
   - 函数前加const表示返回的值为const
   - 非常量引用不能指向常量对象
     - 相当于返回类型也加了const所以定义函数也要加const,但是一下例子const没必要，因为没有改变自己的数据成员
      ```
        Point& returnPoint(){return *this;}
        const Point* returnPointp()const {return this;}
      ```
4. 为什么类内析构已经写了delete，还要在实际调用时自己写delete？
   - 直接声明的对象，比如shape a，即在栈上面的对象，所在作用域结束后，会自动执行析构函数，而new出来的在堆上的对象，不调用delete，即使它所在的作用域已经结束，也不会调用析构函数
   - 注意，类里面如果也new了对象，那么类的析构也一定要写对应的delete，如果使用类定对象时也new了，那么就有两个new，都要写delete

5. C与C++结构体的区别
   - C++
    ```
    struct Simple{...}s1;Simple s2,s3;
    typedef struct Simple{...}Simple;Simple s1,s2.s3;
    ```
     - 在C++中，struct和class是完全相同的，除了该struct默认为public可见，class默认为private不可见
   - C
     ```
    struct {...}s1;
    struct Simple {...}s1;struct Simple s2,s3;
    typedef struct {...}Simple;Simple s1,s2,s3;
     ```
   - 区别 
     1. 结构内的成员函数：C中的结构不能在结构内部具有成员函数，但C ++中的结构可以与成员函数一起使用。
     2. 直接初始化：我们不能直接初始化C中的结构数据成员，但我们可以在C ++中实现。
     3. 使用struct关键字： 在C中，我们需要使用struct声明一个struct变量。
     4. 静态成员：结构不能有静态成员，但C++允许使用。
     5. sizeof运算符：该运算符将为C中的空结构生成0，而在C++中为空结构生成1。
     6. 数据隐藏：C结构不允许数据隐藏的概念，但在C ++中允许，因为C++是面向对象的语言，而C不是。
     7. 访问修饰符：C结构没有访问修饰符，因为这些修饰符不被语言支配。C++结构可以具有这个概念，因为它在语言中是内置的。

6. 定义类时可以对数据成员直接赋值吗？
   - 不可以,只有产生类的实例(对象)以后才分配内存空间，此时才能初始化数据成员
   - 哪怕可以也削弱了面向对象的概念，不抽象