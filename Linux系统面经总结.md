#### Linux基础

1. 关机命令
    sync 将数据由内存同步到硬盘中
    shutdown
2. 系统目录结构
    /bin    系统的一些指令
    /boot   启动Linux时使用的一些核心文件
    /dev    Linux的外部设备
    /etc    系统管理所需要的配置文件
    /home   用户的主目录
    /lib    动态连接共享库
    /media  自动识别的设备的挂载处
    /opt    额外安装软件所摆放的目录
    /proc   虚拟的目录，是系统内存的映射
    /root   超级权限者的用户主目录
    /var    各种日志文件
    /usr    用户的很多应用程序和文件都放在这个目录
    /usr/bin    系统用户使用的应用程序
    /usr/sbin   超级用户使用的比较高级的管理程序和系统守护程序
    /usr/src    内核源代码默认的放置目录
3. 常用目录管理目录
    man
    ls ll
    cd
    pwd -P:确实的路径
    mkdir -m:配置权限，-p递归创建
    rmdir
    cp
    rm -f, -i, -r
    mv
4. 文件属性
    d   目录
    \-  文件
    l   软链接
    b   存储设备
    c   端口设备
    rwx 777
    chgrp， chown， chmod
5. 查看文件
    cat
    tac
    nl
    more
    less
    head
    tail
    grep hello a.txt
6. 硬链接和软链接
   - ln f1 f2
   - ln -s f1 f3
   - 硬链接
        Linux 的文件系统为每一个文件分配一个编号，称为索引节点号(Inode Index)。在 Linux 中，多个文件名指向同一索引节点是可以存在的，即硬链接。硬连接的作用是允许一个文件拥有多个有效路径名，这样用户就可以建立硬连接到重要文件，以防止“误删”的功能。删除其中任何一个都不会影响另外一个的访问，文件真正删除的条件是与之相关的所有硬连接文件均被删除。
   - 软链接
        类似于快捷方式，实际上是一个文本文件，其中包含的有另一文件的位置信息。软链接文件的inode节点和被链接的文件不一样。
7. vim的使用模式
    命令模式，输入模式，底线命令模式等等
8. 账户管理
   - Linux系统是一个多用户多任务的分时操作系统（分时：采用时间片轮转的方式同时为多个用户服务）
   - 账户
    useradd, userdel, usermod
   - 用户组
    groupadd, groupdel, groupmod, newgrp
   - /etc/passwd
    它记录了这个用户的一些基本属性,如主目录，shell类型等
   - /etc/shadow
    存放着加密后的用户密码
   - 伪用户（pseudo users
    要是方便系统管理，，满足相应的系统进程对文件属性的要求。如sys 拥有系统文件。
   - /etc/group
    记录用户组的所有信息
9. 磁盘管理
   - df 
     - 列出文件系统的整体磁盘使用量
     - -h， -i：以 inode 的数量来显示
   - du
     - 文件和目录磁盘使用的空间的查看
     - -a， -sh
   - mount， umount
     - 磁盘挂载与卸载
10. 进程管理
   - ps
     - ps -aux|grep xxx ，查看某个服务的进程 如，ps -aux|grep mysql
     - ps -ef是以全格式显示当前所有的进程，查看父进程
   - kill
   - pstree
     - -p， -u 
11. linux一些常用的网络相关的命令
    netstat：监控TCP/IP网络，它可以显示路由表、实际的网络连接以及每一个网络接口设备的状态信息。
    ifconfig：网卡信息，入网卡名称，ip地址，网络掩码，MTU
    ss：和netstat类似，但内容更详细更快
    route
    ping
    traceroute
    等等...


