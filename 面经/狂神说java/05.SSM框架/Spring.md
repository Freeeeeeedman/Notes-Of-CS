# 1、Spring

## 1.1、简介

- Spring:春天-----给软件行业带来春天。
- 2002，首次推送了spring框架的雏形：interface21框架
- spring框架已interface21框架为基础，经过重新设计，并不断丰富其内涵，于2004年3月24日，发布了1.0正式版。
- Rod Johnson，spring framework创始人，著名作者。很难想象Rod Johnson的学历，真的让好多人大吃一惊，它是悉尼大学的博士，然而他的专业不是计算机，而是音乐学。
- spring理念：使现在的技术更加容易使用，本身是一个大杂烩，整合了现有的技术框架！
- SSH:Structs + Spring + Hibernate
- SSM:SpringMVC + Spring + Mybatis
- 官网：[Spring Framework Overview](https://docs.spring.io/spring-framework/docs/current/reference/html/overview.html#overview)
- github地址：[GitHub - spring-projects/spring-framework: Spring Framework](https://github.com/spring-projects/spring-framework)

```xml
<!-- https://mvnrepository.com/artifact/org.springframework/spring-webmvc -->
<dependency>
    <groupId>org.springframework</groupId>
    <artifactId>spring-webmvc</artifactId>
    <version>5.3.19</version>
</dependency>

<!-- https://mvnrepository.com/artifact/org.springframework/spring-webmvc -->
<dependency>
    <groupId>org.springframework</groupId>
    <artifactId>spring-jdbc</artifactId>
    <version>5.3.19</version>
</dependency>
```



## 1.2、优点

- spring是一个开源的免费的框架（容器）！
- spring是一个轻量级的、非侵入式的框架！
- 控制反转（IOC）、面向切面编程（AOP）！
- 支持事务的处理，对框架整合的支持！



==总结一句话：spring就是一个轻量级的控制反转（IOC）和面向切面编程（AOP）的框架！==

## 1.3、组成

![img](https://gitee.com/zhayuyao/img/raw/master/zhayuyao/img/2019102923475419.png)

spring框架是一个分层架构，由7个模块组成，spring模块构建在核心容器之上，核心容器定义了创建、配置和管理bean的方式。

![img](https://gitee.com/zhayuyao/img/raw/master/zhayuyao/img/2020010313504529.png)

组成spring框架的每个模块（或者组件）都可以单独存在，或者与其他一个或者多个模块联合实现。每个模块的功能如下：

- **核心容器**：核心容器提供 Spring 框架的基本功能。核心容器的主要组件是 BeanFactory，它是工厂模式的实现。BeanFactory 使用*控制反转*（IOC） 模式将应用程序的配置和依赖性规范与实际的应用程序代码分开。
- **Spring 上下文**：Spring 上下文是一个配置文件，向 Spring 框架提供上下文信息。Spring 上下文包括企业服务，例如 JNDI、EJB、电子邮件、国际化、校验和调度功能。
- **Spring AOP**：通过配置管理特性，Spring AOP 模块直接将面向切面的编程功能 , 集成到了 Spring 框架中。所以，可以很容易地使 Spring 框架管理任何支持 AOP的对象。Spring AOP 模块为基于 Spring 的应用程序中的对象提供了事务管理服务。通过使用 Spring AOP，不用依赖组件，就可以将声明性事务管理集成到应用程序中。
- **Spring DAO**：JDBC DAO 抽象层提供了有意义的异常层次结构，可用该结构来管理异常处理和不同数据库供应商抛出的错误消息。异常层次结构简化了错误处理，并且极大地降低了需要编写的异常代码数量（例如打开和关闭连接）。Spring DAO 的面向 JDBC 的异常遵从通用的 DAO 异常层次结构。
- **Spring ORM**：Spring 框架插入了若干个 ORM 框架，从而提供了 ORM 的对象关系工具，其中包括 JDO、Hibernate 和 iBatis SQL Map。所有这些都遵从 Spring 的通用事务和 DAO 异常层次结构。
- **Spring Web 模块**：Web 上下文模块建立在应用程序上下文模块之上，为基于 Web 的应用程序提供了上下文。所以，Spring 框架支持与 Jakarta Struts 的集成。Web 模块还简化了处理多部分请求以及将请求参数绑定到域对象的工作。
- **Spring MVC 框架**：MVC 框架是一个全功能的构建 Web 应用程序的 MVC 实现。通过策略接口，MVC 框架变成为高度可配置的，MVC 容纳了大量视图技术，其中包括 JSP、Velocity、Tiles、iText 和 POI。

## 1.4、拓展

在spring的官网有这个介绍：现代化的java开发！说白就是基于spring的开发！

![image-20220502111643372](https://gitee.com/zhayuyao/img/raw/master/zhayuyao/img/image-20220502111643372.png)

**Spring Boot与Spring Cloud**

- Spring Boot 是 Spring 的一套快速配置脚手架，可以基于Spring Boot 快速开发单个微服务;
- Spring Cloud是基于Spring Boot实现的；
- Spring Boot专注于快速、方便集成的单个微服务个体，Spring Cloud关注全局的服务治理框架；
- Spring Boot使用了约束优于配置的理念，很多集成方案已经帮你选择好了，能不配置就不配置 , Spring Cloud很大的一部分是基于Spring Boot来实现，Spring Boot可以离开Spring Cloud独立使用开发项目，但是Spring Cloud离不开Spring Boot，属于依赖的关系。
- SpringBoot在SpringClound中起到了承上启下的作用，如果你要学习SpringCloud必须要学习SpringBoot。



因为现在大多数公司都在使用springboot进行快速开发，学习springboot的前提，需要完全掌握spring和springmvc！承上启下的作用！



spring弊端：发展了太久，违背了原来的理念，配置十分繁琐，人称：“配置地狱”

# 2、IOC理论推导

新建一个空白的maven项目

我们先用我们原来的方式写一段代码

1. UserDao

   ```
   public interface UserDao {
       void addUser();
   }
   ```

2. UserDaoImpl

   ```java
   public class UserDaoImpl implements UserDao {
       @Override
       public void addUser() {
           System.out.println("添加一个用户");
       }
   }
   ```

3. UserService

   ```java
   public interface UserService {
       void addUser();
   }
   ```

4. UserServiceImpl

   ```java
   public class UserServiceImpl implements UserService {
   
       private UserDao userDao = new UserDaoOracleImpl();
   
       @Override
       public void addUser() {
           userDao.addUser();
       }
   }
   ```

5. 测试一下

   ```java
   public class UserServiceTest {
       
       @Test
       public void addUser() {
           UserService service = new UserServiceImpl();
           service.addUser();
       }
   }
   ```

现在我们修改一下，把Userdao的实现类增加一个

```java
public class UserDaoMySqlImpl implements UserDao {
    @Override
    public void addUser() {
        System.out.println("mysql新增一个用户");
    }
}
```

我们要使用mysql的话，就需要去service类里修改对应的实现

```java
public class UserServiceImpl implements UserService {

    private UserDao userDao = new UserDaoMySqlImpl();

    @Override
    public void addUser() {
        userDao.addUser();
    }
}
```

假设我们再新增一个Userdao的实现类

```java
public class UserDaoOracleImpl implements UserDao {
    @Override
    public void addUser() {
        System.out.println("oracle新增一个用户");
    }
}
```

使用oracle，又需要去service实现类里面修改对应的实现。假设我们的这种需求非常大 , 这种方式就根本不适用了, 甚至反人类对吧 , 每次变动 , 都需要修改大量代码 。 这种设计的耦合性太高了，牵一发而动全身。



那我们如何解决？

我们可以在需要用到他的地方 , 不去实现它 , 而是留出一个接口 , 利用set , 我们去代码里修改下 

```java
public class UserServiceImpl implements UserService {
    
    private UserDao userDao;

    public void setUserDao(UserDao userDao) {
        this.userDao = userDao;
    }

    @Override
    public void addUser() {
        userDao.addUser();
    }
}
```

测试

```java
public class UserServiceTest {

    @Test
    public void addUser() {
        UserServiceImpl service = new UserServiceImpl();
        service.setUserDao(new UserDaoMySqlImpl());
        service.addUser();
    }
}
```

这里发生了革命性个改变

- 之前，程序是主动创建对象，控制权在程序员手上

- 使用set注入之后，程序不再具有主动性，而是变成了被动接受的对象！

这种思想，从本质上解决了问题，我们程序员不用再去管理对象的创建了。系统的耦合性大大降低了，可以更加注重在业务上的实现，这是ioc的原型。

## 2.1、IOC本质

**控制反转IoC(Inversion of Control)，是一种设计思想，DI(依赖注入)是实现IoC的一种方法**，也有人认为DI只是IoC的另一种说法。没有IoC的程序中 , 我们使用面向对象编程 , 对象的创建与对象间的依赖关系完全硬编码在程序中，对象的创建由程序自己控制，控制反转后将对象的创建转移给第三方，个人认为所谓控制反转就是：获得依赖对象的方式反转了。

![图片](https://gitee.com/zhayuyao/img/raw/master/zhayuyao/img/640)

**IoC是Spring框架的核心内容**，使用多种方式完美的实现了IoC，可以使用XML配置，也可以使用注解，新版本的Spring也可以零配置实现IoC。

Spring容器在初始化时先读取配置文件，根据配置文件或元数据创建与组织对象存入容器中，程序使用时再从Ioc容器中取出需要的对象。

采用XML方式配置Bean的时候，Bean的定义信息是和实现分离的，而采用注解的方式可以把两者合为一体，Bean的定义信息直接以注解的形式定义在实现类中，从而达到了零配置的目的。

**控制反转是一种通过描述（XML或注解）并通过第三方去生产或获取特定对象的方式。在Spring中实现控制反转的是IoC容器，其实现方法是依赖注入（Dependency Injection,DI）。**

# 3、HelloSpring

1. 导包

   ```xml
           <!-- https://mvnrepository.com/artifact/org.springframework/spring-webmvc -->
           <dependency>
               <groupId>org.springframework</groupId>
               <artifactId>spring-webmvc</artifactId>
               <version>5.3.19</version>
           </dependency>
   ```

2. 编写代码

   ```java
   public class Hello {
       private String str;
   
       public String getStr() {
           return str;
       }
   
       public void setStr(String str) {
           this.str = str;
       }
   
       @Override
       public String toString() {
           return "Hello{" +
                   "str='" + str + '\'' +
                   '}';
       }
   }
   ```

3. 编写我们的spring文件，这里命名为beans.xml

   ```xml
   <?xml version="1.0" encoding="UTF-8"?>
   <beans xmlns="http://www.springframework.org/schema/beans"
          xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance"
          xsi:schemaLocation="http://www.springframework.org/schema/beans
           https://www.springframework.org/schema/beans/spring-beans.xsd">
   
       <!--
       bean就是java对象 , 由Spring创建和管理
       使用spring来创建对象，在spring这些都称为bean
       类型 变量名 = new 类();
       Hello helloSpring = new Hello();
   
       id = 变量名
       class = new 的对象
       property相当于给对象中属性设置一个值！
   
   
       -->
       <bean id="helloSpring" class="com.zyy.pojo.Hello">
           <property name="str" value="spring"/>
       </bean>
   
   </beans>
   ```

4. 测试

   ```java
   public class HelloTest {
       @Test
       public void test() {
           //解析beans.xml文件 , 生成管理相应的Bean对象
           ApplicationContext context = new ClassPathXmlApplicationContext("beans.xml");
           //getBean : 参数即为spring配置文件中bean的id .
           Hello helloSpring = (Hello) context.getBean("helloSpring");
           System.out.println(helloSpring);
       }
   }
   ```

   

思考：

- Hello 对象是谁创建的 ?

  hello 对象是由Spring创建的

- Hello 对象的属性是怎么设置的 ?

  hello 对象的属性是由Spring容器设置的

这个过程就叫控制反转：

- 控制：谁在控制对象的创建，传统的应用程序的对象是由程序本身控制创建的，使用spring后，对象由spring来创建
- 反转：程序本身不创建对象，而变成被动的接收对象

依赖注入：就是利用set方法来进行注入的

==IOC是一种编程思想，由主动的编程变成被动的接收==



修改一下一开始的案例

新增一个spring配置文件beans.xml

```xml
<?xml version="1.0" encoding="UTF-8"?>
<beans xmlns="http://www.springframework.org/schema/beans"
       xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance"
       xsi:schemaLocation="http://www.springframework.org/schema/beans
        https://www.springframework.org/schema/beans/spring-beans.xsd">

    <bean id="userDaoMySqlImpl" class="com.zyy.dao.UserDaoMySqlImpl">
    </bean>
    <bean id="userDaoOracleImpl" class="com.zyy.dao.UserDaoOracleImpl">
    </bean>

    <bean id="userServiceImpl" class="com.zyy.service.UserServiceImpl">
        <!-- 注意: 这里的name并不是属性 , 而是set方法后面的那部分 , 首字母小写 -->
        <!-- 引用另外一个bean , 不是用value 而是用 ref -->
        <property name="userDao" ref="userDaoOracleImpl"/>
    </bean>
</beans>
```

测试

```java
    @Test
    public void addUser2() {
        ApplicationContext context = new ClassPathXmlApplicationContext("beans.xml");
        UserServiceImpl service = (UserServiceImpl) context.getBean("userServiceImpl");
        service.addUser();
    }
```

**OK , 到了现在 , 我们彻底不用再程序中去改动了 , 要实现不同的操作 , 只需要在xml配置文件中进行修改 , 所谓的IoC,一句话搞定 : 对象由Spring 来创建 , 管理 , 装配 !** 

# 4、IOC创建对象方式

1. 使用无参构造创建对象，默认

   User.java

   ```java
   public class User {
       private String name;
   
       public User() {
           System.out.println("User无参构造方法");
       }
   
       public String getName() {
           return name;
       }
   
       public void setName(String name) {
           this.name = name;
       }
   
       public void show() {
           System.out.println("name=" + this.name);
       }
   }
   
   ```

   beans.xml

   ```xml
   <?xml version="1.0" encoding="UTF-8"?>
   <beans xmlns="http://www.springframework.org/schema/beans"
          xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance"
          xsi:schemaLocation="http://www.springframework.org/schema/beans
           https://www.springframework.org/schema/beans/spring-beans.xsd">
   
       <bean id="user" class="com.zyy.pojo.User">
           <property name="name" value="zyy"/>
       </bean>
   
   </beans>
   ```

   测试类

   ```java
   public class UserTest {
   
       @Test
       public void test() {
           ApplicationContext context = new ClassPathXmlApplicationContext("beans.xml");
           User user = (User) context.getBean("user");
           user.show();
       }
   }
   ```

   结果我们可以发现，在调用show()方法之前，User对象已经通过无参构造初始化了。

2. 假设我们要使用有参构造创建对象

   ```java
   public class User {
       private String name;
   
       public User(String name) {
           this.name = name;
           System.out.println("User构造方法给name赋值"+this.name);
       }
   
       public String getName() {
           return name;
       }
   
       public void setName(String name) {
           this.name = name;
       }
   
       public void show() {
           System.out.println("name=" + this.name);
       }
   }
   ```

   1. 下标赋值

      ```xml
          <bean id="user" class="com.zyy.pojo.User">
              <constructor-arg index="0" value="zyy02"/>
          </bean>
      ```

   2. 类型

      ```xml
          <!--    不推荐使用-->
          <bean id="user" class="com.zyy.pojo.User">
              <constructor-arg type="java.lang.String" value="zyy03"/>
          </bean>
      ```

   3. 参数名

      ```xml
          <bean id="user" class="com.zyy.pojo.User">
              <constructor-arg name="name" value="zyy04"/>
          </bean>
      ```

总结：在配置文件加载的时候，容器中管理的对象就已经初始化了。

# 5、spring配置

## 5.1、别名

```xml
    <bean id="user" class="com.zyy.pojo.User">
        <constructor-arg name="name" value="zyy04"/>
    </bean>
    <!--  别名，如果添加了别名，我们也可以使用别名获取到这个对象 -->
    <alias name="user" alias="userNew"/>
```



## 5.2、bean的配置

```xml
    <!--
     id：bean 的唯一标识符，也就是相当于我们学的对象名
     class：bean对象所对应的全限定名：包名+类型
     name：也是别名，而且name可以同时取多个别名
     -->
    <bean id="user" class="com.zyy.pojo.User" name="u1 u2,u3;u4">
        <constructor-arg name="name" value="zyy04"/>
    </bean>
```



## 5.3、import

这个import，一般用于团队开发，它可以将多个配置文件，导入合并为一个

假设，现在项目中有多个人开发，这三个人负责不同的类开发，不同的类需要注册在不同的bean中，我们可以利用import将所有的beans.xml合并为一个总的

- 张三

- 李四

- 王五

- applicationContext.xml

  ```xml
      <import resource="beans1.xml"/>
      <import resource="beans2.xml"/>
      <import resource="beans3.xml"/>
  ```

  



使用的时候，直接使用总的配置就可以了。