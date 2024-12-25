package com.itheima.config;

import com.alibaba.druid.pool.DruidDataSource;
import com.itheima.dao.BookDao;
import org.springframework.beans.factory.annotation.Value;
import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.Configuration;

import javax.sql.DataSource;

//@Configuration
public class JdbcConfig {
    //1.定义一个方法获得要管理的对象
    //2.添加@Bean，表示当前方法的返回值是一个bean

    @Value("com.mysql.jdbc.driver")
    private String driver;
    @Value("jdbc:mysql://localhost:3306/db1")
    private String url;
    @Value("root")
    private String username;
    @Value("admin")
    private String password;

    @Bean
    public DataSource dataSource(BookDao bookDao){ //扫描容器按类型自动装配
        System.out.println(bookDao);
        DruidDataSource ds = new DruidDataSource();
        ds.setDriverClassName(driver);
        ds.setUrl(url);
        ds.setUsername(username);
        ds.setPassword(password);
        return ds;
    }
}
