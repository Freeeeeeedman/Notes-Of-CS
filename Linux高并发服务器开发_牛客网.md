
[toc]

### 1. Linux系统编程入门

#### 1.1 Linux开发环境搭建
1. 免登录VSCode
    本地端: ssh-keygen
    服务器端:ssh-keygen -t rsa 
    复制本地端公钥.pub至.ssh/authoirzed_keys

#### 1.2 GCC
1. gcc与g++
- gcc 和 g++都是GNU(编译器套件)的一个编译器
- 使用原则：gcc编译c文件,g++编译c++文件
- 注意
  - 后缀为 .c 的， gcc 把它当作是 C 程序，而 g++ 当作是 c++ 程序
  - 后缀为 .cpp 的，两者都会认为是 C++ 程序
  - 编译可以用gcc/g++，而链接可以用 g++ 或者 gcc -lstdc++
  - gcc 命令不能自动和C++程序使用的库联接，所以通常使用 g++ 来完成联接。但在编译阶段，g++ 会自动调用 gcc，二者等价
1. GCC工作流程
   - 源代码(.h .c .cpp)经预处理器后为预处理后源代码(.i)
   - 再经编译器为汇编代码(.s)
   - 再经编译器为目标代码(.o)
   - 再与启动代码，库代码，其他目标代码经链接器为可执行程序(.exe .out)
2. 静态库制作
   - 命名规则:libxxx.a libxxx.lib
   - 流程
     - 编译，汇编：gcc -c add.c sub.c mult.c div.c -I ../include/
     - 生成静态库： ar rcs libcalcu.a add.o div.o mult.o sub.o
     - 链接：gcc main.c -o app -I ./include/ -l calcu -L ./lib/
3. 动态库制作
   - 命名规则:libxxx.so libxxx.dll
   - 流程
     - 编译，汇编，得到和位置无关的代码:gcc -c -fpic *.c
     - 生成动态库：gcc -shared *.o -o libcalc.so
     - 链接：gcc main.c -o main -I./include/ -L lib/ -l calc   
     - 配置环境变量:
       - 临时：export LD_LIBRARY_PATH=$LD_LIBRARY:/home/ubuntu/lessons/lesson01/library/lib
       - 用户：.bashrc
       - 系统:/etc/profile/,./profile或者/etc/ld.so.config,sudo ldconfig
4. 工作原理
   - 静态库： GCC 进行链接时，会把静态库中代码打包到可执行程序中
   - 动态库： GCC 进行链接时，动态库的代码不会被打包到可执行程序中
   - 程序启动之后，动态库会被动态加载到内存中，通过 ldd （list dynamic dependencies）命令检查动态库依赖关系
   - 如何定位共享库文件
    当系统加载可执行代码时候，能够知道其所依赖的库的名字，但是还需要知道绝对路径。此时就需要系统的动态载入器来获取该绝对路径。对于elf格式的可执行程序，是由ld-linux.so来完成的，它先后搜索elf文件的 DT_RPATH段 ——> 环境变量LD_LIBRARY_PATH ——> /etc/ld.so.cache文件列表 ——> /lib/， /usr/lib目录找到库文件后将其载入内存
5. 对比
    - 静态链接方式，动态链接方式
    - 库非常小使用静态库，库比较大时使用动态库
    - 库的好处： 1.代码保密 2.方便部署和分发
    - 静态库优缺点
      - 优点
        - 静态库被打包到应用程序中加载速度快
        - 发布程序无需提供静态库，移植方便
      - 缺点
        - 多个程序同一静态库重复加载至内存，消耗系统资源，浪费内存
        - 更新、部署、发布麻烦
    - 动态库优缺点
      - 优点
        - 可以实现进程间资源共享（共享库）
        - 更新、部署、发布简单
        - 可以控制何时加载动态库，使用到时加载，没使用到就不加载
      - 缺点
        - 加载速度比静态库慢
        - 发布程序时需要提供依赖的动态库
      - 注意
        - 链接时加载的是动态库的一些信息如名称而不是动态库本身
        - 动态库运行时加载所以在内存中位置不确定，编译汇编时要加-fpic