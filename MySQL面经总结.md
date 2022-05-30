#### 1. 基础操作
1. 数据库
        SHOW DATABASES;
        CREATE DATABASE 数据库名;
        USE 数据库名称;
        DROP DATABASE 数据库名;
2. 表
        SHOW TABLES;
        CREATE TABLE 表名 (
            列名1    数据类型    [列的属性],
            列名2    数据类型    [列的属性],
            ...
            列名n    数据类型    [列的属性]
        )COMMENT '表的注释信息';
        DROP TABLE 表1, 表2, ..., 表n;
        DESC 表名;
        SHOW CREATE TABLE 表名;
        SHOW TABLES FROM xiaohaizi;
        SHOW CREATE TABLE xiaohaizi.first_table\G
        ALTER TABLE 旧表名 RENAME TO 新表名;
        RENAME TABLE 旧表名1 TO 新表名1, 旧表名2 TO 新表名2, ... 旧表名n TO 新表名n;
        ALTER TABLE 表名 ADD COLUMN 列名 数据类型 [列的属性];
        ALTER TABLE 表名 ADD COLUMN 列名 列的类型 [列的属性] FIRST;
        ALTER TABLE 表名 ADD COLUMN 列名 列的类型 [列的属性] AFTER 指定列名;
        ALTER TABLE 表名 DROP COLUMN 列名;
        ALTER TABLE 表名 MODIFY 列名 新数据类型 [新属性];
        ALTER TABLE 表名 CHANGE 旧列名 新列名 新数据类型 [新属性];
        ALTER TABLE 表名 MODIFY 列名 列的类型 列的属性 FIRST;
        ALTER TABLE 表名 MODIFY 列名 列的类型 列的属性 AFTER 指定列名;
        ALTER TABLE 表名 操作1, 操作2, ..., 操作n;
3. 列
   - SELECT * FROM 表名;
   - INSERT INTO 表名(列1, 列2, ...) VALUES(列1的值，列2的值, ...), (列1的值，列2的值, ...), (列1的值，列2的值, ...), ...;
   - 列的属性
       - 默认值
            列名 列的类型 DEFAULT 默认值
       - 非空
            列名 列的类型 NOT NULL
       - PRIMART主键
            PRIMARY KEY (列名1, 列名2, ...)
       - UNIQUE唯一键（约束）
            UNIQUE KEY [约束名称] (列名1, 列名2, ...)
       - 外键（约束）
            CONSTRAINT [外键名称] FOREIGN KEY(列1, 列2, ...) REFERENCES 父表名(父列1, 父列2, ...);
       - 自增
            列名 列的类型 AUTO_INCREMENT
       - 影响展示外观的ZEROFILL属性
            i1 INT(10) UNSIGNED ZEROFILL
   - 一个列同时具有多个属性,空白隔开
   - MODIFY，CHANGE设置属性时，相当于新增属性，重复的不需要再写
   - 删除属性
       - 非空
         NULL
       - 唯一键，唯一键也是索引
         SHOW CREATE TABLE t1;
         ALTER TABLE t1 DROP INDEX col;
4. 简单查询
   - 查询列
        SELECT 列名1, 列名2, ... 列名n FROM 表名;
        SELECT * FROM 表名;
        SELECT 列名 [AS] 列的别名 FROM 表名;
   - 去除重复值
        SELECT DISTINCT 列名 FROM 表名;
        注意默认编码字符串不区分大小写
   - 限制查询结果条数
        SELECT number, name, id_number, major FROM student_info LIMIT 0, 2;
   - 排序
        ASC顺序，DESC倒序
        SELECT * FROM student_score ORDER BY score ASC;
        ORDER BY 列1 ASC|DESC, 列2 ASC|DESC ...
5. 带搜索条件的查询
   - SELECT * FROM student_info WHERE name = '范剑';
        =, !=, >, <, >=, <=, BETWEEN, NOT BEYWEEM 
   - 匹配列表中元素
        SELECT *  FROM student_info WHERE major IN ('软件工程', '飞行器设计');
   - 匹配NULL值
        IS NULL, IS NOT NULL，注意必须要用这样的方式判断，唯一的！
   - 多个搜索条件的查询
        AND, OR, XOR
        AND操作符的优先级高于OR操作符,所以在一个查询中有多个搜索条件时最好使用小括号()来显式的指定各个搜索条件的检测顺序
         SELECT * FROM student_score WHERE (score > 95 OR score < 55) AND subject = '论萨达姆的战争准备';
   - 通配符
        LIKE, NOT LIKE, %, _
6. 函数
   - 文本处理函数
        SELECT SUBSTRING('abc123', 2, 3);
        SELECT CONCAT('学号为', number, '的学生在《', subject, '》课程的成绩是：',score) AS 成绩描述 FROM student_score;
   - 日期和时间处理函数
   - 聚集函数
         SELECT COUNT(*) FROM student_info;
         SELECT MAX(score) FROM student_score;
         SELECT SUM(score) FROM student_score;
         SELECT AVG(score) FROM student_score;
         SELECT COUNT(DISTINCT major) FROM student_info;
         SELECT COUNT(*) AS 成绩记录总数, MAX(score) AS 最高成绩, MIN(score) AS 最低成绩, AVG(score) AS 平均成绩 FROM student_score;
   - 隐式类型转换
        - 根据上下文转换，如数字与字符串的转换
        - MySQL会尽量把值转换为表达式中需要的类型，而不是产生错误
        - 在运算时会自动提升操作数的类型
7. 分组查询
   - 创建分组
        SELECT subject, AVG(score) FROM student_score GROUP BY subject;
        注意不能将非分组列放到查询列表中，只能放入分组列和聚合函数
   - 带有WHERE子句的分组查询
         SELECT subject, AVG(score) FROM student_score WHERE score >= 60 GROUP BY subject;
   - 作用于分组的过滤条件
        SELECT subject, AVG(score) FROM student_score GROUP BY subject HAVING AVG(score) > 73;
        注意这里针对分组的条件是指分组列或作用于分组的聚集函数
   - 分组和排序
        SELECT subject, AVG(score) AS avg_score FROM student_score GROUP BY subject ORDER BY avg_score DESC;
   - 嵌套分组
         SELECT department, major, COUNT(*) FROM student_info GROUP BY department, major;
   - 注意
        - 如果分组列中含有NULL值，那么NULL也会作为一个独立的分组存在
        - 如果存在多个分组列，也就是嵌套分组，聚集函数将作用在最后的那个分组列上
        - 如果查询语句中存在WHERE子句和ORDER BY子句，那么GROUP BY子句必须出现在WHERE子句之后，ORDER BY子句之前
        - 非分组列不能单独出现在检索列表中(可以被放到聚集函数中)
        - 对于派生表也就是子查询生成的表，使用聚合函数时必须要指定别名
        - 注意这两条语句的不同，聚集函数是作用在分组后的列上
            SELECT subject, COUNT(subject) as count_sub FROM student_score GROUP BY subject;
            SELECT COUNT(*) FROM (SELECT subject FROM student_score GROUP BY subject) as s1;
          
