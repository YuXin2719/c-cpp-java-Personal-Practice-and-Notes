# 一、MyBatis 简介

**==！！建议搭配本笔记学习以下视频教程！！==**

【黑马mybatis教程全套视频教程，2天Mybatis框架从入门到精通】 https://www.bilibili.com/video/BV1MT4y1k7wZ/?share_source=copy_web&vd_source=d9edc224153cc08d2737066e5ff7b890



**什么是MyBatis？**

- MyBatis是一款优秀的==持久层框架==，用于简化JDBC开发
- MyBatis 本是 Apache 的一个开源项目iBatis，2010年这个项目由apache software foundation迁移到了google code，并且改名为MyBatis。2013年11月迁移到GitHub
- 官网：[MyBatis中文网](https://mybatis.net.cn/)



**持久层**

- 负责将数据保存到数据库的那一层代码
- JavaEE三层架构：表现层、业务层、**持久层**



**框架**

- 框架就是一个半成品软件，是一套可重用的、通用的、软件基础代码模型
- 在框架的基础之上构建软件编写会更加高效、规范、通用、可拓展



**JDBC缺点**

1. 硬编码   =>   配置文件
   - 注册驱动，获取连接
   - SQL语句

2. 操作繁琐   =>   自动完成
   - 手动设置参数
   - 手动封装结果集


<img src="photo/image-20241119123539133.png" alt="image-20241119123539133" style="zoom:50%;" />



**MyBatis免除了几乎所有的JDBC代码以及设置参数和获取结果集工作**

<img src="photo/image-20241119153628000.png" alt="image-20241119153628000" style="zoom:50%;" />

各种持久层框架中，MyBatis在国内的使用率占比最高



**本课程笔记学习大纲：**

- MyBatis 快速入门
- Mapper 代理开发
- MyBatis 核心配置文件
- 配置文件完成增删改查
- 注解完成增删改查
- 动态 SQL



# 二、MyBatis 快速入门

**查询user表中所有数据**

1. 创建user表，添加数据
2. 创建模块，导入坐标
3. 编写 MyBatis 核心配置文件 -- > 替换连接信息，解决硬编码问题
4. 编写 SQL 映射文件 -- > 统一管理sql语句，解决硬编码问题
5. 编码
   1. 定义POJO类
   2. 加载核心配置文件，获取 SqlSessionFactory 对象
   3. 获取 SqlSession 对象，执行 SQL 语句
   4. 释放资源



**在MySQL中创建MyBatis数据库，然后创建User表，添加数据**

用到的SQL代码为：

```sql
create database mybatis;
use mybatis;

drop table if exists tb_user;

create table tb_user(
	id int primary key auto_increment,
	username varchar(20),
	password varchar(20),
	gender char(1),
	addr varchar(30)
);

INSERT INTO tb_user VALUES (1, 'zhangsan', '123', '男', '北京');
INSERT INTO tb_user VALUES (2, '李四', '234', '女', '天津');
INSERT INTO tb_user VALUES (3, '王五', '11', '男', '西安');
```

我使用的是Navicat for MySQL软件管理数据库

成功创建后如图所示：

<img src="photo/image-20241119171942959.png" alt="image-20241119171942959" style="zoom:50%;" />



**创建项目，导入坐标**

pom.xml文件内容

**注意**：注意导入的各组件的版本号，仅针对以下版本号组件的测试用例可以成功运行，如果版本号过高或过低可能会出现组件冲突等意外情况。这里不做演示。我尝试了全部配置为最新版本的组件，日志内容无法正常显示，换回以下版本后正常，我估计是因为组件升级后有冲突，所以不建议随便选择组件版本。

```xml
<?xml version="1.0" encoding="UTF-8"?>
<project xmlns="http://maven.apache.org/POM/4.0.0"
         xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance"
         xsi:schemaLocation="http://maven.apache.org/POM/4.0.0 http://maven.apache.org/xsd/maven-4.0.0.xsd">
    <modelVersion>4.0.0</modelVersion>

    <groupId>org.example</groupId>
    <artifactId>MyBatis</artifactId>
    <version>1.0-SNAPSHOT</version>

    <properties>
        <maven.compiler.source>8</maven.compiler.source>
        <maven.compiler.target>8</maven.compiler.target>
        <project.build.sourceEncoding>UTF-8</project.build.sourceEncoding>
    </properties>

    <dependencies>
        <!--mybatis 依赖-->
        <dependency>
            <groupId>org.mybatis</groupId>
            <artifactId>mybatis</artifactId>
            <version>3.5.5</version>
        </dependency>
        <!--MySQL 驱动-->
        <dependency>
            <groupId>mysql</groupId>
            <artifactId>mysql-connector-java</artifactId>
            <version>8.0.33</version>
        </dependency>
        <!--Junit 单元测试-->
        <dependency>
            <groupId>junit</groupId>
            <artifactId>junit</artifactId>
            <version>4.13</version>
            <scope>test</scope>
        </dependency>
        <!-- 添加slf4j日志api -->
        <dependency>
            <groupId>org.slf4j</groupId>
            <artifactId>slf4j-api</artifactId>
            <version>1.7.20</version>
        </dependency>
        <!-- 添加logback-classic依赖 -->
        <dependency>
            <groupId>ch.qos.logback</groupId>
            <artifactId>logback-classic</artifactId>
            <version>1.2.3</version>
        </dependency>
        <!-- 添加logback-core依赖 -->
        <dependency>
            <groupId>ch.qos.logback</groupId>
            <artifactId>logback-core</artifactId>
            <version>1.2.3</version>
        </dependency>

    </dependencies>

</project>
```

记得将**Logback配置文件**放入：src/main/resources 下

logback.xml文件内容

```xml
<?xml version="1.0" encoding="UTF-8"?>
<configuration>
    <!--
        CONSOLE ：表示当前的日志信息是可以输出到控制台的。
    -->
    <appender name="Console" class="ch.qos.logback.core.ConsoleAppender">
        <encoder>
            <pattern>[%level] %blue(%d{HH:mm:ss.SSS}) %cyan([%thread]) %boldGreen(%logger{15}) - %msg %n</pattern>
        </encoder>
    </appender>

    <logger name="com.itheima" level="DEBUG" additivity="false">
        <appender-ref ref="Console"/>
    </logger>


    <!--

      level:用来设置打印级别，大小写无关：TRACE, DEBUG, INFO, WARN, ERROR, ALL 和 OFF
     ， 默认debug
      <root>可以包含零个或多个<appender-ref>元素，标识这个输出位置将会被本日志级别控制。
      -->
    <root level="DEBUG">
        <appender-ref ref="Console"/>
    </root>
</configuration>
```

mybatis-config.xml就是**MyBatis的核心配置文件**，放到src/main/resources文件夹中

mybatis-config.xml文件内容

```xml
<?xml version="1.0" encoding="UTF-8"?>
<!DOCTYPE configuration
        PUBLIC "-//mybatis.org//DTD Config 3.0//EN"
        "http://mybatis.org/dtd/mybatis-3-config.dtd">
<configuration>
    <environments default="development">
        <environment id="development">
            <transactionManager type="JDBC"/>
            <dataSource type="POOLED">
                <!--数据库连接信息-->
                <property name="driver" value="com.mysql.cj.jdbc.Driver"/>
                <property name="url" value="jdbc:mysql:///mybatis?useSSL=false"/>
                <property name="username" value="root"/>
                <property name="password" value="admin"/>
            </dataSource>
        </environment>
    </environments>
    <mappers>
        <!--加载sql映射文件-->
        <mapper resource="com/itheima/mapper/UserMapper.xml"/>
    </mappers>
</configuration>
```

UserMapper.xml是**Mapper配置文件**，放入src/main/resources

```xml
<?xml version="1.0" encoding="UTF-8" ?>
<!DOCTYPE mapper
        PUBLIC "-//mybatis.org//DTD Mapper 3.0//EN"
        "http://mybatis.org/dtd/mybatis-3-mapper.dtd">

<!--
    namespace:名称空间
-->
<mapper namespace="test">
    <select id="selectAll" resultType="com.itheima.pojo.User">
        select * from tb_user;
    </select>
</mapper>
```

**定义POJO类：User.java**

```java
package com.itheima.pojo;

public class User {

    //alt + 左键 : 整列编辑
    private Integer id;
    private String username;
    private String password;
    private String gender;
    private String addr;

    public Integer getId() {
        return id;
    }

    public void setId(Integer id) {
        this.id = id;
    }

    public String getUsername() {
        return username;
    }

    public void setUsername(String username) {
        this.username = username;
    }

    public String getPassword() {
        return password;
    }

    public void setPassword(String password) {
        this.password = password;
    }

    public String getGender() {
        return gender;
    }

    public void setGender(String gender) {
        this.gender = gender;
    }

    public String getAddr() {
        return addr;
    }

    public void setAddr(String addr) {
        this.addr = addr;
    }

    @Override
    public String toString() {
        return "User{" +
                "id=" + id +
                ", username='" + username + '\'' +
                ", password='" + password + '\'' +
                ", gender='" + gender + '\'' +
                ", addr='" + addr + '\'' +
                '}';
    }
}
```



**然后就可以编写测试类了**

```java
package com.itheima;

import org.apache.ibatis.io.Resources;
import org.apache.ibatis.session.SqlSession;
import org.apache.ibatis.session.SqlSessionFactory;
import org.apache.ibatis.session.SqlSessionFactoryBuilder;

import java.io.IOException;
import java.io.InputStream;
import java.util.List;

//TODO MyBatis快速入门代码
public class MyBatisDemo {
    public static void main(String[] args) throws IOException {
        //1.加载MyBatis的核心配置文件,获取 SqlSessionFactory
        String resource = "mybatis-config.xml";
        InputStream inputStream = Resources.getResourceAsStream(resource);
        SqlSessionFactory sqlSessionFactory = new SqlSessionFactoryBuilder().build(inputStream);

        //2.获取SqlSession对象,用它来执行sql
        SqlSession sqlSession=sqlSessionFactory.openSession();

        //3.执行sql
        List<Object> users = sqlSession.selectList("test.selectAll");

        System.out.println(users);

        //4.释放资源
        sqlSession.close();

    }
}
```



正确的输出结果：

```cmd
E:\JDK8\bin\java.exe "-javaagent:D:\IntelliJ IDEA Community Edition 2024.1\lib\idea_rt.jar=20643:D:\IntelliJ IDEA Community Edition 2024.1\bin" -Dfile.encoding=UTF-8 -classpath "E:\JDK8\jre\lib\charsets.jar;E:\JDK8\jre\lib\deploy.jar;E:\JDK8\jre\lib\ext\access-bridge-64.jar;E:\JDK8\jre\lib\ext\cldrdata.jar;E:\JDK8\jre\lib\ext\dnsns.jar;E:\JDK8\jre\lib\ext\jaccess.jar;E:\JDK8\jre\lib\ext\jfxrt.jar;E:\JDK8\jre\lib\ext\localedata.jar;E:\JDK8\jre\lib\ext\nashorn.jar;E:\JDK8\jre\lib\ext\sunec.jar;E:\JDK8\jre\lib\ext\sunjce_provider.jar;E:\JDK8\jre\lib\ext\sunmscapi.jar;E:\JDK8\jre\lib\ext\sunpkcs11.jar;E:\JDK8\jre\lib\ext\zipfs.jar;E:\JDK8\jre\lib\javaws.jar;E:\JDK8\jre\lib\jce.jar;E:\JDK8\jre\lib\jfr.jar;E:\JDK8\jre\lib\jfxswt.jar;E:\JDK8\jre\lib\jsse.jar;E:\JDK8\jre\lib\management-agent.jar;E:\JDK8\jre\lib\plugin.jar;E:\JDK8\jre\lib\resources.jar;E:\JDK8\jre\lib\rt.jar;E:\c.---c.---java-exercise\JavaCode\MyBatis\target\classes;E:\Maven Local repository\org\mybatis\mybatis\3.5.5\mybatis-3.5.5.jar;E:\Maven Local repository\mysql\mysql-connector-java\5.1.46\mysql-connector-java-5.1.46.jar;E:\Maven Local repository\org\slf4j\slf4j-api\1.7.20\slf4j-api-1.7.20.jar;E:\Maven Local repository\ch\qos\logback\logback-classic\1.2.3\logback-classic-1.2.3.jar;E:\Maven Local repository\ch\qos\logback\logback-core\1.2.3\logback-core-1.2.3.jar" com.itheima.MyBatisDemo
[DEBUG] 22:34:08.232 [main] o.a.i.l.LogFactory - Logging initialized using 'class org.apache.ibatis.logging.slf4j.Slf4jImpl' adapter. 
[DEBUG] 22:34:08.261 [main] o.a.i.d.p.PooledDataSource - PooledDataSource forcefully closed/removed all connections. 
[DEBUG] 22:34:08.261 [main] o.a.i.d.p.PooledDataSource - PooledDataSource forcefully closed/removed all connections. 
[DEBUG] 22:34:08.262 [main] o.a.i.d.p.PooledDataSource - PooledDataSource forcefully closed/removed all connections. 
[DEBUG] 22:34:08.262 [main] o.a.i.d.p.PooledDataSource - PooledDataSource forcefully closed/removed all connections. 
[DEBUG] 22:34:08.333 [main] o.a.i.t.j.JdbcTransaction - Opening JDBC Connection 
[DEBUG] 22:34:08.538 [main] o.a.i.d.p.PooledDataSource - Created connection 21257599. 
[DEBUG] 22:34:08.538 [main] o.a.i.t.j.JdbcTransaction - Setting autocommit to false on JDBC Connection [com.mysql.jdbc.JDBC4Connection@1445d7f] 
[DEBUG] 22:34:08.546 [main] test.selectAll - ==>  Preparing: select * from tb_user; 
[DEBUG] 22:34:08.569 [main] test.selectAll - ==> Parameters:  
[DEBUG] 22:34:08.581 [main] test.selectAll - <==      Total: 3 
[User{id=1, username='zhangsan', password='123', gender='男', addr='北京'}, User{id=2, username='李四', password='234', gender='女', addr='天津'}, User{id=3, username='王五', password='11', gender='男', addr='西安'}]
[DEBUG] 22:34:08.581 [main] o.a.i.t.j.JdbcTransaction - Resetting autocommit to true on JDBC Connection [com.mysql.jdbc.JDBC4Connection@1445d7f] 
[DEBUG] 22:34:08.582 [main] o.a.i.t.j.JdbcTransaction - Closing JDBC Connection [com.mysql.jdbc.JDBC4Connection@1445d7f] 
[DEBUG] 22:34:08.582 [main] o.a.i.d.p.PooledDataSource - Returned connection 21257599 to pool. 

进程已结束，退出代码为 0

```



# 三、Mapper 代理开发

Mappers：映射器

- 目的

  - 解决原生方式中的硬编码
  - 简化后期执行SQL

  <img src="photo/image-20241119224754963.png" alt="image-20241119224754963" style="zoom:50%;" />



**使用 Mapper 代理方式完成入门案例**

1. 定义与SQL映射文件同名的Mapper接口，并且将Mapper接口和SQL映射文件放置在同一目录下
2. 设置SQL映射文件的namespace属性为Mapper接口全限定名
3. 在 Mapper 接口中定义方法，方法名就是SQL映射文件中sql语句的id，并保持参数类型和返回值类型一致
4. 编码
   1. 通过 SqlSession 的 getMapper 方法获取 Mapper 接口的代理对象
   2. 调用对应方法完成sql的执行



1.resources目录下这么创建文件目录，然后把UserMapper放到com/itheima/mapper目录下就可以和UserMapper编译后的文件存在一个目录中了

<img src="photo/image-20241121105028660.png" alt="image-20241121105028660" style="zoom:50%;" />

效果如下

<img src="photo/image-20241121105238855.png" alt="image-20241121105238855" style="zoom:50%;" />



2.将UserMapper的配置文件的命名空间改成Mapper接口的全限定名

<img src="photo/image-20241121105519293.png" alt="image-20241121105519293" style="zoom:50%;" />



3.在Mapper接口中定义方法，方法名就是SQL映射文件中sql语句的id，上例中就是selectAll，并且保持参数类型和返回值类型一致

<img src="photo/image-20241121105923438.png" alt="image-20241121105923438" style="zoom:50%;" />



记得改一下mybatis-config配置文件中sql映射文件的路径

<img src="photo/image-20241121110110219.png" alt="image-20241121110110219" style="zoom:50%;" />



4.然后我们就可以开始编码了，我们在com.itheima包下整个MyBatisDemo2.java

```java
package com.itheima;

import com.itheima.mapper.UserMapper;
import com.itheima.pojo.User;
import org.apache.ibatis.io.Resources;
import org.apache.ibatis.session.SqlSession;
import org.apache.ibatis.session.SqlSessionFactory;
import org.apache.ibatis.session.SqlSessionFactoryBuilder;

import java.io.IOException;
import java.io.InputStream;
import java.util.List;

//TODO MyBatis代理开发
public class MyBatisDemo2 {
    public static void main(String[] args) throws IOException {
        //1.加载MyBatis的核心配置文件,获取 SqlSessionFactory
        String resource = "mybatis-config.xml";
        InputStream inputStream = Resources.getResourceAsStream(resource);
        SqlSessionFactory sqlSessionFactory = new SqlSessionFactoryBuilder().build(inputStream);

        //2.获取SqlSession对象,用它来执行sql
        SqlSession sqlSession=sqlSessionFactory.openSession();

        //3.执行sql
//        List<Object> users = sqlSession.selectList("test.selectAll");
        //3.1 获取UserMapper接口的代理对象
        UserMapper userMapper = sqlSession.getMapper(UserMapper.class);
        List<User> users = userMapper.selectAll();

        System.out.println(users);

        //4.释放资源
        sqlSession.close();

    }
}

```



**细节：如果Mapper接口名称和SQL映射文件名称相同，并在同一目录下，则可以使用包扫描的方式简化SQL映射文件的加载**

<img src="photo/image-20241119225430416.png" alt="image-20241119225430416" style="zoom:50%;" />

<img src="photo/image-20241121125345733.png" alt="image-20241121125345733" style="zoom:50%;" />

这样写系统会自动把com.itheima.mapper路径下的接口对应的xml配置文件全部一起扫描进来，就不用我们自己一个一个手动加载sql映射文件了



# 四、MyBatis 核心配置文件

MyBatis 核心配置文件详解

MyBatis 核心配置文件的顶层结构如下：

<img src="photo/image-20241121140807070.png" alt="image-20241121140807070" style="zoom: 50%;" />

- 类型别名（typeAliases）

  ```xml
  <typeAliases>
  	<package name="com.itheima.pojo"/>
  </typeAliases>
  ```

  配置好类型别名就意味着下图位置（结果类型）只需要写类名即可（不用区分大小写）

  <img src="photo/image-20241121141248358.png" alt="image-20241121141248358" style="zoom:50%;" />

  

  **细节：配置各个标签时，需要遵守前后顺序**



核心配置文件更新后：

```xml
<?xml version="1.0" encoding="UTF-8"?>
<!DOCTYPE configuration
        PUBLIC "-//mybatis.org//DTD Config 3.0//EN"
        "http://mybatis.org/dtd/mybatis-3-config.dtd">
<configuration>

    <typeAliases>
        <package name="com.itheima.pojo"/>
    </typeAliases>

    <!--
    enviroments : 配置数据库连接环境信息,可以配置多个enviroment,通过default属性切换不同的enviroment
    -->
    <environments default="development">
        <environment id="development">
            <!--事务的管理方式-->
            <transactionManager type="JDBC"/>
            <!--数据库连接池-->
            <dataSource type="POOLED">
                <!--数据库连接信息-->
                <property name="driver" value="com.mysql.cj.jdbc.Driver"/>
                <property name="url" value="jdbc:mysql:///mybatis?useSSL=false"/>
                <property name="username" value="root"/>
                <property name="password" value="admin"/>
            </dataSource>
        </environment>
    </environments>
    <mappers>
        <!--加载sql映射文件-->
        <!--        <mapper resource="com/itheima/mapper/UserMapper.xml"/>-->

        <!--Mapper代理方式-->
        <package name="com.itheima.mapper"/>
    </mappers>
</configuration>
```



# 五、配置文件完成增删改查

## 1.MyBatis 案例 - 环境准备

**完成品牌数据的增删改查操作**

产品原型样式：

<img src="photo/image-20241121215036432.png" alt="image-20241121215036432" style="zoom:50%;" />

- 要完成的功能列表清单：
  1. 查询
     - 查询所有数据
     - 查看详情
     - 条件查询
  2. 添加
  3. 修改
     - 修改全部字段
     - 修改动态字段
  4. 删除
     - 删除一个
     - 批量删除



**准备环境**

- 数据库表 tb-brand
- 实体类 Brand
- 测试用例
- 安装 MyBatisX 插件



1.导入数据库表

```sql
-- 删除tb_brand表
drop table if exists tb_brand;
-- 创建tb_brand表
create table tb_brand
(
    -- id 主键
    id           int primary key auto_increment,
    -- 品牌名称
    brand_name   varchar(20),
    -- 企业名称
    company_name varchar(20),
    -- 排序字段
    ordered      int,
    -- 描述信息
    description  varchar(100),
    -- 状态：0：禁用  1：启用
    status       int
);
-- 添加数据
insert into tb_brand (brand_name, company_name, ordered, description, status)
values ('三只松鼠', '三只松鼠股份有限公司', 5, '好吃不上火', 0),
       ('华为', '华为技术有限公司', 100, '华为致力于把数字世界带入每个人、每个家庭、每个组织，构建万物互联的智能世界', 1),
       ('小米', '小米科技有限公司', 50, 'are you ok', 1);


SELECT * FROM tb_brand;
```

<img src="photo/image-20241121220130885.png" alt="image-20241121220130885" style="zoom:50%;" />



2.准备实体类 Brand，放入项目的pojo包中

```java
package com.itheima.pojo;

/**
 * 品牌
 *
 * alt + 鼠标左键：整列编辑
 *
 * 在实体类中，基本数据类型建议使用其对应的包装类型
 */

public class Brand {
    // id 主键
    private Integer id;
    // 品牌名称
    private String brandName;
    // 企业名称
    private String companyName;
    // 排序字段
    private Integer ordered;
    // 描述信息
    private String description;
    // 状态：0：禁用  1：启用
    private Integer status;


    public Integer getId() {
        return id;
    }

    public void setId(Integer id) {
        this.id = id;
    }

    public String getBrandName() {
        return brandName;
    }

    public void setBrandName(String brandName) {
        this.brandName = brandName;
    }

    public String getCompanyName() {
        return companyName;
    }

    public void setCompanyName(String companyName) {
        this.companyName = companyName;
    }

    public Integer getOrdered() {
        return ordered;
    }

    public void setOrdered(Integer ordered) {
        this.ordered = ordered;
    }

    public String getDescription() {
        return description;
    }

    public void setDescription(String description) {
        this.description = description;
    }

    public Integer getStatus() {
        return status;
    }

    public void setStatus(Integer status) {
        this.status = status;
    }

    @Override
    public String toString() {
        return "Brand{" +
                "id=" + id +
                ", brandName='" + brandName + '\'' +
                ", companyName='" + companyName + '\'' +
                ", ordered=" + ordered +
                ", description='" + description + '\'' +
                ", status=" + status +
                '}';
    }
}

```



3.写一个测试用例

<img src="photo/image-20241121224204699.png" alt="image-20241121224204699" style="zoom:50%;" />



4.安装 **MyBatisX 插件**

- **MyBatisX **是一款基于 IDEA 的快速开发插件，为**效率**而生

- 主要功能：

  - XML 和 接口方法 相互跳转
  - 根据接口方法生成 statement

- 安装：

  <img src="photo/image-20241121223314473.png" alt="image-20241121223314473" style="zoom:50%;" />



## 2.查询 - 查询所有&结果映射

**查询 - 查询所有数据**

<img src="photo/image-20241121224538486.png" alt="image-20241121224538486" style="zoom:50%;" />

1. 编写接口方法：Mapper接口

   ```java
   List<Brand> selectAll();
   ```

   - 参数：无
   - 结果：List\<Brand>

2. 编写SQL语句：

   SQL映射文件：

   ```xml
   <select id="selectAll" resultType="brand">
   	select * from tb_brand;
   </select>
   ```

3. 执行方法，编写测试用例

   注意存放位置

   <img src="photo/image-20241122091823194.png" alt="image-20241122091823194" style="zoom:50%;" />

   ```java
   package com.itheima.test;
   
   import com.itheima.mapper.BrandMapper;
   import com.itheima.pojo.Brand;
   import org.apache.ibatis.io.Resources;
   import org.apache.ibatis.session.SqlSession;
   import org.apache.ibatis.session.SqlSessionFactory;
   import org.apache.ibatis.session.SqlSessionFactoryBuilder;
   import org.junit.Test;
   
   import java.io.IOException;
   import java.io.InputStream;
   import java.util.List;
   
   public class MyBatisTest {
   
       @Test
       public void testSelectAll() throws Exception {
           //1.获取SqlSessionFactory,加载MyBatis的核心配置文件
           String resource = "mybatis-config.xml";
           InputStream inputStream = Resources.getResourceAsStream(resource);
           SqlSessionFactory sqlSessionFactory = new SqlSessionFactoryBuilder().build(inputStream);
   
           //2.获取SqlSession对象
           SqlSession sqlSession = sqlSessionFactory.openSession();
   
           //3.获取Mapper接口的代理对象
           BrandMapper brandMapper = sqlSession.getMapper(BrandMapper.class);
   
           //4.执行方法
           List<Brand> brands = brandMapper.selectAll();
           System.out.println(brands);
   
           //5.释放资源
           sqlSession.close();
   
       }
   }
   
   ```



**总结：MyBatis完成操作需要几步？**

==三步：编写接口方法 -> 编写SQL -> 执行方法==



**小问题：数据库表的字段名称 和 实体类的属性名称 不一样，则不能自动封装数据**，按刚才的BrandMapper文件brand_name和brandName无法对应上，最后结果查询不出来，我们该如何解决？

<img src="photo/image-20241122110527959.png" alt="image-20241122110527959" style="zoom:50%;" />

解决方法如下：

1. **起别名**：在SQL语句中，对不一样的列名起别名，别名和实体类属性名一样，* 可以定义\<sql>片段，提升复用性
2. **resultMap**：定义\<resultMap>完成不一致的属性名和列名的映射

示例BrandMapper.xml配置文件：

```xml
<?xml version="1.0" encoding="UTF-8" ?>
<!DOCTYPE mapper
        PUBLIC "-//mybatis.org//DTD Mapper 3.0//EN"
        "http://mybatis.org/dtd/mybatis-3-mapper.dtd">

<!--
    namespace:名称空间
-->
<mapper namespace="com.itheima.mapper.BrandMapper">

    <!--
    数据库表的字段名称 和 实体类的属性名称 不一样,则不能自动封装数据
        * 起别名 : 对不一样的列名起别名,让别名和实体类的属性名一样
            * 缺点 : 每次查询都要定义一次别名
                * 使用 sql片段 解决问题
                    *缺点 : 不灵活
        * resultMap:
            1.定义<resultMap>标签
            2.在<select>标签中,使用resultMap属性替换resultType属性
    -->
    <!--
    id:唯一标识
    type:映射的类型,支持别名
    -->
    <!--自动完成别名映射-->
    <resultMap id="brandResultMap" type="brand">
        <!--
        id:完成主键字段的映射
            column:表的列名
            property:实体类的属性名
        result:完成一般字段的映射
            column:表的列名
            property:实体类的属性名
        -->
        <result column="brand_name" property="brandName"/>
        <result column="company_name" property="companyName"/>
    </resultMap>

    <select id="selectAll" resultMap="brandResultMap">
        select * from tb_brand;
    </select>

    <!--
        sql片段
    -->
    <!--    <sql id="brand_column">-->
    <!--        id,brand_name as brandName,company_name as companyName,ordered,description,status-->
    <!--    </sql>-->

    <!--    <select id="selectAll" resultType="brand">-->
    <!--        select-->
    <!--        <include refid="brand_column"/>-->
    <!--        from tb_brand;-->
    <!--    </select>-->

    <!--    <select id="selectAll" resultType="brand">-->
    <!--        select * from tb_brand;-->
    <!--    </select>-->

</mapper>
```



## 3.查询 - 查看详情

**查询 - 查看详情**

<img src="photo/image-20241122113719235.png" alt="image-20241122113719235" style="zoom:50%;" />

1. 编写接口方法：Mapper接口

   ```java
   Brand selectById(int id);
   ```

   - 参数：id
   - 结果：Brand

2. 编写SQL语句：SQL映射文件

   ```xml
   <select id="selectById" parameterType="int" resultType="brand">
   	select * from tb_brand where id=#{id};
   </select>
   ```

3. 执行方法，测试



配置文件代码：

```xml
    <!--
    * 参数占位符:
        1.#{}:会将其替换为 ?,为了防止SQL注入
        2.${}:直接拼接SQL,会存在SQL注入问题
                TODO 所以最好使用 #{}
        3.使用时机:
            * 参数传递的时候:#{}
            * 表名或者列名不固定的情况下:${} (不常用)

    * 参数类型: parameterType:可以省略(一般也没人写)
    * 特殊字符的处理:
        1.转义字符:需要替换的符号比较少的时候可以用,例如 < 就需要替换成 &lt;
        2.CDATA区:如下演示,当替换的字符较多时,全部放到CDATA区就可以了
    -->
    <!--    <select id="selectByIdBrand" resultMap="brandResultMap">-->
    <!--        select * from tb_brand where id=#{id};-->
    <!--    </select>-->

    <select id="selectByIdBrand" resultMap="brandResultMap">
        select * from tb_brand where id
        <![CDATA[
            <
        ]]>
        #{id};
    </select>
```



测试代码：

```java
    @Test
    public void testSelectById() throws Exception {
        //接收参数
        int id=1;

        //1.获取SqlSessionFactory,加载MyBatis的核心配置文件
        String resource = "mybatis-config.xml";
        InputStream inputStream = Resources.getResourceAsStream(resource);
        SqlSessionFactory sqlSessionFactory = new SqlSessionFactoryBuilder().build(inputStream);

        //2.获取SqlSession对象
        SqlSession sqlSession = sqlSessionFactory.openSession();

        //3.获取Mapper接口的代理对象
        BrandMapper brandMapper = sqlSession.getMapper(BrandMapper.class);

        //4.执行方法
        Brand brand = brandMapper.selectByIdBrand(id);
        System.out.println(brand);

        //5.释放资源
        sqlSession.close();

    }
```



**总结：**

1. 参数占位符
   1. **#{}**：执行SQL时，会将#{}占位符替换为？，将来自动设置参数值
   2. **${}**：拼接SQL语句时使用，会存在SQL注入问题
   3. 使用时机：
      - 参数传递，都使用#{}
      - 如果要对表名、列名进行动态设置，只能使用${}进行sql拼接
2. parameterType：
   - 用于设置参数类型，该参数可以省略
3. SQL语句中特殊字符的处理：
   - 转义字符
   - \<![CDATA[ 内容 ]]>



## 4.查询 - 条件查询

**查询 - 多条件查询**

<img src="photo/image-20241122123307070.png" alt="image-20241122123307070" style="zoom:50%;" />

1. 编写接口方法：Mapper接口

   - 参数：所有查询条件
   - 结果List\<Brand>

   接收参数有三种不同的方式

   ```java
   List<Brand> selectByCondition(@Param("status")int status,@Param("companyName")String companyName,@Param("brandName")String brandName);
   
   List<Brand> selectByCondition(Brand brand);
   
   List<Brand> selectByCondition(Map map);
   ```

2. 编写SQL语句：SQL映射文件

   ```xml
   <select id="selectByCondition" resultMap="brandResultMap">
       select *
       from tb_brand
       where
       	status = #{status}
       	and company_name like #{companyName}
       	and brand_name like #{brandName}
   </select>
   ```

3. 执行方法，测试



**查询 - 多条件 - 动态条件查询**

- SQL语句会随着用户的输入或者外部条件的变化而变化，我们称之为 **动态SQL**

  ```xml
  <select id="selectByCondition" resultMap="brandResultMap">
  	select *
  	from tb_brand
  	where
  	status = #{status}
  	and company_name like #{companyName}
  	and brand_name like #{brandName}
  </select>
  ```

- MyBatis 对动态SQL有很强大的支撑：

  - if
  - choose(when,otherwise)
  - trim(where,set)
  - foreach



**查询 - 单条件 - 动态条件查询**

<img src="photo/image-20241122123903712.png" alt="image-20241122123903712" style="zoom:50%;" />

- 从多个条件中选择一个

  - choose(when,otherwise)：选择，类似于 Java 中的 switch 语句

    ```xml
    <select id="selectByConditionSingle" resultMap="brandResultMap">
        select *
        from tb_brand
        where
        <choose><!--类似于switch-->
            <when test="status != null"><!--类似于case-->
                status=#{status}
            </when>
            <when test="companyName != null and companyName != ''">
                company_name like #{companyName}
            </when>
            <when test="brandName != null and brandName != ''">
                brand_name like #{brandName}
            </when>
            <otherwise><!--类似于default-->
                1 = 1
            </otherwise>
        </choose>
    </select>
    ```



### ① 多条件查询

我们先分析一下需要关注和完成的SQL任务：

1. 条件表达式
   - status = ？
   - company_name like ？
   - brand_name like ?
2. 条件之间该如何连接
   - and 连接
   - select * from tb_brand where 开头



**散装参数接收方式：**

BrandMapper.xml 配置文件相关内容

```xml
    <!--
    条件查询
    -->
    <select id="selectByCondition" resultMap="brandResultMap">
        select *
        from tb_brand
        where
        status = #{status}
        and company_name like #{companyName}
        and brand_name like #{brandName}
    </select>
```



BrandMapper.java 接口文件相关内容

```java
    //TODO 条件查询
    //  参数接收
    //      1.散装参数：如果这个方法中有多个参数,需要使用@Param("SQL参数占位符名称")
    //      2.对象参数
    //      3.map集合参数
    List<Brand> selectByCondition(@Param("status") int status, @Param("companyName")String companyName, @Param("brandName")String brandName);

//    List<Brand> selectByCondition(Brand brand);

//    List<Brand> selectByCondition(Map map);
```



MyBatisTest.java 测试文件相关内容

```java
    @Test
    public void testSelectByCondition() throws Exception {
        //接收参数
        int status = 1;
        String companyName = "华为";
        String brandName = "华为";

        //处理参数
        companyName = "%" + companyName + "%";
        brandName = "%" + brandName + "%";

        //1.获取SqlSessionFactory,加载MyBatis的核心配置文件
        String resource = "mybatis-config.xml";
        InputStream inputStream = Resources.getResourceAsStream(resource);
        SqlSessionFactory sqlSessionFactory = new SqlSessionFactoryBuilder().build(inputStream);

        //2.获取SqlSession对象
        SqlSession sqlSession = sqlSessionFactory.openSession();

        //3.获取Mapper接口的代理对象
        BrandMapper brandMapper = sqlSession.getMapper(BrandMapper.class);

        //4.执行方法
        List<Brand> brands = brandMapper.selectByCondition(status, companyName, brandName);
        System.out.println(brands);

        //5.释放资源
        sqlSession.close();

    }
```



**对象参数接收方式：**

BrandMapper.java 接口文件相关内容

```java
    //TODO 条件查询
    //  参数接收
    //      1.散装参数 : 如果这个方法中有多个参数,需要使用@Param("SQL参数占位符名称")
    //      2.对象参数 : 对象的属性名称要和参数占位符名称一致
    //      3.map集合参数
//    List<Brand> selectByCondition(@Param("status") int status, @Param("companyName")String companyName, @Param("brandName")String brandName);

    List<Brand> selectByCondition(Brand brand);

//    List<Brand> selectByCondition(Map map);
```



MyBatisTest.java 测试文件相关内容

要点：封装对象

```java
    @Test
    public void testSelectByCondition() throws Exception {
        //接收参数
        int status = 1;
        String companyName = "华为";
        String brandName = "华为";

        //处理参数
        companyName = "%" + companyName + "%";
        brandName = "%" + brandName + "%";

        //封装对象
        Brand brand=new Brand();
        brand.setStatus(status);
        brand.setCompanyName(companyName);
        brand.setBrandName(brandName);

        //1.获取SqlSessionFactory,加载MyBatis的核心配置文件
        String resource = "mybatis-config.xml";
        InputStream inputStream = Resources.getResourceAsStream(resource);
        SqlSessionFactory sqlSessionFactory = new SqlSessionFactoryBuilder().build(inputStream);

        //2.获取SqlSession对象
        SqlSession sqlSession = sqlSessionFactory.openSession();

        //3.获取Mapper接口的代理对象
        BrandMapper brandMapper = sqlSession.getMapper(BrandMapper.class);

        //4.执行方法
//        List<Brand> brands = brandMapper.selectByCondition(status, companyName, brandName);
        List<Brand> brands = brandMapper.selectByCondition(brand);
        System.out.println(brands);

        //5.释放资源
        sqlSession.close();

    }
```



**Map集合参数接收方式：**

BrandMapper.java 接口文件相关内容

```java
    //TODO 条件查询
    //  参数接收
    //      1.散装参数 : 如果这个方法中有多个参数,需要使用@Param("SQL参数占位符名称")
    //      2.对象参数 : 对象的属性名称要和参数占位符名称一致
    //      3.map集合参数
//    List<Brand> selectByCondition(@Param("status") int status, @Param("companyName")String companyName, @Param("brandName")String brandName);

//    List<Brand> selectByCondition(Brand brand);

    List<Brand> selectByCondition(Map map);
```



MyBatisTest.java 测试文件相关内容

重点：封装对象

```java
    @Test
    public void testSelectByCondition() throws Exception {
        //接收参数
        int status = 1;
        String companyName = "华为";
        String brandName = "华为";

        //处理参数
        companyName = "%" + companyName + "%";
        brandName = "%" + brandName + "%";

        //封装对象
//        Brand brand=new Brand();
//        brand.setStatus(status);
//        brand.setCompanyName(companyName);
//        brand.setBrandName(brandName);

        Map map = new HashMap();
        map.put("status", status);
        map.put("companyName", companyName);
        map.put("brandName", brandName);

        //1.获取SqlSessionFactory,加载MyBatis的核心配置文件
        String resource = "mybatis-config.xml";
        InputStream inputStream = Resources.getResourceAsStream(resource);
        SqlSessionFactory sqlSessionFactory = new SqlSessionFactoryBuilder().build(inputStream);

        //2.获取SqlSession对象
        SqlSession sqlSession = sqlSessionFactory.openSession();

        //3.获取Mapper接口的代理对象
        BrandMapper brandMapper = sqlSession.getMapper(BrandMapper.class);

        //4.执行方法
//        List<Brand> brands = brandMapper.selectByCondition(status, companyName, brandName);
//        List<Brand> brands = brandMapper.selectByCondition(brand);
        List<Brand> brands = brandMapper.selectByCondition(map);
        System.out.println(brands);

        //5.释放资源
        sqlSession.close();

    }
```



**总结：SQL语句中有多个参数有几种方式？**

1. **散装参数：**需要使用@Param("SQL中的参数占位符名称")
2. **实体类封装参数：**只需要保证SQL中的参数名 和 实体类属性名对应上，即可设置成功
3. **map集合：**只需要保证SQL中的参数名 和 map集合的键的名称对应上，即可设置成功



### ② 动态条件查询

思考：用户输入条件时，是否所有条件都会填写？

**查询 - 多条件 - 动态条件查询**

- SQL语句会随着用户的输入或外部条件的变化而变化，我们称之为 **动态SQL**

  ```xml
  <select id="selectByCondition" resultMap="brandResultMap">
  	select *
      from tb_brand
      where
      	if(status != null)
      		status = #{status}
      	and company_name like #{companyName}
      	and brand_name like #{brandName}
  </select>
  ```

- MyBatis 对动态SQL有很强大的支撑

  - if
  - choose(when,otherwise)
  - trim(where,set)
  - foreach



BrandMapper.xml 配置文件相关内容

```xml
    <!--
    动态条件查询
        * if : 条件判断
            * test : 逻辑表达式
        * 问题 :
            * 恒等式
            * MyBatis提供的where标签 <where> 替换 where 关键字
    -->
    <select id="selectByCondition" resultMap="brandResultMap">
        select *
        from tb_brand
        <!--where 1=1-->
        <where>
            <if test="status != null">
                and status = #{status}
            </if>
            <if test="companyName != null and companyName != ''">
                and company_name like #{companyName}
            </if>
            <if test="brandName != null and brandName != ''">
                and brand_name like #{brandName}
            </if>
        </where>

    </select>
```



**总结：动态SQL**

**if**：用于判断参数是否有值，使用test属性进行条件判断

- 存在的问题：第一个条件不需要逻辑判断符
- 解决方案：
  1. 使用恒等式让所有条件格式都一样
  2. **\<where>**便签替换 where 关键字



**查询 - 单条件 - 动态条件查询**

- 从多个条件中选择一个
  - choose(when,otherwise)：选择，类似于 Java 中的 switch 语句

<img src="photo/image-20241126112804539.png" alt="image-20241126112804539" style="zoom:50%;" />

```xml
<select id="selectConditionSingle" resultMap="brandResultMap">
	select *
    from tb_band
    where
    <choose> <!--类似于switch-->
        <when test="status != null"> <!--类似于case-->
            status = #{status}
        </when>
        <when test="companyName != null and companyName != ''">
        	company_name like #{companyName}
        </when>
        <when test="brandName != null and brandName != ''">
        	brand_name like #{brandName}
        </when>
        <otherwise> <!--类似于default-->
        	1 = 1
        </otherwise>
    </choose>
</select>
```

或者使用 where 标签包括起来

```xml
    <select id="selectByConditionSingle" resultMap="brandResultMap">
        select *
        from tb_brand
        <where>
            <choose> <!--相当于switch-->
                <when test="status != null"> <!--相当于case-->
                    status = #{status}
                </when>
                <when test="companyName != null and companyName != ''">
                    company_name like #{companyName}
                </when>
                <when test="brandName != null and brandName != ''">
                    brand_name like #{brandName}
                </when>
            </choose>
        </where>
    </select>
```



测试代码：

```java
    @Test
    public void testSelectByConditionSingle() throws Exception {
        //接收参数
        int status = 1;
        String companyName = "华为";
        String brandName = "华为";

        //处理参数
        companyName = "%" + companyName + "%";
        brandName = "%" + brandName + "%";

        //封装对象
        Brand brand=new Brand();
//        brand.setStatus(status);
//        brand.setCompanyName(companyName);
//        brand.setBrandName(brandName);

        //1.获取SqlSessionFactory,加载MyBatis的核心配置文件
        String resource = "mybatis-config.xml";
        InputStream inputStream = Resources.getResourceAsStream(resource);
        SqlSessionFactory sqlSessionFactory = new SqlSessionFactoryBuilder().build(inputStream);

        //2.获取SqlSession对象
        SqlSession sqlSession = sqlSessionFactory.openSession();

        //3.获取Mapper接口的代理对象
        BrandMapper brandMapper = sqlSession.getMapper(BrandMapper.class);

        //4.执行方法
//        List<Brand> brands = brandMapper.selectByCondition(status, companyName, brandName);
//        List<Brand> brands = brandMapper.selectByCondition(brand);

        List<Brand> brands = brandMapper.selectByConditionSingle(brand);
        System.out.println(brands);

        //5.释放资源
        sqlSession.close();

    }
```



## 5.添加 & 修改功能

### ① 添加

<img src="photo/image-20241126201224550.png" alt="image-20241126201224550" style="zoom:50%;" />

1. 编写接口方法：Mapper接口

   ```java
   void add(Brand brand);
   ```

   - 参数：除了id之外的所有数据
   - 结果：void

2. 编写SQL语句：SQL映射文件

   ```xml
   <insert id="add">
   	insert into tb_brand(brand_name,company_name,ordered,description,status)
       values (#{brandName},#{companyName},#{ordered},#{description},#{status});
   </insert>
   ```

3. 执行方法，测试

   - MyBatis事务：
     - openSession()：默认开启事务，进行增删改操作后需要使用 sqlSession.commit(); 手动提交事务
     - openSession(true):可以设置为自动提交事务（关闭事务）



### ② 添加 - 主键返回

<img src="photo/image-20241126215702309.png" alt="image-20241126215702309" style="zoom:50%;" />

在数据添加成功后，需要获取插入数据库数据的主键

- 比如： 添加订单和订单项

  1. 添加订单

  2. 添加订单项，订单项中需要设置所属订单的id

     ```xml
     <insert id="addOrder" useGeneratedKeys="true" keyProperty="id">
     	insert into tb_order (payment,payment_type,status)
         values (#{payment},#{paymentType},#{status})
     </insert>
     ```

     ```xml
     <insert id="addOrderItem">
     	insert into tb_order_item (goods_name,goods_price,count,order_id)
         values (#{goodName},#{goodsPrice},#{count},#{orderId});
     </insert>
     ```



测试代码：

```java
    @Test
    public void testAdd() throws Exception {
        //接收参数
        int status = 1;
        String companyName = "波导手机";
        String brandName = "波导";
        String description ="手机中的战斗机";
        int ordered=100;

        //封装对象
        Brand brand=new Brand();
        brand.setStatus(status);
        brand.setCompanyName(companyName);
        brand.setBrandName(brandName);
        brand.setDescription(description);
        brand.setOrdered(ordered);

        //1.获取SqlSessionFactory,加载MyBatis的核心配置文件
        String resource = "mybatis-config.xml";
        InputStream inputStream = Resources.getResourceAsStream(resource);
        SqlSessionFactory sqlSessionFactory = new SqlSessionFactoryBuilder().build(inputStream);

        //2.获取SqlSession对象
//        SqlSession sqlSession = sqlSessionFactory.openSession();
        SqlSession sqlSession = sqlSessionFactory.openSession(true); //传参:true是自动提交事务,false是手动提交事务

        //3.获取Mapper接口的代理对象
        BrandMapper brandMapper = sqlSession.getMapper(BrandMapper.class);

        //4.执行方法
        brandMapper.add(brand);

        //手动提交事务
//        sqlSession.commit();

        //5.释放资源
        sqlSession.close();

    }
```



**主键返回总结：返回添加数据的主键**

需要在BrandMapper.xml配置文件中配置参数

```xml
<insert useGeneratedKeys="true" keyProperty="id">
```

1. useGeneratedKeys：用于返回自动生成的主键值
2. keyProperty：将自动生成的主键赋值给对象的某个属性

完整配置代码如下：

```xml
    <insert id="add" useGeneratedKeys="true" keyProperty="id">
        insert into tb_brand (brand_name,company_name,ordered,description,status)
        values(#{brandName},#{companyName},#{ordered},#{description},#{status});
    </insert>
```



### ③ 修改 - 修改全部字段

<img src="photo/image-20241128194029056.png" alt="image-20241128194029056" style="zoom:50%;" />

1. 编写接口方法：Mapper接口

   - 参数：所有数据
   - 结果：void

   ```java
   void update(Brand brand);
   ```

2. 编写 SQL 语句：SQL映射文件

   ```xml
   <update id="update">
   	update tb_brand
       set brand_name = #{brandName},
       	company_name = #{companyName},
       	ordered = #{ordered},
       	description = #{description},
       	status = #{status}
       where id = #{id};
   </update>
   ```

3. 执行方法，测试



测试代码：

```java
    @Test
    public void testUpdate() throws Exception {
        //接收参数
        int status = 1;
        String companyName = "波导手机";
        String brandName = "波导";
        String description ="波导手机,手机中的战斗机";
        int ordered=200;
        int id=11;

        //封装对象
        Brand brand=new Brand();
        brand.setStatus(status);
        brand.setCompanyName(companyName);
        brand.setBrandName(brandName);
        brand.setDescription(description);
        brand.setOrdered(ordered);
        brand.setId(id);

        //1.获取SqlSessionFactory,加载MyBatis的核心配置文件
        String resource = "mybatis-config.xml";
        InputStream inputStream = Resources.getResourceAsStream(resource);
        SqlSessionFactory sqlSessionFactory = new SqlSessionFactoryBuilder().build(inputStream);

        //2.获取SqlSession对象
//        SqlSession sqlSession = sqlSessionFactory.openSession();
        SqlSession sqlSession = sqlSessionFactory.openSession(true); //传参:true是自动提交事务,false是手动提交事务

        //3.获取Mapper接口的代理对象
        BrandMapper brandMapper = sqlSession.getMapper(BrandMapper.class);

        //4.执行方法
        int count = brandMapper.update(brand);
        System.out.println(count);

        //手动提交事务
//        sqlSession.commit();

        //5.释放资源
        sqlSession.close();

    }
```



### ④ 修改 - 修改动态字段

<img src="photo/image-20241128195608336.png" alt="image-20241128195608336" style="zoom:50%;" />

1. 编写接口方法：Mapper接口

   - 参数：部分数据，封装到对象中
   - 结果：void

2. 编写 SQL 语句：SQL映射文件

   如果想修改密码，但是SQL语句如下的话，最后只传入了password一个值，其他的值就会被设置为null了，很不合适

   ```xml
   <update id="update">
   	update tb_brand
       set username = #{username},
       	password = #{password},
       	gender = #{gender},
       	addr = #{addr}
       where
       	id = #{id};
   </update>
   ```

   动态的修改资料：

   ```xml
   <update id="update">
   	update tb_brand
       <set>
       	<if test="brandName != null and brandName != ''">
           brand_name = #{brandName},
           </if>
           <if test="companyName != null and companyName != ''">
           company_name = #{companyName},
           </if>
           <if test="ordered != null">
           ordered = #{ordered},
           </if>
           <if test="description != null and description != ''">
           description = #{description},
           </if>
           <if test="status != null">
           status = #{status},
           </if>
       </set>
       where id =#{id};
   </update>
   ```

3. 执行方法，测试，测试方法同上



## 6.删除

### ① 删除一个

<img src="photo/image-20241128202531418.png" alt="image-20241128202531418" style="zoom:50%;" />

1. 编写接口方法：Mapper接口

   - 参数：id
   - 结果：void

   ```java
   void deleteById(int id);
   ```

2. 编写 SQL 语句：SQL映射文件

   ```xml
   <delete id="deleteById">
   	delete from tb_brand where id = #{id};
   </delete>
   ```

3. 执行方法，测试



测试代码：

```java
    @Test
    public void testDeleteById() throws Exception {
        //接收参数
        int id=11;

        //1.获取SqlSessionFactory,加载MyBatis的核心配置文件
        String resource = "mybatis-config.xml";
        InputStream inputStream = Resources.getResourceAsStream(resource);
        SqlSessionFactory sqlSessionFactory = new SqlSessionFactoryBuilder().build(inputStream);

        //2.获取SqlSession对象
//        SqlSession sqlSession = sqlSessionFactory.openSession();
        SqlSession sqlSession = sqlSessionFactory.openSession(true); //传参:true是自动提交事务,false是手动提交事务

        //3.获取Mapper接口的代理对象
        BrandMapper brandMapper = sqlSession.getMapper(BrandMapper.class);

        //4.执行方法
        brandMapper.deleteById(id);

        //手动提交事务
//        sqlSession.commit();

        //5.释放资源
        sqlSession.close();

    }
```



### ② 批量删除

<img src="photo/image-20241128203325124.png" alt="image-20241128203325124" style="zoom:50%;" />

1. 编写接口方法：Mapper接口

   - 参数：id数组
   - 结果：void

   ```java
   void deleteByIds(@Param("ids") int[] ids);
   ```

2. 编写 SQL 语句：SQL映射文件

   以下写法的问号无法确定数量，所以该写法并不合适

   ```xml
   <delete id="deleteByIds">
   	delete from tb_brand
       where id in (?,?,?)
   </delete>
   ```

   ```xml
   <delete id="deleteByIds">
   	delete from tb_brand
       where id in
       <foreach collection="ids" item="id" separator="," open="(" close=")">
       #{id}
       </foreach>
   </delete>
   ```

   - collection：表示遍历哪个数组
   - item：遍历出来的每一个元素

3. 执行方法，测试



测试代码：

```java
    @Test
    public void testDeleteByIds() throws Exception {
        //接收参数
        int[] ids = {12, 13};

        //1.获取SqlSessionFactory,加载MyBatis的核心配置文件
        String resource = "mybatis-config.xml";
        InputStream inputStream = Resources.getResourceAsStream(resource);
        SqlSessionFactory sqlSessionFactory = new SqlSessionFactoryBuilder().build(inputStream);

        //2.获取SqlSession对象
//        SqlSession sqlSession = sqlSessionFactory.openSession();
        SqlSession sqlSession = sqlSessionFactory.openSession(true); //传参:true是自动提交事务,false是手动提交事务

        //3.获取Mapper接口的代理对象
        BrandMapper brandMapper = sqlSession.getMapper(BrandMapper.class);

        //4.执行方法
        brandMapper.deleteByIds(ids);

        //手动提交事务
//        sqlSession.commit();

        //5.释放资源
        sqlSession.close();

    }
```



## 5.MyBatis 参数传递

MyBatis 接口方法中可以接收各种各样的参数，MyBatis底层对于这些参数进行不同的封装处理方式

- 单个参数：

  1. POJO类型（实体类）：直接使用，属性名 和 参数占位符 名称一致

  2. Map集合：直接使用，键名 和 参数占位符 名称一致

  3. Collection：封装为Map集合，推荐使用@Param注解替换Map集合中默认的arg键名

     ```java
     map.put("arg0",collection集合);
     map.put("collection",collection集合);
     ```

  4. List：封装为Map集合，推荐使用@Param注解替换Map集合中默认的arg键名

     ```java
     map.put("arg0",list集合);
     map.put("collection",list集合);
     map.put("list",list集合);
     ```

  5. Array：封装为Map集合，推荐使用@Param注解替换Map集合中默认的arg键名

     ```java
     map.put("arg0",数组);
     map.put("array",数组);
     ```

  6. 其他类型：直接使用

- 多个参数：封装为Map集合，可以使用@Param注解，替换Map集合中默认的arg键名（param不会被修改）
  系统默认如下

  ```java
  map.put("arg0",参数值1)
  map.put("param1",参数值1)
  map.put("arg1",参数值2)
  map.put("param2",参数值2)
  ```

  

  ```java
  User select(@Param("username")String username,@Param("password")String password);
  ```

  ```xml
  <select id="select" resultType="user">
  	select *
      from tb_user
      where
      	username = #{username}
      and password = #{password};
  </select>
  ```



**MyBatis提供了 ParamNameResolver 类来进行参数封装**



测试代码：

```java
public class UserMapperTest {
    @Test
    public void testDeleteByIds() throws Exception {
        //1.获取SqlSessionFactory,加载MyBatis的核心配置文件
        String resource = "mybatis-config.xml";
        InputStream inputStream = Resources.getResourceAsStream(resource);
        SqlSessionFactory sqlSessionFactory = new SqlSessionFactoryBuilder().build(inputStream);

        //2.获取SqlSession对象
        SqlSession sqlSession = sqlSessionFactory.openSession(true); //传参:true是自动提交事务,false是手动提交事务

        //3.获取Mapper接口的代理对象
        UserMapper userMapper = sqlSession.getMapper(UserMapper.class);

        //4.执行方法
        String username="zhangsan";
        String password="123";

        User user = userMapper.select(username, password);

        System.out.println(user);

        //5.释放资源
        sqlSession.close();

    }
}
```



**重点建议：将来都使用@Param注解来修改Map集合中默认的键名，并使用修改后的名称来获取值，这样可读性更高！**



# 六、注解完成增删改查

使用注解开发会比配置文件开发更加方便

```java
@Select("select * from tb_user where id = #{id}")
public User selectById(int id);
```

- 查询：@Select
- 添加：@Insert
- 修改：@Update
- 删除：@Delete



**提示：**

- 注解完成简单功能
- 配置文件完成复杂功能



> 使用注解来映射简单语句会使代码显得更加简洁，但对于稍微复杂一点的语句，Java 注解不仅力不从心，还会让你本就复杂的 SQL 语句更加混乱不堪。因此，如果你需要做一些很复杂的操作，最好使用 XML 来映射语句
>
> 选择何种方式来配置映射，以及认为是否应该要统一映射语句定义的形式，完全取决于你和你的团队。换句话说，永远不要拘泥于一种方式，你可以很轻松的在基于注解和 XML 的语句映射方式间自由移植和切换



测试代码：

```java
    @Test
    public void testSelectById() throws Exception {
        //1.获取SqlSessionFactory,加载MyBatis的核心配置文件
        String resource = "mybatis-config.xml";
        InputStream inputStream = Resources.getResourceAsStream(resource);
        SqlSessionFactory sqlSessionFactory = new SqlSessionFactoryBuilder().build(inputStream);

        //2.获取SqlSession对象
        SqlSession sqlSession = sqlSessionFactory.openSession(true); //传参:true是自动提交事务,false是手动提交事务

        //3.获取Mapper接口的代理对象
        UserMapper userMapper = sqlSession.getMapper(UserMapper.class);

        //4.执行方法
        User user = userMapper.selectById(1);

        System.out.println(user);

        //5.释放资源
        sqlSession.close();

    }
```