#### 2. linux面试问题
1. 说一说常用的命令

    一般命令：ls，pwd，cd,ln， touch,cp,mv,rm,tar,find， su,chmod，ldd
    数据处理命令：cat，vim，grep,awk(用于正则匹配来筛选数据，用过一点，后来不用了，用python来做数据处理更方便)
    性能分析命令：
    网络：ifconfig， ip看网络配置，netstat和sar分析网络吞吐量， tcmdump抓包给wireshark分析，还要就是traceroute
    CPU/内存：dmidecode看硬件信息，top/htop/ps看进程占用，vmstat看CPU/内存/IO的分析，还有strace分析进程的调用情况，还有就是free和pmap看内存信息
    IO： fdisk -l 和 df 查看磁盘基本信息，iostat可以看IO的吞吐量和效率，iotop的话可以定位哪个进程IO开销大
    
2. 说一说linux目录结构
    /bin    系统的一些指令
    /boot   启动Linux时使用的一些核心文件
    /dev    Linux的外部设备
    /etc    系统管理所需要的配置文件
    /home   用户的主目录
    /lib    动态连接共享库
    /root   超级权限者的用户主目录
    /var    各种日志文件
    /usr    用户的很多应用程序和文件都放在这个目录
    /usr/bin    系统用户使用的应用程序
    /usr/sbin   超级用户使用的比较高级的管理程序和系统守护程序
    /usr/src    内核源代码默认的放置目录
3. 如何查看Linux端口占用
    lsof -i 端口号
    netstat 结合grep
4. kill -15 和 kill -9 的区别
    kill -9 ：SIGKILL 是强制杀死一个进程,不可以被忽略，不是正常关闭
    kill -15 : SIGTERM 通知应用主动关闭，应用可以忽略该信号，是正常关闭
5. Linux前台进程和后台进程区别
    前台进程：是在终端中运行的命令，那么该终端就为进程的控制终端，一旦这个终端关闭，这个进程也随之消失。
    后台进程：也叫守护进程(Daemon)，是运行在后台的一种特殊进程，不受终端控制，它不需要终端的交互；Linux的大多数服务器就是使用守护进程实现的。比如Web服务器的httpd等。
6. 如何递归地创建目录
    mkdir -p a/b/c
7. 查看CPU的使用效率
    top,htop
8. 说一说scp命令
  主要用来在不同主机之间做数据的安全拷贝
8. 管道命令和xargs有什么区别吗？
  管道是实现“将前面的标准输出作为后面的标准输入”
  xargs是实现“将标准输入作为命令的参数”
  echo "--help"|cat
  echo "--help"|xargs cat
9.  一个文件夹下有多个文件夹，如何删除该目录下的所有txt文件？
    find ./ -name "*.txt" | xargs rm -rf
10. linux查找目录下包含字符串aaa的文件
    find ./ | grep "aaa"
11. 统计一个文件中某个/多个字符串出现次数
    grep -o str filename|wc -l
12. 用过shell脚本吗？
    用过一段时间，后来觉得shell脚本处理数据有些麻烦就用python结合os等系统命令来做脚本
13. linux的用户态和内核态有什么区别？
    通过系统调用将Linux整个体系分为用户态和内核态。内核态就是系统调用执行的地方，比如控制计算机的硬件资源。用户态就是提供应用程序运行的空间。linux提供了为应用程序提供系统调用这样的结构来访问内核管理的资源
14. 用户态到内核态切换有几种方式？
    1. 系统调用，其实系统调用本身就是中断，但是软件中断，跟硬中断不同。
    2. 异常：如果当前进程运行在用户态，如果这个时候发生了异常事件，就会触发切换。例如：缺页异常。
    3. 外设中断：当外设完成用户的请求时，会向CPU发送中断信号
15. 说一说硬链接和软链接的区别
   - 硬链接
        Linux 的文件系统为每一个文件分配一个编号，称为索引节点号(Inode Index)。在 Linux 中，多个文件名指向同一索引节点是可以存在的，即硬链接。硬连接的作用是允许一个文件拥有多个有效路径名，这样用户就可以建立硬连接到重要文件，以防止“误删”的功能。删除其中任何一个都不会影响另外一个的访问，文件真正删除的条件是与之相关的所有硬连接文件均被删除。
   - 软链接
        类似于快捷方式，实际上是一个文本文件，其中包含的有另一文件的位置信息。软链接文件的inode节点和被链接的文件不一样。
