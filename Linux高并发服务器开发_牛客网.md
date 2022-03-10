
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
  - ldd命令查看所链接的库
1. GCC工作流程
   - 源代码(.h .c .cpp)经预处理器后为预处理后源代码(.i)
   - 再经编译器为汇编代码(.s)
   - 再经汇编器为目标代码(.o)
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

#### 1.3 Makefile
1. 作用
    自动化编译，Makefile 文件定义了一系列的规则来指定哪些文件需要先编译，哪些文件需要后编译，哪些文件需要重新编译。像一个 Shell 脚本一样，也可以执行操作系统的命令
2. 文件命名
    makefile 或者 Makefile
3. Makefile 规则
    一个 Makefile 文件中可以有一个或者多个规则
    目标 ...: 依赖 ...
        命令（Shell 命令）...      
   - 目标：最终要生成的文件（伪目标除外）
   - 依赖：生成目标所需要的文件或是目标
   - 命令：通过执行命令对依赖操作生成目标（命令前必须 Tab 缩进
4. 执行规则
   - 先只执行第一条命令，后面的命令如果不生成第一条命令的依赖不执行,需要指定执行
   - 命令在执行之前，需要先检查规则中的依赖是否存在，存在执行，不存在向下查找再执行
   - 检测更新，在执行规则中的命令时，会比较目标和依赖文件的时间
   - 各自编译为.o文件再链接比直接编译汇编链接.c文件效率高，因为可以避免重复操作
   - 指定执行目标，make clean
5. 变量规则
   - 自定义变量
      变量名=变量值 var=hello
   - 预定义变量
     - AR : 归档维护程序的名称，默认值为 ar
     - CC : C 编译器的名称，默认值为 cc
     - CXX : C++ 编译器的名称，默认值为 g++
     - $@ : 目标的完整名称
     - $< : 第一个依赖文件的名称
     - $^ : 所有的依赖文件
     - 获取变量的值：$(变量名)
   - 自动变量只能在规则的命令中使用
      ```
      app:main.c a.c b.c
        $(CC) -c $^ -o $@
      ```
   - %.o:%.c
      - %: 通配符，匹配一个字符串
      - 两个%匹配的是同一个字符串
   - 伪目标，防止与文件命名冲突
      ```
      .PHONY:clean
      clean:
        ...
      ```
