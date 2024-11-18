package com.itheima.jdbc;

//TODO JDBC快速入门

import com.itheima.pojo.Account;
import org.junit.Test;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.Statement;
import java.util.ArrayList;
import java.util.List;

//TODO 用户登录

public class JDBCDemo6_UserLogin {

    //执行DQL语句
    @Test
    public void testLogin() throws Exception{

        //2.获取连接：如果连接的是本机MySQL，并且端口是默认的3306，可以简化书写
        String url="jdbc:mysql:///db1?useSSL=false";
        String username="root";
        String password="admin";
        Connection conn = DriverManager.getConnection(url, username, password); //获取连接对象

        //接收用户输入的 用户名和密码
        String name="zhangsan";
        String pwd="fasfsafdgb";

        String sql="select * from tb_user where username='"+name+"' and password='"+pwd+"'";

        //获取stmt对象
        Statement stmt = conn.createStatement();

        //执行sql
        ResultSet rs = stmt.executeQuery(sql);

        //判断登录是否成功
        if(rs.next()){
            System.out.println("登录成功!");
        }else{
            System.out.println("登录失败!");
        }

        //7.释放资源
        rs.close();
        stmt.close();
        conn.close();

    }

    //演示SQL注入
    //核心问题在于拼接字符串
    @Test
    public void testLogin_Inject() throws Exception{

        //2.获取连接：如果连接的是本机MySQL，并且端口是默认的3306，可以简化书写
        String url="jdbc:mysql:///db1?useSSL=false";
        String username="root";
        String password="admin";
        Connection conn = DriverManager.getConnection(url, username, password); //获取连接对象

        //接收用户输入的 用户名和密码
        String name="zhangsan";
        String pwd="' or '1' = '1";

        String sql="select * from tb_user where username='"+name+"' and password='"+pwd+"'";
        System.out.println(sql);

        //获取stmt对象
        Statement stmt = conn.createStatement();

        //执行sql
        ResultSet rs = stmt.executeQuery(sql);

        //判断登录是否成功
        if(rs.next()){
            System.out.println("登录成功!");
        }else{
            System.out.println("登录失败!");
        }

        //7.释放资源
        rs.close();
        stmt.close();
        conn.close();

    }
}