8. 子查询
   - 标量子查询
        SELECT * FROM student_score WHERE number = (SELECT number FROM student_info WHERE name = '杜琦燕');
        子查询（内层查询）的结果单纯是一个值
   - 列子查询
        SELECT * FROM student_score WHERE number IN (SELECT number FROM student_info WHERE major = '计算机科学与工程');
        子查询语句的结果集中并不是一个单独的值，而是一个列
   - 行子查询
        SELECT * FROM student_score WHERE (number, subject) = (SELECT number, '母猪的产后护理' FROM student_info LIMIT 1);
        子查询结果为一行
        注意在想要得到标量子查询或者行子查询，但又不能保证子查询的结果集只有一条记录时，应该使用LIMIT 1子句来限制记录数量
   - 表子查询
        SELECT * FROM student_score WHERE (number, subject) IN (SELECT number, '母猪的产后护理' FROM student_info WHERE major = '计算机科学与工程');
        如果子查询结果集中包含多行多列，那么这个子查询也可以被称之为表子查询
   - EXISTS和NOT EXISTS子查询
        SELECT * FROM student_score WHERE EXISTS (SELECT * FROM student_info WHERE number = 20180108);
        只关心子查询的结果集是不是为空集
   - 不相关子查询和相关子查询
        不相关子查询：子查询和外层查询都没有依赖关系，子查询可以独立运行并产生结果
        相关子查询：有依赖关系
        SELECT number, name, id_number, major FROM student_info WHERE EXISTS (SELECT * FROM student_score WHERE student_score.number = student_info.number);
   - 对同一个表的子查询
        会报错！：SELECT * FROM student_score WHERE subject = '母猪的产后护理' AND score > AVG(score);
        因为聚集函数是用来对分组做数据统计的，而WHERE子句是以记录为单位来执行过滤操作的，在WHERE子句执行完成之后才会得到分组，也就是说：聚集函数不能放到WHERE子句中
        所以需要这样做
         SELECT * FROM student_score WHERE subject = '母猪的产后护理' AND score > (SELECT AVG(score) FROM student_score WHERE subject = '母猪的产后护理');
9. 连接查询
   - 连接
       连接的本质就是把各个表中的记录都取出来依次匹配的组合加入结果集并返回给用户。笛卡尔积。
       SELECT t1.m1, t1.n1, t2.m2, t2.n2 FROM t1, t2;如果列名不重复也可以直接使用列名
       SELECT student_info.number, name, major, subject, score FROM student_info, student_score WHERE student_info.number = student_score.number;
   - 内连接
        SELECT * FROM t1 [INNER | CROSS] JOIN t2 [ON 连接条件] [WHERE 普通过滤条件];
        对于内连接的两个表，驱动表中的记录在被驱动表中找不到匹配的记录，该记录不会加入到最后的结果集
   - 外连接
        SELECT * FROM t1 LEFT | RIGHT [OUTER] JOIN t2 ON 连接条件 [WHERE 普通过滤条件];
        会将驱动表中的记录在被驱动表中找不到匹配的记录加入到最后的结果集
        左外连接：选取左侧的表为驱动表
        右外连接：选取右侧的表为驱动表
   - 连接的过滤条件
        -  WHERE子句中的过滤条件
            不论是内连接还是外连接，凡是不符合WHERE子句中的过滤条件的记录都不会被加入最后的结果集
        - ON子句中的过滤条件
            对于外连接的驱动表的记录来说，如果无法在被驱动表中找到匹配ON子句中的过滤条件的记录，那么该记录仍然会被加入到结果集中，对应的被驱动表记录的各个字段使用NULL值填充。
            内连接中的WHERE子句和ON子句是等价的。  
        - 一般情况下，我们都把只涉及单表的过滤条件放到WHERE子句中，把涉及两表的过滤条件都放到ON子句中，我们也一般把放到ON子句中的过滤条件也称之为连接条件。     
   - 多表连接
         SELECT * FROM t1 INNER JOIN t2 INNER JOIN t3 WHERE t1.m1 = t2.m2 AND t1.m1 = t3.m3;
   - 表的别名
        与列的别名类似，我们也可以为表来定义别名，格式与定义列的别名一致，都是用空白字符或者AS隔开，这个在表名特别长的情况下可以让语句表达更清晰一些
        SELECT s1.number, s1.name, s1.major, s2.subject, s2.score FROM student_info AS s1 INNER JOIN student_score AS s2 WHERE s1.number = s2.number; 
   - 自连接
        SELECT * FROM t1 AS table1, t1 AS table2;
        意义：比方说查询与某一行的某一列相同信息的行
        SELECT s2.number, s2.name, s2.major FROM student_info AS s1 INNER JOIN student_info AS s2 WHERE s1.major = s2.major AND s1.name = '史珍香' ;
   - 连接查询与子查询的转换
        可以转换，服务器优化时会将有得子查询转换为连接查询
10. 组合查询
    - 单表的组合查询
         SELECT m1 FROM t1 WHERE m1 < 2 UNION SELECT m1 FROM t1 WHERE m1 > 2;
         SELECT m1, n1 FROM t1 WHERE m1 < 2 UNION SELECT m1, n1 FROM t1 WHERE m1 > 2;
         注意：使用UNION连接起来的各个查询语句的查询列表中位置相同的表达式的类型应该是相同的，否则会自动转换。且结果集的列名是使用第一个查询中的列名。
    - 不同表的组合查询
        SELECT m1, n1 FROM t1 WHERE m1 < 2 UNION SELECT m2, n2 FROM t2 WHERE m2 > 2;
    - 包含或去除重复的行
        UNION默认过滤掉重复的记录
        UNION ALL保留重复记录