16. linux下文件有几种类型？
    7种，ls查看
    d   目录
    \-  文件
    l   软链接
    b   存储设备，硬盘
    c   端口设备，键盘，鼠标
    s   套接字文件
    p   管道文件
17. 说一说linux系统设计
    - 多任务
      多个任务可以并发或者并行同时执行
    - 对称多处理
      每个CPU地位相同，多个CPU共享一个内存，每个CPU都可以访问完整的内存和硬件资源
    - 可执行文件链接格式
      Linux种可执行文件的存储格式，主要包含.bss,.data,.text
    - 宏内核
      Linux内核相当于一个完整的可执行程序，拥有最高的权限
18. 说一说gcc与g++
      gcc 和 g++都是GNU(编译器套件)的一个编译器，gcc编译c文件,g++编译c++文件
19. 说一说Makefile
    - 自动化编译，Makefile 文件定义了一系列的规则来指定哪些文件需要先编译，哪些文件需要后编译，哪些文件需要重新编译。
    - 格式是
      目标 ...: 依赖 ...
          命令（Shell 命令）... 
20. 说一说GDB调试
    - GDB 是由 GNU提供的调试工具，能够设置断点来检查程序中所发生的事
    - 调试选项，编译时加-g， gcc -g -Wall program.c -o program
    - 设置断点：break
    - 调试命令：start，run，continue，print
21. 关于系统IO以及内存管理的在操作系统里复习

#### 3. 网络性能分析
1. 网络性能指标
   - 带宽，表示链路的最⼤传输速率，单位是 b/s （⽐特 / 秒），带宽越⼤，其传输能⼒就越强。
   - 延时，表示请求数据包发送后，收到对端响应，所需要的时间延迟。不同的场景有着不同的含义，⽐如可以表示建⽴ TCP 连接所需的时间延迟，或⼀个数据包往返所需的时间延迟。
   - 吞吐率，表示单位时间内成功传输的数据量，单位是 b/s（⽐特 / 秒）或者 B/s（字节 / 秒），吞吐受带宽限制，带宽越⼤，吞吐率的上限才可能越⾼。
   - PPS，全称是 Packet Per Second（包 / 秒），表示以⽹络包为单位的传输速率，⼀般⽤来评估系统对于⽹络的转发能⼒。
   - ⽹络的可⽤性，表示⽹络能否正常通信；
   - 并发连接数，表示 TCP 连接数量；
   - 丢包率，表示所丢失数据包数量占所发送数据组的⽐率；
   - 重传率，表示重传⽹络包的⽐例；
2. ping
    探测网络的连通性,能获得本次连接的TTL, 往返时间延迟（RTT 时间），丢包情况，以及访问的域名所对应的 IP 地址（使用 DNS 域名解析）
    ping -c 4 www.baidu.com
3. ifconfig
    网络接口的统计信息
    - ⽹⼝的 IP 地址、⼦⽹掩码、 MAC 地址、广播地址
    - ⽹⼝的连接状态标志：RUNNING
    - MTU ⼤⼩。默认值是 1500 字节
    - ⽹路包收发的统计信息
      - TX发送，RX接受
      - errors 表示发⽣错误的数据包数，⽐如校验错误、帧同步错误等；
      - dropped 表示丢弃的数据包数，即数据包已经收到了 Ring Buffer，但因为系统内存不⾜等原因⽽发⽣的丢包；
      - overruns 表示超限数据包数，即⽹络接收/发送速度过快，导致 Ring Buffer 中的数据包来不及处理，⽽导致的丢包，因为过多的数据包挤压在 Ring Buffer，这样 Ring Buffer 很容易就溢出了；
      - carrier 表示发⽣ carrirer 错误的数据包数，⽐如双⼯模式不匹配、物理电缆出现问题等；
      - collisions 表示冲突、碰撞数据包数；
