package com.itheima.jdbc;

//TODO JDBC快速入门

import org.junit.Test;

import java.sql.*;

//TODO JDBC API 详解：PreparedStatement

public class JDBCDemo7_PreparedStatement {

    //执行DQL语句
    @Test
    public void testPreparedStatement() throws Exception{

        //2.获取连接：如果连接的是本机MySQL，并且端口是默认的3306，可以简化书写
        String url="jdbc:mysql:///db1?useSSL=false";
        String username="root";
        String password="admin";
        Connection conn = DriverManager.getConnection(url, username, password); //获取连接对象

        //接收用户输入的 用户名和密码
        String name="zhangsan";
        String pwd="' or '1' = '1";

        //定义sql
        String sql="select * from tb_user where username = ? and password = ?;";

        //获取pstmt对象
        //自动添加转义字符防止SQL注入
        PreparedStatement pstmt = conn.prepareStatement(sql);

        //设置问号的值
        pstmt.setString(1,name);
        pstmt.setString(2,pwd);

        //执行sql
        ResultSet rs = pstmt.executeQuery();

        //判断登录是否成功
        if(rs.next()){
            System.out.println("登录成功!");
        }else{
            System.out.println("登录失败!");
        }

        //7.释放资源
        rs.close();
        pstmt.close();
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

    //PreparedStatement原理
    @Test
    public void testPreparedStatement2() throws Exception{

        //2.获取连接：如果连接的是本机MySQL，并且端口是默认的3306，可以简化书写
        //&useServerPrepStmts=true 参数开启预编译功能
        String url="jdbc:mysql:///db1?useSSL=false&useServerPrepStmts=true&allowPublicKeyRetrieval=true";
        String username="root";
        String password="admin";
        Connection conn = DriverManager.getConnection(url, username, password); //获取连接对象

        //接收用户输入的 用户名和密码
        String name="zhangsan";
        String pwd="' or '1' = '1";

        //定义sql
        String sql="select * from tb_user where username = ? and password = ?;";

        //获取pstmt对象
        //自动添加转义字符防止SQL注入
        PreparedStatement pstmt = conn.prepareStatement(sql);

        Thread.sleep(10000);

        //设置问号的值
        pstmt.setString(1,name);
        pstmt.setString(2,pwd);
        ResultSet rs=null;

        //执行sql
         rs = pstmt.executeQuery();

        //设置问号的值
        pstmt.setString(1,"aaa");
        pstmt.setString(2,"bbb");

        //执行sql
         rs = pstmt.executeQuery();

        //判断登录是否成功
        if(rs.next()){
            System.out.println("登录成功!");
        }else{
            System.out.println("登录失败!");
        }

        //7.释放资源
        rs.close();
        pstmt.close();
        conn.close();

    }

}