11. 数据的插入、删除和更新
    - 插入数据
        - 插入完整的记录
            INSERT INTO 表名 VALUES(列1的值，列2的值, ..., 列n的值);
        - 插入记录的一部分
            要求：该列允许存储NULL值，该列有DEFAULT属性，给出了默认值（没有设置默认为NULL）
            INSERT INTO first_table(first_column, second_column) VALUES (3, 'ccc');
        - 批量插入记录
            INSERT INTO first_table(first_column, second_column) VALUES(7, 'ggg'), (8, 'hhh');
        - 将某个查询的结果集插入表中
             INSERT INTO second_table(s, i) SELECT second_column, first_column FROM first_table WHERE first_column < 5;
        - INSERT IGNORE
            一些是主键或者具有UNIQUE约束的列或者列组合来说，它们不允许重复值的出现
            INSERT IGNORE INTO first_table(first_column, second_column) VALUES(1, '哇哈哈') ; 
        - INSERT ON DUPLICATE KEY UPDATE
           - 对于那些是主键或者具有UNIQUE约束的列或者列组合来说，如果表中已存在的记录中没有与待插入记录在这些列或者列组合上重复的值，那么就把待插入记录插到表中，否则按照规定去更新那条重复的记录中某些列的值
           - 我们可以使用VALUES(列名)的形式来引用待插入记录中对应列的值
            INSERT INTO first_table (first_column, second_column) VALUES(2, '红牛'), (3, '橙汁儿') ON DUPLICATE KEY UPDATE second_column = VALUES(second_column);
    - 删除数据
      - DELETE FROM 表名 [WHERE 表达式];
      - 删除最大记录
          DELETE FROM first_table ORDER BY first_column DESC LIMIT 1;
    - 更新数据
      - UPDATE 表名 SET 列1=值1, 列2=值2, ...,  列n=值n [WHERE 布尔表达式];
      - 更新最大记录
          UPDATE first_table SET second_column='爽歪歪' ORDER BY first_column DESC LIMIT 1;
12. 视图
    - 视图相当于一个查询语句的别名，简化语句的书写
    - 视图也可以被称为虚拟表，因为我们可以对视图进行一些类似表的增删改查操作，只不过我们对视图的相关操作都会被映射到查询语句对应的底层的表上
    - CREATE VIEW 视图名 AS 查询语句
    - SELECT * FROM view1;
    - 利用视图来创建新视图
        CREATE VIEW by_view AS SELECT number, name, score FROM male_student_view;
        在对这种依赖其他的视图而生成的新视图进行查询时，查询语句会先被转换成对它依赖的视图的查询，再转换成对底层表的查询。
    - 创建视图时指定自定义列名
        CREATE VIEW student_info_view(no, n, m) AS SELECT number, name, major FROM student_info;
    - 查看视图
        视图时默认是将其放在当前数据库下的：SHOW TABLES;
    - 查看视图的定义
        SHOW CREATE VIEW 视图名;
    - 可更新的视图
        并不是可以在所有的视图上执行更新语句的，一般我们只在查询语句里使用视图，而不在INSERT、DELETE、UPDATE语句里使用视图
    - 删除视图
        DROP VIEW 视图名
13. 变量与自定义语句结束分隔符
    - 存储程序可以封装一些语句，然后给用户提供一种简单的方式来调用这个存储程序，从而间接地执行这些语句
    - 根据调用方式的不同，我们可以把存储程序分为存储例程、触发器和事件
    - 存储例程又分为存储函数和存储过程
    - 变量
        SELECT @a;
        SET @a = 1;
        SET @b = @a;
        SET @a = (SELECT m1 FROM t1 LIMIT 1);
        SELECT m1, n1 FROM t1 LIMIT 1 INTO @a, @b;
    - 自定义语句结束分隔符
        目的是写函数时，避免函数体执行
        delimiter $
        delimiter EOF
14. 存储函数
    - mysql的设置默认是不允许创建函数
        1、更改全局配置
        SET GLOBAL log_bin_trust_function_creators = 1;
        有主从复制的时候 , 从机必须要设置 不然会导致主从同步失败
        2、更改配置文件my.cnf
        log-bin-trust-function-creators=1 重启服务生效
    - 存储函数其实就是一种函数，只不过在这个函数里可以执行MySQL的语句而已。
        ```
        mysql> delimiter $
        mysql> CREATE FUNCTION avg_score(s VARCHAR(100))
            -> RETURNS DOUBLE
            -> BEGIN
            ->     RETURN (SELECT AVG(score) FROM student_score WHERE subject = s);
            -> END $
        Query OK, 0 rows affected (0.00 sec)

        mysql> delimiter ;
        ```
    - SHOW FUNCTION STATUS [LIKE 需要匹配的函数名]
    - SHOW CREATE FUNCTION 函数名
    - DROP FUNCTION 函数名
    - 在函数体中定义局部变量
        - DECLARE 变量名1, 变量名2, ... 数据类型 [DEFAULT 默认值];
        - 这些在函数体内声明的变量只在该函数体内有用，当存储函数执行完成后，就不能访问到这些变量了
        -  在存储函数的函数体中，DECLARE语句必须放到其他语句的前边。
        ```
        mysql> delimiter $;
        mysql> CREATE FUNCTION var_demo()
        -> RETURNS INT
        -> BEGIN
        ->     DECLARE c INT DEFAULT 1;
        ->     SET c = 5;
        ->     RETURN c;
        -> END $
        Query OK, 0 rows affected (0.00 sec)

        mysql> delimiter ;
        ```
    - 在函数体中使用自定义变量
        在该函数执行完之后我们仍然可以访问到该自定义变量的值
        ```
        mysql> delimiter $
        mysql> CREATE FUNCTION user_defined_var_demo()
            -> RETURNS INT
            -> BEGIN
            ->     SET @abc = 10;
            ->     return @abc;
            -> END $
        Query OK, 0 rows affected (0.00 sec)

        mysql>
        mysql> delimiter ;
        mysql>
        ```
    - 判断语句的编写
        ```
        IF 表达式 THEN
            处理语句列表
        [ELSEIF 表达式 THEN
            处理语句列表]
        ... # 这里可以有多个ELSEIF语句
        [ELSE
            处理语句列表]
        END IF;
        ```
    - 循环语句
        - WHILE循环语句：
            ```
            WHILE 表达式 DO
                处理语句列表
            END WHILE;
            ```
        - REPEAT循环语句
        - LOOP循环语句
15. 存储过程
    - 存储函数和存储过程都属于存储例程，都是对某些语句的一个封装。存储函数侧重于执行这些语句并返回一个值，而存储过程更侧重于单纯的去执行这些语句
    - 定义
        ```
        CREATE PROCEDURE 存储过程名称([参数列表])
        BEGIN
            需要执行的语句
        END
        ```
    - 调用
        CALL 存储过程([参数列表]);
    - 查看和删除存储过程
        SHOW PROCEDURE STATUS [LIKE 需要匹配的存储过程名称]
        SHOW CREATE PROCEDURE 存储过程名称
        DROP PROCEDURE 存储过程名称
    - 存储过程的参数前缀
        参数类型 [IN | OUT | INOUT] 参数名 数据类型
        ```
        mysql> delimiter $
        mysql> CREATE PROCEDURE p_in (
        ->     IN arg INT
        -> )
        -> BEGIN
        ->     SELECT arg;
        ->     SET arg = 123;
        -> END $
        Query OK, 0 rows affected (0.00 sec)

        mysql> delimiter ;
        mysql>
        ```
        IN输入的参数不会被改变，OUT会被改变，INOUT参数既可以在存储过程中被读取，也可以被赋值后被调用者看到
    - 存储过程和存储函数的不同点
        - 存储函数在定义时需要显式用RETURNS语句标明返回的数据类型，而且在函数体中必须使用RETURN语句来显式指定返回的值，存储过程不需要。
        - 存储函数只支持IN参数，而存储过程支持IN参数、OUT参数、和INOUT参数。
        - 存储函数只能返回一个值，而存储过程可以通过设置多个OUT参数或者INOUT参数来返回多个结果。
        - 存储函数执行过程中产生的结果集并不会被显示到客户端，而存储过程执行过程中产生的结果集会被显示到客户端。
        - 存储函数直接在表达式中调用，而存储过程只能通过CALL语句来显式调用