4. netstat， ss(性能更好)
    查看网络整体状况：socket、⽹络协议栈、⽹⼝以及路由表的信息
   - netstat 默认显示连接的套接字数据
        socket 的状态（State）、接收队列（Recv-Q）、发送队列（Send-Q）、本地地址（Local Address）、远端地址（Foreign Address）、进程 PID 和进程名称（PID/Program name）
        - Established ：
            Recv-Q 表示 socket 缓冲区中还没有被应⽤程序读取的字节数；
            Send-Q 表示 socket 缓冲区中还没有被远端主机确认的字节数；
        - Listen:
            Recv-Q 表示全连接队列的⻓度；
            Send-Q 表示全连接队列的最⼤⻓度；
   - netstat -i 显示网络接口信息
        包括网络接口名称（Iface）、MTU，以及一系列接收（RX-）和传输（TX-）的指标。其中 OK 表示传输成功的包，ERR 是错误包，DRP 是丢包，OVR 是超限包。
   - netstat -s 网络协议栈信息
        TCP 协议的主动连接（active connectionsopenings）、被动连接（passive connection openings）、失败重试（failed connection attempts）、发送（segments send out）和接收（segments received）的分段数量
   - netstat -r 显示路由表信息 
5. netcat
        排查网络故障,主要被用来构建网络连接,作为服务端时接受连接，作为客户端时发起连接
         nc -l 0.0.0.0 12345 
         nc -p 1234 127.0.0.1 12345
6. tcmdump
    网络抓包工具,抓包后交给wireshark排查网络错误
    也可以结合netcat使用
7. sar
    历史数据统计工具，包括 CPU、内存、磁盘 I/O、网络、进程、系统调用等等信息。可以用来查看⽹络吞吐率和 PPS 。
       - sar -n DEV 10，显示⽹⼝的统计数据；
            分析网卡接收和发送的网络吞吐量
            xpck/s 和 txpck/s 分别是接收和发送的 PPS，单位为包 / 秒。
            rxkB/s 和 txkB/s 分别是接收和发送的吞吐率，单位是 KB/ 秒。
            rxcmp/s 和 txcmp/s 分别是接收和发送的压缩数据包数，单位是包 / 秒。
       - sar -n EDEV 10，显示关于⽹络错误的统计数据；
            错误包和丢包情况分析，定位问题
            rxerr/s / txerr/s：每秒钟接收/发送的坏数据包
            coll/s：每秒冲突数
            rxdrop/s：因为缓冲充满，每秒钟丢弃的已接收数据包数
            txdrop/s：因为缓冲充满，每秒钟丢弃的已发送数据包数
       - sar -n TCP 10，显示 TCP 的统计数据
            active/s：新的 TCP 主动连接（也就是 socket 中的 connect() 事件），单位是：连接数/s。
            passive/s：新的 TCP 被动连接（也就是 socket 中的 listen() 事件）。
            iseg/s：接收的段（传输层以段为传输单位），单位是：段/s
            oseg/s：发送的段。
       - sar TCP -n IP：IP 数据报统计信息。
       - sar TCP -n EIP：IP 错误统计信息。
       - sar TCP -n ETCP：TCP 错误统计信息。
       - sar TCP -n SOCK：套接字使用。
8. ethtool
     查看带宽，单位为bit而不是byte，千兆网卡，万兆网卡
        ethtool eth0 | grep Speed
        Speed: 1000Mb/s
9. traceroute
    排查网络问题，显示数据包到达目标主机所经过的路径（路由器或网关的 IP 地址）。如果发现网络不通，我们可以通过这个命令来进一步判断是主机的问题还是网关的问题。
    通过发送一系列的探测数据包，同时递增TTL来探测路径。如果中间设备的防火墙拦截响应报文或者超时的话就会显示为*
    traceroute www.baidu.com
10. ip
    新的强大的网络配置工具用来替换ifconfig，netstat
    查看接口:ip link show
    显示接口：ip addr show
    显示路由表: ip route list

