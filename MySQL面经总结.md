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
4. 简单查询
   - 查询列
        SELECT 列名1, 列名2, ... 列名n FROM 表名;
        SELECT * FROM 表名;
        SELECT 列名 [AS] 列的别名 FROM 表名;
   - 去除重复值
        SELECT DISTINCT 列名 FROM 表名;
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
#### 1. 综合问题
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
        定长字符串：CHAR(M)， M x W字节，不足用空格补全
        不定长字符串：VARCHAR(M)， 记录占用字节数，节省CHAR(M)里不足时浪费的空间
        枚举：ENUM('', '', '')
        二进制:BINARY(M), VARBINARY(M)
5. 说一说主键有什么特点
   - 一个表最多只能有一个主键，主键的值不能重复，通过主键可以找到唯一的一条记录
   - 主键列默认是有NOT NULL属性
   - 一般会为主键列设置AUTO_INCREMENT属性
   - 自动建立索引
6. 说一说唯一键
    - 为某个列或多个列的组合添加了一个UNIQUE属性。从此我们插入的记录的该列的值就不能重复
    - 自动建立索引
7. 说一说外键
    即外键约束。如果A表中的某个列或者某些列依赖与B表中的某个列或者某些列，那么就称A表为子表，B表为父表。子表和父表可以使用外键来关联起来。
8.  说一说自增
   - 一个表中最多有一个具有AUTO_INCREMENT属性的列
   - 具有AUTO_INCREMENT属性的列必须建立索引。
   - 拥有AUTO_INCREMENT属性的列就不能再通过指定DEFAULT属性来指定默认值。
   - 一般拥有AUTO_INCREMENT属性的列都是作为主键的属性，来自动生成唯一标识一条记录的主键值。
9. 说一说主键和UNIQUE约束的区别
   - 一张表中只能定义一个主键，却可以定义多个UNIQUE约束
   - 主键列不允许存放NULL，而声明了UNIQUE属性的列可以存放NULL，而且NULL可以重复地出现在多条记录中
10. NULL值意味着什么？
    NULL其实并不是一个值，它代表不确定，我们平常说某个列的值为NULL，意味着这一列的值尚未被填入
11. 说一说表中哪些列需要建立索引？
    - 主键和唯一键自动建立索引
    - 自增列必须建立索引
    - 对于外键，父表中被子表依赖的列或者列组合必须建立索引
12. 说一说WHERE子句和HAVING子句的区别
    WHERE子句在分组前进行过滤，作用于每一条记录，WHERE子句过滤掉的记录将不包括在分组中。而HAVING子句在数据分组后进行过滤，作用于整个分组。
13. 简单查询语句中各子句的顺序
    SELECT [DISTINCT] 查询列表
    [FROM 表名]
    [WHERE 布尔表达式]
    [GROUP BY 分组列表 ]
    [HAVING 分组过滤条件]
    [ORDER BY 排序列表]
    [LIMIT 开始行, 限制条数]
14. 为什么要把关系表分开存储？
    因为会造成同一个对象的基本信息的冗余存储，会导致浪费存储空间，以及当修改某个学生的基本信息时必须修改多处，很容易造成信息的不一致，增大维护的困难。
15. 说一说连接查询的过程
    先从定第一个需要查询的表即驱动表按照条件筛选出结果集，再针对从驱动表每获取到的一条记录，到被驱动表中查询匹配的记录。即驱动表只需要查询一次，被驱动表可能会被查询多次。
16. 说一说视图
    视图相当于一个查询语句的别名，简化语句的书写。视图也可以被称为虚拟表，因为我们可以对视图进行一些类似表的增删改查操作，只不过我们对视图的相关操作都会被映射到查询语句对应的底层的表上。
17. 说一说参存储函数，存储过程，游标，触发器以及事件
    存储函数和存储过程，都是对某些语句的一个封装。存储函数侧重于执行这些语句并返回一个值，而存储过程更侧重于单纯的去执行这些语句。
    而游标是为了在使用存储函数和存储过程，并针对某个查询语句的结果集有多条记录的情况下，遍历去访问这些记录。
    存储例程是需要我们手动调用的，而触发器和事件是MySQL服务器在特定情况下自动调用的。触发器是在具体的语句如INSERT|DELETE|UPDATE执行之前或之后会自动执行，而事件是在某一个时间点或者某一段时间自动执行一些语句。