16. 游标
    - 如果某个查询语句的结果集中有多条记录的话，我们就无法把它们赋值给某些变量了，所以为了方便我们去访问这些有多条记录的结果集，MySQL中引入了游标的概念
    - 我们可以根据这个游标取出它对应记录的信息，随后再移动游标，让它执向下一条记录。
    - 游标的使用步骤
        1.创建游标
        2.打开游标
        3.通过游标访问记录
        4.关闭游标
    - 创建游标
        DECLARE 游标名称 CURSOR FOR 查询语句;
        创建游标的语句一定要放在局部变量声明后头
    - 打开和关闭游标
        OPEN 游标名称;
        CLOSE 游标名称;
    - 使用游标获取记录
        FETCH 游标名 INTO 变量1, 变量2, ... 变量n
    - 遍历结束时的执行策略
        在FETCH语句获取不到记录的时候会触发一个事件，从而我们可以得知所有的记录都被获取过了，然后我们就可以去主动的停止循环
        DECLARE CONTINUE HANDLER FOR NOT FOUND 处理语句;
        ```
        CREATE PROCEDURE cursor_demo()
        BEGIN
            DECLARE m_value INT;
            DECLARE n_value CHAR(1);
            DECLARE not_done INT DEFAULT 1;

            DECLARE t1_record_cursor CURSOR FOR SELECT m1, n1 FROM t1;

            DECLARE CONTINUE HANDLER FOR NOT FOUND SET not_done = 0;

            OPEN t1_record_cursor;

            flag: LOOP
                FETCH t1_record_cursor INTO m_value, n_value;
                IF not_done = 0 THEN
                    LEAVE flag;
                END IF;
                SELECT m_value, n_value, not_done;
            END LOOP flag;

            CLOSE t1_record_cursor;
        END
        ```
17. 触发器
   - 存储例程是需要我们手动调用的，而触发器和事件是MySQL服务器在特定情况下自动调用的
   - 创建触发器
        ```
        CREATE TRIGGER 触发器名
        {BEFORE|AFTER}
        {INSERT|DELETE|UPDATE}
        ON 表名
        FOR EACH ROW
        BEGIN
            触发器内容
        END
        ```
        BEFORE	表示在具体的语句执行之前就开始执行触发器的内容
        AFTER	表示在具体的语句执行之后才开始执行触发器的内容
    - NEW和OLD来分别代表新记录和旧记录，来访问该记录中的内容的方式
        对于INSERT语句设置的触发器来说，NEW代表准备插入的记录，OLD无效。
        对于DELETE语句设置的触发器来说，OLD代表删除前的记录，NEW无效。
        对于UPDATE语句设置的触发器来说，NEW代表修改后的记录，OLD代表修改前的记录
        ```
        mysql> delimiter $
        mysql> CREATE TRIGGER bi_t1
            -> BEFORE INSERT ON t1
            -> FOR EACH ROW
            -> BEGIN
            ->     IF NEW.m1 < 1 THEN
            ->         SET NEW.m1 = 1;
            ->     ELSEIF NEW.m1 > 10 THEN
            ->         SET NEW.m1 = 10;
            ->     END IF;
            -> END $
        Query OK, 0 rows affected (0.02 sec)

        mysql> delimiter ;
        ```
    - 查看和删除触发器
        SHOW TRIGGERS;
        SHOW CREATE TRIGGER 触发器名;
        DROP TRIGGER 触发器名;
    - 注意事项
        - 触发器内容中不能有输出结果集的语句
        - 触发器内容中NEW代表记录的列的值可以被更改，OLD代表记录的列的值无法更改
        - 在BEFORE触发器中，我们可以使用SET NEW.列名 = 某个值的形式来更改待插入记录或者待更新记录的某个列的值，但是这种操作不能在AFTER触发器中使用，因为在执行AFTER触发器的内容时记录已经被插入完成或者更新完成了
        - 如果我们的BEFORE触发器内容执行过程中遇到了错误，那这个触发器对应的具体语句将无法执行；如果具体的操作语句执行过程中遇到了错误，那与它对应的AFTER触发器的内容将无法执行
18. 事件
    - 有时候我们想让MySQL服务器在某个时间点或者每隔一段时间自动地执行一些语句，这时候就需要去创建一个事件
    - 创建事件
        ```
        CREATE EVENT 事件名
        ON SCHEDULE
        {
            AT 某个确定的时间点| 
            EVERY 期望的时间间隔 [STARTS datetime][END datetime]
        }
        DO
        BEGIN
            具体的语句
        END
        ```
    - 查看和删除事件
       SHOW EVENTS;
       SHOW CREATE EVENT 事件名;
       DROP EVENT 事件名;
    - 注意事项
       -  MySQL服务器并不会帮助我们执行事件，除非我们使用下边的语句手动开启该功能
            SET GLOBAL event_scheduler = ON;
#### 2. 基础问题
1. 在学习MySQL时用到什么资料?
    - MySQL官方文档,不过那个太长了
    - 阿里云的taobao月报可以看看源码
    - 其他人的博客
    - 还有一些书里面的一些章节,如《高性能MySQL》,《MySQL必知必会》
2. 说一说什么是MySQL
    MySQL是关系型数据库，有着免费，开源，跨平台，高性能的优势
3. 说一说什么是关系型数据库
    由行和列组成的表来存放数据，且不同的表之间可以通过某种关系联系起来
4. 说一说MySQL的数据类型
        整数：INT 4字节
        浮点数：float 4， double 8
        定点数：DECIMAL(M, D),确保小数位精确
        日期和时间类型
        定长字符串：CHAR(M)， M代表字符数，分配的空间为定长M x W字节，不足用空格补全
        不定长字符串：VARCHAR(M)， M代表最多可记录的字符数，需要记录占用字节数，应对记录的字符串长短不一的情况，节省空间
        枚举：ENUM('', '', '')
        二进制:BINARY(M), VARBINARY(M)

5.  说一说WHERE子句和HAVING子句的区别
    WHERE子句在分组前进行过滤，作用于每一条记录，WHERE子句过滤掉的记录将不包括在分组中。而HAVING子句在数据分组后进行过滤，作用于整个分组。