#### 4. CPU性能分析
1. lscpu， cat /proc/cpuinfo
    查看CPU信息
2. dmidecode
    查看系统硬件信息，如BIOS、系统、主板、处理器、内存、缓存等等
3. top / htop
    查看进程状态信息
   - load average
        三个数字分别表示最近 1 分钟，5 分钟和 15 分钟的负责，数值越大负载越重。一般要求不超过核数，比如对于单核情况要 < 1。如果机器长期处于高于核数的情况，说明机器 CPU 消耗严重了
   - %Cpu(s)
        表示当前 CPU 的使用情况，如果要查看所有核（逻辑核）的使用情况，可以按下数字 “1” 查看
        - us    用户空间占用 CPU 时间比例
        - sy    系统占用 CPU 时间比例
        - id    CPU 空闲时间比
        - wa    IO等待时间比（IO等待高时，可能是磁盘性能有问题了）
        - hi    硬件中断
        - si    软件中断
   - 每个进程的使用情况
        top -p pid
4. ps
    查看进程状态信息
    watch -n 1 "ps aux"
5. vmstat
    虚拟内存统计，包括CPU, 内存, IO
    - procs：r这一列显示了多少进程在等待cpu，b列显示多少进程正在不可中断的休眠（等待IO）。
    - memory：swapd列显示了多少块被换出了磁盘（页面交换），剩下的列显示了多少块是空闲的（未被使用），多少块正在被用作缓冲区，以及多少正在被用作操作系统的缓存。
    - swap：显示交换活动：每秒有多少块正在被换入（从磁盘）和换出（到磁盘）。
    - io：显示了多少块从块设备读取（bi）和写出（bo）,通常反映了硬盘I/O。
    - system：显示每秒中断(in)和上下文切换（cs）的数量。
    - cpu：显示所有的cpu时间花费在各类操作的百分比，包括执行用户代码（非内核），执行系统代码（内核），空闲以及等待IO。
    
    内存不足的表现：free  memory急剧减少，回收buffer和cacher也无济于事，大量使用交换分区（swpd）,页面交换（swap）频繁，读写磁盘数量（io）增多，缺页中断（in）增多，上下文切换（cs）次数增多，等待IO的进程数（b）增多，大量CPU时间用于等待IO（wa）
6. dstat
    系统监控，pu使用情况，磁盘io情况，网络发包情况和换页
7. pidstat
    进程统计系统信息，包括 CPU、内存和 IO 
    pidstat -u -p pid [times]
8. strace
    分析进程的系统调用情况，可以看进程都调用了哪些库和哪些系统调用
    还可以 attach（附着）到一个正在运行的进程上进行分析
    strace -p pid
    分析问题，从而定位到问题

#### 5. 内存性能分析
0. 查看系统内存用 free -h，分析进程内存占用用 ps 或者 top（首选 ps），深入分析选择 pmap
1. /proc/meminfo
    内存配置信息
   - MemTotal：系统总内存，由于 BIOS、内核等会占用一些内存，所以这里和配置声称的内存会有一些出入，比如我这里配置有 2G，但其实只有 1.95G 可用。
   - MemFree：系统空闲内存。
   - MemAvailable：应用程序可用内存。有人会比较奇怪和 MemFree 的区别，可以从两个层面来区分，MemFree 是系统层面的，而 MemAvailable 是应用程序层面的。系统中有些内存虽然被使用了但是有一部分是可以回收的，比如 Buffers、Cached 及 Slab 这些内存，这部分可以回收的内存加上 MemFree 才是 MemAvailable 的内存值，这是内核通过特定算法算出来的，是一个估算值。
   - Buffers：缓冲区内存
   - Cached：缓存
2. free
   MemTotal = used + free + buff/cache（单位 K)
   free -h
     free 很小，buff/cache 却很大，这是 Linux 的内存设计决定的，Linux 的想法是内存闲着反正也是闲着，不如拿出来做系统缓存和缓冲区，提高数据读写的速率。但是当系统内存不足时，buff/cache 会让出部分来，非常灵活的操作。
