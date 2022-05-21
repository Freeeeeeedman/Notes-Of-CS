#### Linux 系统面经总结

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
    netstate
    ss
    route
    ping
    traceroute
    等等...