6.  简单查询语句中各子句的顺序
    SELECT [DISTINCT] 查询列表
    [FROM 表名]
    [WHERE 布尔表达式]
    [GROUP BY 分组列表 ]
    [HAVING 分组过滤条件]
    [ORDER BY 排序列表]
    [LIMIT 开始行, 限制条数]
7.  为什么要把关系表分开存储？
    因为会造成同一个对象的基本信息的冗余存储，会导致浪费存储空间，以及当修改某个列的信息时必须修改多处，很容易造成信息的不一致，增大维护的困难。
8.  说一说连接查询的过程
    先从定第一个需要查询的表即驱动表按照条件筛选出结果集，再针对从驱动表每获取到的一条记录，到被驱动表中查询匹配的记录。即驱动表只需要查询一次，被驱动表可能会被查询多次。
9.  说一说视图
    视图相当于一个查询语句的别名，简化语句的书写。视图也可以被称为虚拟表，因为我们可以对视图进行一些类似表的增删改查操作，只不过我们对视图的相关操作都会被映射到查询语句对应的底层的表上。
10. 说一说存储函数，存储过程，游标，触发器以及事件
    存储函数和存储过程，都是对某些语句的一个封装。存储函数侧重于执行这些语句并返回一个值，而存储过程更侧重于单纯的去执行这些语句。
    而游标是为了在使用存储函数和存储过程，并针对某个查询语句的结果集有多条记录的情况下，遍历去访问这些记录。
    存储例程是需要我们手动调用的，而触发器和事件是MySQL服务器在特定情况下自动调用的。触发器是在具体的语句如INSERT|DELETE|UPDATE执行之前或之后会自动执行，而事件是在某一个时间点或者某一段时间自动执行一些语句。

#### 3. 架构问题
1. 说一说MySQL的基础架构
    MySQL可以分为服务层和存储引擎层。Server层包括连接器、 查询缓存、 分析器、 优化器、 执行器，涵盖MySQL的大多数核心服务功能， 以及所有的内置函数， 所有跨存储引擎的功能都在这一层实现， 比如存储过程、 触发器、 视图等
    而存储引擎层负责数据的存储和提取，不同的存储引擎共用一个Server层
2. 说一说一条SQL查询语句是如何执行的
    - 首先客户端会通过连接器连接到数据库上。
    - 连接建立完后，执行SELECT语句，首先会查询缓冲。如果缓冲命中，则直接返回结果。
    - 如果没有命中查询缓存，MySQL会通过分析器对SQL语句做词法分析与语法分析。
    - 分析完成后，优化器进行优化，选择最高效率的执行方案。比如在表里面有多个索引的时候， 决定使用哪个索引； 或者在一个语句有多表关联（join）的时候， 决定各个表的连接顺序。等等。
    - 优化完成后，执行器开始执行语句。首先判断对这个表有没有执行查询的权限，有就调用存储引擎提供的接口。
3. 说一说MySQL的连接器
    连接器负责跟客户端建立连接、 获取权限、 维持和管理连接。 
4. 如何查看MySQL的客户端的连接信息？如何查看 MySQL 服务被多少个客户端连接了？
    show processlist
5. 空闲连接会一直占用着吗？
    当然不是了，MySQL 定义了空闲连接的最大空闲时长，由 wait_timeout 参数控制的，默认值是 8 小时（28880秒），如果空闲连接超过了这个时间，连接器就会自动将它断开
6. MySQL 的连接数有限制吗？
    MySQL 服务支持的最大连接数由 max_connections 参数控制
7. 什么是数据库的长连接与短连接？
    长连接是指连接成功后， 如果客户端持续有请求， 则一直使用同一个连接。 短连接则是指每次执行完很少的几次查询就断开连接， 下次查询再重新建立一个。
    每次连接开销大，应该尽量使用长连接
8. 数据库长连接会导致什么问题？
    会导致MySQL占用内存高，因为MySQL在执行过程中临时使用的内存是管理在连接对象里面的。 这些资源会在连接断开的时候才释放。MySQL占用内存过大时会导致系统强行杀掉，即 MySQL 服务异常重启。
9.  如何解决长连接的问题？
   - 定期断开长连接。 
   - 客户端主动重置连接，执行mysql_reset_connection来重新初始化连接资源。 
10. 说一说MySQL的查询缓存
    MySQL查询缓存会用键值对的方式将查询语句与结果缓存在内存中。执行SELECT语句时，首先会查询缓冲。如果缓冲命中，则直接返回结果。
11. 查询缓存有什么问题？
   - 查询缓存的失效非常频繁， 只要有对一个表的更新， 这个表上所有的查询缓存都会被清空。对于更新压力大的数据库来说， 查询缓存的命中率会非常低。 除非你的业务就是有一张静态表， 很长时间才会更新一次。比如， 一个系统配置表， 那这张表上的查询才适合使用查询缓存。
   - 应该默认关闭查询缓存，然后 要使用查询缓存的语句， 可以用SQL_CACHE显式指定

#### 4. 索引
1. 什么是索引？
    索引的定义就是帮助存储引擎快速获取数据的一种数据结构，形象的说就是索引是数据的目录
2. 什么是存储引擎？
   存储引擎，就是如何存储数据、如何为存储的数据建立索引和如何更新、查询数据等技术的实现方法
3. 说一说InnoDB为什么使用B+树而不是其他数据结构？
    - B+Tree 与 BTree的区别（聚簇索引的特点，B+树有什么特点,性能比较）
        - 查找IO操作更少，内存占用更少
            B+Tree 只在叶子节点存储数据，而 B 树 的非叶子节点也要存储数据。导致这样使得同样大小的磁盘页可以容纳更多节点元素，树的层级更少，在相同数据量下，ＩＯ操作更少。同时如果用B树查找，查找过程中不需要的节点数据也会加载到内存中，占用内存资源
        - 性能稳定
            Ｂ树的查找只需找到匹配元素即可，最好情况下查找到根节点，最坏情况下查找到叶子结点，所以性能很不稳定，而Ｂ＋树每次必须查找到叶子结点，性能稳定
        - B+树的插入和删除效率更高
           -  B+ 树有大量的冗余节点，这样使得删除一个节点的时候，可以直接从叶子节点中删除，甚至可以不动非叶子节点，这样删除非常快。B 树没有冗余节点，删除节点的时候非常复杂，比如删除根节点中的数据，可能涉及复杂的树的变形
           -  B+ 树的插入也是一样，有冗余节点，插入可能存在节点的分裂（如果节点饱和），但是最多只涉及树的一条路径。而且 B+ 树会自动平衡，不需要像更多复杂的算法，类似红黑树的旋转操作等
        - 更适合范围查找
           B+树范围查询首先通过二分查找，找到范围下限，然后同过叶子结点的链表顺序遍历，直至找到上限即可，效率更高。而B树则是通过二分法到范围下限，在不断通过中序遍历，直到查找到范围的上限，整个过程比较耗时；
    - B+Tree vs 平衡二叉搜索树（AVL树）
        平衡二叉搜索树查找和插入数据都是O(log2N)基本，连续插入新元素开销不大。
        对于有 N 个叶子节点且节点允许的最大子节点个数为 d 个的 B+Tree，其搜索复杂度为O(logdN)。相同数据量，二叉树相较B+树层级更多，导致查找数据的IO操作更多
    - B+Tree vs Hash
        Hash等值查询的时候效率高O(1)，但是范围查询时需要扫描全表
    - B+Tree vs 有序数组
        有序数组在等值查询和范围查询场景中的性能就都非常优秀O(logN),但只适用于静态表，增删都会导致很大的开销