3. dmidecode
    dmidecode -t memory
4. top/htop/ps
    查看进程内存使用情况
    top后按F，s确认
    - VIRT：virtual memory usage，进程占用的虚拟内存大小。
    - RES：resident memory usage，进程常驻内存大小，也就是实际内存占用情况，一般我们看进程占用了多少内存，就是看的这个值。
    - SHR：shared memory，共享内存大小，不常用。s
5. pmap
    查看进程的内存映像信息，能够查看进程在哪些地方用了多少内存
    pmap -x pid 
    - Address：占用内存的文件的内存起始地址。
    - Kbytes：占用内存的字节数。    
    - RSS：实际占用内存大小。
    - Dirty：脏页大小。
    - Mapping：占用内存的文件，[anon] 为已分配的内存，[stack] 为程序堆栈
     pmap -x pid | tail -1 

#### 6. IO性能分析
0. fdisk -l 和 df 查看磁盘基本信息，iostat -d 查看磁盘 IOPS 和吞吐量，iostat -x 结合 vmstat 查看磁盘的繁忙程度和处理效率，iotop定位哪个进程IO开销较大
1. 存储可以概括为磁盘，内存，缓存，三者读写的性能差距非常大，磁盘读写是毫秒级的（一般 0.1-10ms），内存读写是微妙级的（一般 0.1-10us），cache 是纳秒级的（一般 1-10ns）。但这也是牺牲其他特性为代价的，速度快的，价格越贵，容量也越小。
2. fdisk
    查看磁盘信息，包括磁盘容量，扇区大小，IO 大小等信息
    fdisk -l
3. df
    查看磁盘使用情况，通常看磁盘使用率
4. vmstat
   - b 值：表示因为 IO 阻塞排队的任务数
   - bi 和 bo 值：表示每秒读写磁盘的块数，bi（block in）是写磁盘，bo（block out）是读磁盘。
   - wa 值：表示因为 IO 等待（wait）而消耗的 CPU 时间比例。
   一般这几个值偏大，都意味着系统 IO 的消耗较大，对于读请求较大的服务器，b、bo、wa 的值偏大，而写请求较大的服务器，b、bi、wa 的值偏大。
5. iostat
    iostat 是专业分析 IO 性能的工具，可以方便查看 CPU、网卡、tty 设备、磁盘、CD-ROM 等等设备的信息
   - iostat -c 查看部分 CPU 使用情况
         %iowait：CPU 等待IO完成的时间的百分比
         %idle：CPU空闲时间百分比
         如果%iowait的值过高，表示硬盘存在I/O瓶颈，%idle值高，表示CPU较空闲，如果%idle值高但系统响应慢时，有可能是CPU等待分配内存，此时应加大内存容量。%idle值如果持续低于10，那么系统的CPU处理能力相对较低，表明系统中最需要解决的资源是CPU
   - iostat -d 查看磁盘使用情况
        tps：设备每秒的传输次数（transfers per second），也就是读写次数。
        kB_read/s 和 kB_wrtn/s：每秒读写磁盘的数据量。
        kB_read 和 kB_wrtn：读取磁盘的数据总量
   - iostat -x 查看磁盘详细信息
        await：平均每次磁盘读写的等待时间（ms）。
        svctm：平均每次磁盘读写的服务时间（ms）。
        %util：一秒钟有百分之多少的时间用于磁盘读写操作。
        %util用于衡量IO的繁忙程度，如果vmstat 的 b 参数（等待 IO 的进程数）和 wa 参数（IO 等待所占 CPU 时间百分比）来看，如果 wa > 30% 也说明 IO 较为繁忙
        await：衡量 IO 的响应速度，图个和svctm差不多说明响应较快
6. 查看每个进程的IO开销
    iotop 定位具体哪个进程的 IO 开销比较大
