package com.itheima.jdbc;

//TODO JDBC快速入门

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.Statement;

//TODO JDBC API 详解：DriverManager

public class JDBCDemo2_DriverManager {
    public static void main(String[] args) throws Exception {

        //1.注册驱动
//        Class.forName("com.mysql.jdbc.Driver");

        //2.获取连接：如果连接的是本机MySQL，并且端口是默认的3306，可以简化书写
        String url="jdbc:mysql:///db1?useSSL=false";
        String username="root";
        String password="admin";
        Connection conn = DriverManager.getConnection(url, username, password); //获取连接对象

        //3.定义sql
        String sql="update account set money=2000 where id=1;";

        //4.获取执行sql的对象 Statement
        Statement stmt = conn.createStatement();

        //5.执行sql
        int count = stmt.executeUpdate(sql); //返回的是受影响的数据的行数

        //6.处理结果
        System.out.println(count);

        //7.释放资源
        stmt.close();
        conn.close();

    }
}