4. 说一说B+树和B树各自的适用场景
    存在大量范围检索的场景，适合使用 B+树，比如数据库。而对于大量的单个索引查询的场景，可以考虑 B 树，比如 nosql 的MongoDB。
5.  说一说MySQL有哪些索引？
    按「数据结构」分类：B+tree索引、Hash索引、Full-text索引。
    按「物理存储」分类：聚簇索引（主键索引）、二级索引（辅助索引）。
    按「字段特性」分类：主键索引、唯一索引、普通索引、前缀索引。
    按「字段个数」分类：单列索引、联合索引
6.  InnoDB创建表时没有主键会怎么办？
    如果没有主键，就选择第一个不包含 NULL 值的唯一列作为聚簇索引的索引键（key）；如果前面的条件也不满足，InnoDB 将自动生成一个隐式自增 id 列作为聚簇索引的索引键（key）
7.  说一说通过主键查询数据的过程
    B+Tree 会自顶向下逐层进行查找，通过连续的二分法确定目录项记录进而确定索引数据
8.  通过二级索引查询商品数据的过程
    和通过主键查询相似，但是需要进行回表操作
9.  主键索引的 B+Tree 和二级索引的 B+Tree 区别
    主键索引的 B+Tree 的叶子节点存放的是实际数据，所有完整的用户记录都存放在主键索引的 B+Tree 的叶子节点里；
    二级索引的 B+Tree 的叶子节点存放的是主键值和索引，而不是实际数据。
10. 说一说覆盖索引
    在查询列表里只包含索引列，省去了 回表 操作带来的性能损耗。
11. 说一说主键有什么特点
   - 一个表最多只能有一个主键，主键的值不能重复，通过主键可以找到唯一的一条记录
   - 主键列默认是有NOT NULL属性
   - 一般会为主键列设置AUTO_INCREMENT属性
   - 自动建立索引
11. 说一说唯一键
    - 为某个列或多个列的组合添加了一个UNIQUE属性。从此我们插入的记录的该列的值就不能重复
    - 自动建立索引
12. 说一说外键
    即外键约束。如果A表中的某个列或者某些列依赖与B表中的某个列或者某些列，那么就称A表为子表，B表为父表。子表和父表可以使用外键来关联起来。
13. 说一说自增
   - 一个表中最多有一个具有AUTO_INCREMENT属性的列
   - 具有AUTO_INCREMENT属性的列必须建立索引。
   - 拥有AUTO_INCREMENT属性的列就不能再通过指定DEFAULT属性来指定默认值。
   - 一般拥有AUTO_INCREMENT属性的列都是作为主键的属性，来自动生成唯一标识一条记录的主键值。
14. 说一说主键和UNIQUE约束的区别
   - 一张表中只能定义一个主键，却可以定义多个UNIQUE约束
   - 主键列不允许存放NULL，而声明了UNIQUE属性的列可以存放NULL，而且NULL可以重复地出现在多条记录中
15. NULL值意味着什么？
    NULL其实并不是一个值，它代表不确定，我们平常说某个列的值为NULL，意味着这一列的值尚未被填入
16. 说一说表中哪些列需要建立索引？
    - 主键和唯一键自动建立索引
    - 自增列必须建立索引
    - 对于外键，父表中被子表依赖的列或者列组合必须建立索引
17. 基于主键索引和普通索引的查询有什么区别？
   需要回表，基于非主键索引的查询需要多扫描一棵索引树
18. 为什么主键要设置自增属性？
   - 为了满足B+树每层节点都是按照索引列的值从小到大的顺序排序，插入新值时可能会导致页分裂等性能开销。如果设置自增主键每次插入一条新记录，都是追加操作，都不涉及到挪动其他记录， 也不会触发页分裂。有业务逻辑的字段做主键， 则往往不容易保证有序插入， 这样写数据成本相对较高
   - 同时对于非主键索引，叶子节点会存储主键值。主键长度越小， 普通索引的叶子节点就越小， 普通索引占用的空间也就越小。
19. 有没有什么场景适合用业务字段直接做主键的呢？
    因为没有其他索引，所以不用担心其他的二级索引内主键占用空间太大
   - 只有一个索引；
   - 该索引必须是唯一索引；
20. 为什么要重建非主键索引?
    - 索引可能因为删除， 或者页分裂等原因， 导致数据页有空洞， 重建索引的过程会创建一个新的索引， 把数据按顺序插入， 这样页面的利用率最高， 也就是索引更紧凑、 更省空间。
    - 对于主键索引，重建的话会导致整个表重建
21. 说一说前缀索引
    前缀索引是指对字符类型字段的前几个字符建立的索引，用处是减少索引占用的存储空间，提升查询效率
22. 在一个市民信息表上， 是否有必要将身份证号和名字建立联合索引？
    如果有一个高频请求， 要根据市民的身份证号查询他的姓名， 这个联合索引就有意义了。 它可以在这个高频请求上用到覆盖索引， 不再需要回表查整行记录， 减少语句的执行时间。
23. 说一说最左前缀原则
    联合索引查询的 B+Tree时按照索引项的最左边的那一项排序，最左项相同的情况下再按照下一项排序。利用索引的前提是索引里的 key 是有序的。比如范围列可以用到联合索引，但是范围列后面的列无法用到联合索引。
24. 说一说在建立联合索引的时候有什么要注意的？
    - 如果通过调整顺序， 可以少维护一个索引， 那么这个顺序往往就是需要优先考虑采用的。比如联合索引（a,b），因为最左前缀原则，一般就不需要在a上建立索引了
    - 建立联合索引时，要把区分度大即更少重复的字段排在前面，这样区分度大的字段越有可能被更多的 SQL 使用到
25. 说一说索引下推优化
    可以在索引遍历过程中，对索引中包含的字段先做判断， 直接过滤掉不满足条件的记录， 减少回表次数。比如联合索引（a，b），搜索条件中有b的限制，则先判断b再对满足限制的条件做回表
