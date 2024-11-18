package com.itheima.jdbc;

//TODO JDBC快速入门

import org.junit.Test;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.Statement;

//TODO JDBC API 详解：Statement

public class JDBCDemo4_Statement {

    //执行DML语句
    @Test
    public void testDML() throws Exception{
        //1.注册驱动
//        Class.forName("com.mysql.jdbc.Driver");

        //2.获取连接：如果连接的是本机MySQL，并且端口是默认的3306，可以简化书写
        String url="jdbc:mysql:///db1?useSSL=false";
        String username="root";
        String password="admin";
        Connection conn = DriverManager.getConnection(url, username, password); //获取连接对象

        //3.定义sql
        String sql="update account set money=3000 where id=1;";

        //4.获取执行sql的对象 Statement
        Statement stmt = conn.createStatement();

        //5.执行sql
        int count = stmt.executeUpdate(sql); //执行完DML语句后，返回的是受影响的数据的行数

        //6.处理结果
//        System.out.println(count);
        if(count>0){
            System.out.println("修改成功！");
        }else{
            System.out.println("修改失败!");
        }

        //7.释放资源
        stmt.close();
        conn.close();
    }

    //执行DDL语句
    @Test
    public void testDDL() throws Exception{
        //1.注册驱动
//        Class.forName("com.mysql.jdbc.Driver");

        //2.获取连接：如果连接的是本机MySQL，并且端口是默认的3306，可以简化书写
        String url="jdbc:mysql:///db1?useSSL=false";
        String username="root";
        String password="admin";
        Connection conn = DriverManager.getConnection(url, username, password); //获取连接对象

        //3.定义sql
        String sql="drop database db2;";

        //4.获取执行sql的对象 Statement
        Statement stmt = conn.createStatement();

        //5.执行sql
        int count = stmt.executeUpdate(sql); //执行完DDL语句后，返回的可能是0

        //6.处理结果
//        System.out.println(count);
//        if(count>0){
//            System.out.println("修改成功！");
//        }else{
//            System.out.println("修改失败!");
//        }
        System.out.println(count);

        //7.释放资源
        stmt.close();
        conn.close();
    }

}