6. 函数
   - $(wildcard PATTERN...)
     - $(wildcard *.c ./sub/*.c)
   - $(patsubst <pattern>,<replacement>,<text>)
     - $(patsubst %.c, %.o, x.c bar.c)

#### 1.4 GDB调试
1. 简介
    GDB 是由 GNU 软件系统社区提供的调试工具，同 GCC 配套组成了一套完整的开发环境， GDB 是 Linux 和许多类 Unix 系统中的标准开发环境
2. 功能
   1. 启动程序，可以按照自定义的要求随心所欲的运行程序
   2. 可让被调试的程序在所指定的调置的断点处停住（断点可以是条件表达式）
   3. 当程序被停住时，可以检查此时程序中所发生的事
   4. 可以改变程序，将一个 BUG 产生的影响修正从而测试其他 BUG
3. 准备
    gcc -g -Wall program.c -o program //关闭优化选项-O
    `-g` 选项的作用是在可执行文件中加入源代码的信息,并不是把源代码嵌入其中，所以调试时必须保证 gdb 能找到源文件
4. 命令
   - 基础命令
     - 启动和退出
      gdb 可执行程序
      quit
     - 给程序设置参数/获取设置参数
      set args 10 20
      show args
     - GDB 使用帮助
      help
     - 查看当前文件代码
      list/l （从默认位置显示）
      list/l 行号 （从指定的行显示）
      list/l 函数名（从指定的函数显示）
     - 查看非当前文件代码（不能直接指定文件）
      list/l 文件名:行号
      list/l 文件名:函数名
     - 设置显示的行数
      show list/listsize
      set list/listsize 行数
   - 断点命令
     - 设置断点
      b/break 行号
      b/break 函数名
      b/break 文件名:行号
      b/break 文件名:函数
     - 查看断点
      i/info b/break
     - 删除断点
      d/del/delete 断点编号
     - 设置断点无效
      dis/disable 断点编号
     - 设置断点生效
      ena/enable 断点编号
     - 设置条件断点（一般用在循环的位置）
      b/break 10 if i==5
   - 调试命令
     - 运行GDB程序
      start（程序停在第一行）
      run（遇到断点才停）
     - 继续运行，到下一个断点停
      c/continue
     - 向下执行一行代码（不会进入函数体）
      n/next
     - 变量操作
      p/print 变量名（打印变量值）
      ptype 变量名（打印变量类型）
     - 向下单步调试（遇到函数进入函数体）
      s/step
      finish（跳出函数体）
     - 自动变量操作
      display 变量名（自动打印指定变量的值）
      i/info display
      undisplay 编号
     - 其它操作
      set var 变量名=变量值 （循环中用的较多）
      until （跳出循环）

#### 1.5 文件IO
1. 站在内存角度考虑IO，输入为文件到内存，输出为内存到文件
2. 跨平台
  Java通过虚拟跨平台，实际代码运行都在虚拟机内
  C通过调用不同平台的API跨平台
3. 返回值File *fp
   结构体
   - 文件描述符(整型值)：索引到对应的磁盘文件
   - 文件读写指针位置：读写文件过程中指针的实际位置，用于操作读数据和写数据
   - I/O缓冲区（内存地址）：通过寻址找到对应的内存，数据从内存刷新到磁盘     
4. I/O缓冲区
    C库函数先写入缓冲区，再调用LinuxI/O函数写入磁盘
  - 作用 
    提高效率，降低写磁盘的次数（本质是通过内核）
  - 写入磁盘的时机
    1. 刷新缓冲区： fflush
    2. 缓冲区已满
    3. 正常关闭文件
        a.fclose
        b.return(main函数)
        c.exit(main函数)
4. 标准 C 库 IO 和 Linux 系统 IO 的关系
   - 调用和被调用的关系
      用户程序调用C标准I/O库，C标准I/O库写入缓冲区，缓冲区满时调用linux系统I/O，写入磁盘
   - 标准C库函数为高级语言，linux平台I/O函数更低级
   - 磁盘读写时选用标准C库函数，网络通信提高效率使用LinuxI/O函数

#### 1.6 虚拟地址空间 
1. 程序和进程
    程序：磁盘上的代码
    进程：加载到内存中的运行中的程序
2. 32位：2^32 ~ 4G
   64位: 2^48
3. 内核区1G
   - 内存管理
   - 进程管理
   - 设备驱动管理
   - VFS虚拟文件系统
4. 用户区3G
  - 环境变量
  - 命令行参数
  - 栈空间(小)：由高到低存
  - 共享库
  - 堆空间(大)：由低到高存
  - ELF
    未初始化全局变量
    初始化全局变量
    代码段，二进制机器命令
  - 受保护的地址

#### 1.6 文件描述符
1. 文件描述符在内核区，由PCB进程控制块管理
2. 文件描述符表
   - 使用数组存取，为了一个进程可以同时打开多个文件
   - 默认大小为1024，即最大同时可打开文件数目为1024
   - 默认前三为标准输入0，标准输出1，标准错误2，默认为打开状态，与当前终端/dev/tty设备文件绑定
   - 一个文件可以被打开多次，即多个文件描述符可以指定同一文件
   - 每打开一个文件，则占用一个空闲的最小的文件描述符

#### 1.7 Linux I/O函数
1. man 2 open:linux系统I/O函数
   man 3 fopen:标准C库函数
2. open()
   - int open(const char *pathname, int flags);
     - pathname:要打开的文件路径
     - flags：对文件的操作权限设置还要其他设置，互斥
     - 返回值：返回一个新的文件描述符，如果调用失败，返回-1
     - errno：属于linux系统函数库，是其中的一个全局变量，记录的是最近的错误号
   - void perror(const char *s);作用：打印errno对应的错误描述
      s参数：用户描述，比如hello,最终输出的内容是  hello:xxx(实际的错误描述)
   - int open(const char *pathname, int flags, mode_t mode);
     - 不是函数重载，C是用可变参数实现
     - flags：对文件的操作权限和其他的设置
       - 必选项：O_RDONLY,  O_WRONLY, O_RDWR  这三个之间是互斥的
       - 可选项：O_CREAT 文件不存在，创建新文件
         - 使用按位或设置可选项
         - flags参数是一个int类型的数据，占4个字节，32位
         - flags 32个位，每一位就是一个标志位
       - mode
         - 八进制的数，表示创建出的新的文件的操作权限，比如：0775
         - 最终的权限是：mode & ~umask
         - 按位与：0和任何数都为0,umask的作用就是抹去某些权限
            0777   ->   111111111
        &   0775   ->   111111101

                        111111101
3. read()
   - ssize_t read(int fd, void *buf, size_t count);
     - 参数：
       - fd：文件描述符，open得到的，通过这个文件描述符操作某个文件
       - buf：需要读取数据存放的地方，数组的地址（传出参数）
       - count：指定的数组的大小
     - 返回值：
        - 成功：
           \>0: 返回实际的读取到的字节数
           =0：文件已经读取完了
        - 失败：-1 ，并且设置errno        
4. write()
    - ssize_t write(int fd, const void *buf, size_t count);
       - 参数：
            - fd：文件描述符，open得到的，通过这个文件描述符操作某个文件
            - buf：要往磁盘写入的数据，数据
            - count：要写的数据的实际的大小
       - 返回值：
            成功：实际写入的字节数
            失败：返回-1，并设置errno
5. lseek()
   - off_t lseek(int fd, off_t offset, int whence);
      -  参数：
            - fd：文件描述符，通过open得到的，通过这个fd操作某个文件
            - offset：偏移量
            - whence:
                SEEK_SET
                    设置文件指针的偏移量
                SEEK_CUR
                    设置偏移量：当前位置 + 第二个参数offset的值
                SEEK_END
                    设置偏移量：文件大小 + 第二个参数offset的值
      -  返回值：返回文件指针的位置
     -   作用：
        1. 移动文件指针到文件头,避免再次打开文件
        lseek(fd, 0, SEEK_SET);
        2. 获取当前文件指针的位置
        lseek(fd, 0, SEEK_CUR);
        3. 获取文件长度
        lseek(fd, 0, SEEK_END);
        4. 拓展文件的长度，当前文件10b, 110b, 增加了100个字节
        lseek(fd, 100, SEEK_END)
        注意：需要写一次数据， write(fd, " ", 1);
        用途：先占据一部分空间
6. stat()
   - stat test.txt
   - int stat(const char *pathname, struct stat *statbuf);
      - 作用：获取一个文件相关的一些信息
      - 参数:
            - pathname：操作的文件的路径
            - statbuf：结构体变量，传出参数，用于保存获取到的文件的信息
      - 返回值：
            成功：返回0
            失败：返回-1 设置errno
   - int lstat(const char *pathname, struct stat *statbuf);
      - 作用：获取软链接而非其指向的文件的信息
   -  ```
      struct stat {
          dev_t st_dev; // 文件的设备编号
          ino_t st_ino; // 节点
          mode_t st_mode; // 文件的类型和存取的权限
          nlink_t st_nlink; // 连到该文件的硬连接数目
          uid_t st_uid; // 用户ID
          gid_t st_gid; // 组ID
          dev_t st_rdev; // 设备文件的设备编号
          off_t st_size; // 文件字节数(文件大小)
          blksize_t st_blksize; // 块大小
          blkcnt_t st_blocks; // 块数
          time_t st_atime; // 最后一次访问时间
          time_t st_mtime; // 最后一次修改时间
          time_t st_ctime; // 最后一次改变时间(指属性)
      };
      ```
   - st_mode变量
     - 4位文件类型+3位特殊权限位+3位User权限位+3位Group权限位+3位Others权限位
     - linux共七种文件
         - S_IFSOCK 0140000 套接字
         - S_IFLNK 0120000 符号链接（软链接）
         - S_IFREG 0100000 普通文件
         - S_IFBLK 0060000 块设备
         - S_IFDIR 0040000 目录
         - S_IFCHR 0020000 字符设备
         - S_IFIFO 0010000 管道
         - S_IFMT 0170000 掩码
     - (st_mode & S_IFMT) == S_IFREG，通过与宏&运算，再与对应文件类型宏进行比较得出其文件类型
     - others文件权限也是通过与宏00007&运算得出，等待
 