26. 索引有什么缺点？
   - 需要占用物理空间，数量越大，占用空间越大；
   - 创建索引和维护索引要耗费时间，这种时间随着数据量的增加而增大；
   - 会降低表的增删改的效率，因为每次增删改索引，B+ 树为了维护索引有序性，都需要进行动态维护 
27. 什么时候适用索引？
    - 字段有唯一性限制的。极端情况索引只有两个值，会导致每次搜索即使用到索引也需要再查找50%的数据
    - 经常用于 WHERE 查询条件的字段，这样能够提高整个表的查询速度，如果查询条件不是一个字段，可以建立联合索引。
    - 经常用于 GROUP BY 和 ORDER BY 的字段，这样在查询的时候就不需要再去做一次排序了，因为我们都已经知道了建立索引之后在 B+Tree 中的记录都是排序好的
28. 什么时候不需要创建索引？
    - WHERE 条件，GROUP BY，ORDER BY 里用不到的字
        索引的价值是快速定位，如果起不到定位的字段通常是不需要创建索引的，因为索引是会占用物理空间的。
    - 字段中存在大量重复数据，不需要创建索引
        比如性别字段，只有男女，如果数据库表中，男女的记录分布均匀，那么无论搜索哪个值都可能得到一半的数据。在这些情况下，还不如不要索引，因为 MySQL 还有一个查询优化器，查询优化器发现某个值出现在表的数据行中的百分比很高的时候，它一般会忽略索引，进行全表扫描。
    - 表数据太少的时候，不需要创建索引；
    - 经常更新的字段不用创建索引
        比如不要对电商项目的用户余额建立索引，因为索引字段频繁修改，由于要维护 B+Tree的有序性，那么就需要频繁的重建索引，这个过程是会影响数据库性能的。
29. 有什么优化索引的方法？
    - 前缀索引优化；
        使用前缀索引是为了减小索引字段大小，可以增加一个索引页中存储的索引值，有效提高索引的查询速度。索引页能够存储的索引值越多，需要的IO操作就越少
    - 覆盖索引优化；
        查找的项可以直接从二级索引中得到，避免回表。
        假设我们只需要查询商品的名称、价格，有什么方式可以避免回表呢？建立一个联合索引
    - 主键索引最好是自增的；
        InnoDB 创建主键索引默认为聚簇索引，数据被存放在了 B+Tree 的叶子节点上。也就是说，同一个叶子节点内的各个数据是按主键顺序存放的。自增主键插入数据时按序的，不需要移动数据。而非自增主键插入数据可能会导致页分裂，造成大量的内存碎片，导致索引结构不紧凑，从而影响查询效率。
    - 索引最好设置为 NOT NUL
        - 索引列存在 NULL 就会导致优化器在做索引选择的时候更加复杂，更加难以优化，因为可为 NULL 的列会使索引、索引统计和值比较都更复杂，比如进行索引统计时，count 会省略值为NULL 的行。
        - NULL 值是一个没意义的值，但是它会占用物理空间，所以会带来的存储空间的问题，会导致更多的存储空间占用，因为 InnoDB 默认行存储格式COMPACT，会用 1 字节空间存储 NULL 值列表
    - 防止索引失效
30. 前缀索引的局限性
    - order by 就无法使用前缀索引；
    - 无法把前缀索引用作覆盖索引；
31. 说一说索引失效的情况
    - 对索引使用左或者左右模糊匹配
       也就是 like %xx 或者 like %xx%这两种方式都会造成索引失效；因为索引 B+ 树是按照「索引值」有序排列存储的，只能根据前缀进行比较。通过前缀查找的过程类似于一般查找，只不过每次查找都要比较当前节点的前缀和要查找的前缀的大小
    - 对索引使用函数或对索引进行表达式计算
        因为索引保存的是索引字段的原始值，而不是经过函数计算后的值，自然就没办法走索引了。
    - 对索引隐式类型转换
        MySQL在遇到字符串和数字比较的时候，会自动把字符串转为数字，然后再进行比较。如果索引是字符串，而条件是数字，则会将索引转换为数字，就相当于使用了函数
    - 联合索引非最左匹配
        在联合索引的情况下，数据是按照索引第一列排序，第一列数据相同时才会按照第二列排序。
    - 在 WHERE 子句中，如果在 OR 前的条件列是索引列，而在 OR 后的条件列不是索引列，那么索引会失效。
32. 对索引使用左或者左右模糊匹配一定会导致索引失效吗？
    不一定。判断是否使用索引的标准是，使用二级索引+回表的开销小于全表扫描。而对于数据库表中只有主键和二级索引字段的情况，即使使用了左模糊匹配，也会全扫描二级索引树，因为二级索引树的叶子节点只记录索引列和主键值，而聚簇索引还要记录事务id，回滚指针等导致全扫描二级索引树的IO开销更小。
33.  联合索引非最左匹配一定回导致索引失效吗？
    不一定。判断是否使用索引的标准是，使用二级索引+回表的开销小于全表扫描。而对于数据库表中只有主键和二级索引字段的情况，即使使用了联合索引非最左匹配，也会全扫描二级索引树，因为二级索引树的叶子节点只记录索引列和主键值，而聚簇索引还要记录事务id，回滚指针等导致全扫描二级索引树的IO开销更小。
34. 说一说count(*)，count(1),count(主键)，count(普通字段)的效率
    效率：count(*) = count(1) > count(主键) > count(普通字段)
    count()意义是统计在对应字段的记录中,不为NULL的有多少个
    对应count(\*)和count(1)都是求对应字段记录一共有多少行，所以效率相同。对于count(*)，count(1)，count(主键)，如果存在二级索引，那么都会全扫描二级索引，因为这样的IO开销更低，在这种情况下，由于count(\*)和count(1)不需要判断值是否为null，所以效率更高。而对于普通字段，会采用全表扫描的方式，效率最差。
    如果你非要统计表中该字段不为 NULL 的记录个数，建议给这个字段建立一个二级索引。
35. 如何优化count(*)
    - 近似值,通过show table status 或者 explain 命令来表进行估算
    - 额外表保存计数值
36.  说一说EXPLAIN产生的执行计划
    possible_keys 字段表示可能用到的索引；
    key 字段表示实际用的索引，如果这一项为 NULL，说明没有使用索引；
    key_len 表示索引的长度；
    rows 表示扫描的数据行数。
    type 表示扫描数据的方式
37. 扫描数据的方式有哪些
    const（结果只有一条的主键或唯一索引扫描）
    eq_ref（唯一索引扫描）
    ref（非唯一索引扫描）
    range（索引范围扫描）
    index（全索引扫描）
    ALL（全表扫描
    要尽量避免全表扫描和全索引扫描，也要避免 extra 的结果为 using filesort 的语句
38. InnoDB 是如何存储数据的
    通过B+树来存储数据，非叶子节点为存放目录项记录的数据页，叶子节点为存放数据的数据页。数据页通过文件头里的指针组成了双向链表，而数据页中的记录按照「主键」顺序组成单向链表。
39. B+ 树是如何进行查询的？
    从根节点开始，先通过主键二分法定位到页内范围包含查询值的页，在该页中查找更详细的目录项
    再在非叶子节点中，继续通过二分法快速定位到符合页内范围包含查询值的页，到对应叶子节点查找记录
    在叶子节点中，通过槽查找记录时，使用二分法快速定位要查询的记录在哪个槽，定位到槽后，再遍历槽内的所有记录，找到所需的记录


#### 5. 事务
1. 为什么不推荐使用长事务？
    当没有事务再需要用到这些回滚日志时， 回滚日志会被删除。长事务意味着系统里面会存在很老的事务视图。 由于这些事务随时可能访问数据库里面的任何数据， 所以这个事务提交之前， 数据库里面它可能用到的回滚记录都必须保留， 这就会导致大量占用存储空间。
2. 如何防止长事务？
   - 客户端
     - 开启自动提交set autocommit=1,并通过显式语句的方式来启动事务
     - 确认是否有不必要的只读事务
     - 通过SETMAX_EXECUTION_TIME命令，来控制每个语句执行的最长时间， 避免单个语句意外执行太长时间
   - 服务端
     - 监控 information_schema.Innodb_trx表，设置长事务阈值， 超过就报警/或者kill
     - 在业务功能测试阶段要求输出所有的general_log， 分析日志行为提前发现问题
#### 6. 锁
1. 
#### 7. 日志redolog，binlog，undolog
1. 一条SQL更新语句是如何执行的？
   - 连接器，更新没有查询缓存，分析器，优化器，执行器，调用引擎接口
   - 执行器通过B+树找到要修改的数据页，如果在内存中就直接返回给执行器，不在就先从磁盘中读入
   - 得到旧的数据更新后调用引擎接口写入新数据到内存中，并将这个更新操作记录到内存redolog中。此时redolog处于准备状态
   - 执行器再生成这个操作的binlog，并写入磁盘
   - 执行器调用引擎的提交事务接口，将redolog改为提交状态，更新完成
2. 怎样让数据库恢复到半个月内任意一秒的状态？
    首先，找到最近的一次全量备份，从这个备份恢复到临时库；
    然后， 从备份的时间点开始， 将备份的binlog依次取出来， 重放到对应的时刻
3. 为什么redolog是两阶段提交的？
    因为不这么做会导致主从不一致。如果先写redo log后写binlog会导致，如果redolog写完后发生崩溃，主库的数据会恢复到执行完本次更新操作后的状态，而由于binlog里并没有记录这次操作所以从库的数据不会有此次操作。导致主从不一致。同意如果先写binlog后写redolog，会导致相当于从库的数据更新了而主库的数据没更新。
4. 什么时候需要恢复临时库或者说恢复数据？
   - 误操作时需要恢复数据
   - 当你需要扩容的时候， 也就是需要再多搭建一些备库来增加系统的读能力的时候，要用全量备份加上应用binlog来实现的， 这个“不一致”就会导致你的线上出现主从数据库不一致
5. 说一说redo日志
   - 作用
        如果内存中有脏页未写入磁盘，并且这时系统崩溃，则可以根据redo log进行重做，从而达到事务的持久性这一特性
   - 类型
        物理日志，记录的是物理数据页面的修改的信息
   - 产生时机
        事务开始后就产生redolog到内存中的日志缓存中，随着后台线程刷新等刷盘时机在事务过程中就会被刷新到磁盘
   - 刷盘时机
      - 日志缓存空间不足时
      - 事务提交时（保持持久性）
      - 后台MASTER线程刷新
      - 正常关闭服务器时
   - 磁盘释放时机
     通过checkpoint判断即对应事务的脏页已经刷新到磁盘里后，redo日志占用的磁盘空间就可以复用
6. 为什么再大的事务的提交（commit）的时间也是很短暂的？
    因为后台线程会每秒都将redo log刷新到磁盘中。开启binlog后可能会造成提交速度减慢，因为时一次性写入的。
7. 说一说bin日志
   - 作用：
       - 用于复制，在主从复制中，从库利用主库上的binlog进行重播，实现主从同步。
       - 用于数据库的基于时间点的还原。
   - 类型
        逻辑格式的日志，可以简单认为就是执行过的事务中的sql语句。但又不完全是sql语句这么简单，而是包括了执行的sql语句（增删改）反向的信息，也就意味着delete对应着delete本身和其反向的insert；update对应着update执行前后的版本的信息；insert对应着delete和insert本身的信息。
   - 产生时机（刷盘时间）
        事务提交的时候，一次性将事务中的sql语句记录到磁盘binlog中
   - 磁盘释放时机
      有个保存时机限制，超过保存时间就删除
8. 说一说undo日志
   - 作用
       - 用于回滚
       - 实现MVCC
   - 类型
        逻辑格式的日志
   - 产生时机
        事务开始之前，将当前版本生成的undolog写入
   - 释放时机
       - purge线程通过readview来判断当没有事务再需要用到这些回滚日志，即当系统里没有比这个回滚日志更早的read-view的时候，就可以删除了。（比如说对于RR隔离级别，在第一次执行SELECT时创建readview。当前的readview可见，后面的别的并发事务更新的数据都不可见，即防止了不可重复读与幻读。那么当这个事务提交后，即这个readview释放了，就说明不再需要这个readview前的undo日志了，就可以删除了）
       - insert undo 在事务提交之后就可以被释放掉了，而 update undo 由于还需要支持 MVCC ，不能立即删除掉。
9. 说一说redo日志和bin日志的不同
   - 作用不同：redo log是保证事务的持久性的，是事务层面的，binlog作为还原的功能，是数据库层面的
   - 内容不同：redo log是物理日志，binlog是逻辑日志
   - 产生时机和释放时机都不同
   - redo log是循环写入磁盘而binlog是追加写入磁盘
   - redo log是InnoDB引擎特有的； binlog是MySQL的Server层实现的， 所有引擎都可以使用
   - 恢复数据时候的效率，基于物理日志的redo log恢复数据的效率要高于语句逻辑日志的binlog
10. undo日志是怎么实现MVCC的？
    每条数据都有两个隐藏字段，即最近一次更新这条数据的事务id，以及指向更新这个事务之前形成undolog的回滚指针。这样就形成了一个undolog的版本链。我们通过这个版本链，结合ReadView机制判断版本链中的哪个版本是当前事务可见的，即可以实现MVCC机制，避免脏读，可重复读与幻读。
11. 一天一备和一周一备有什么区别？
    在一天一备的模式里， 最坏情况下需要应用一天的binlog。一周一备最坏情况就要应用一周的binlog了。但频繁全量备份需要消耗更多存储空间。




