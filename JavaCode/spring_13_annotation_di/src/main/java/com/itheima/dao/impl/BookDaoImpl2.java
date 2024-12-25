package com.itheima.dao.impl;

import com.itheima.dao.BookDao;
import org.springframework.stereotype.Repository;

import javax.annotation.PostConstruct;
import javax.annotation.PreDestroy;

@Repository("bookDao2")
public class BookDaoImpl2 implements BookDao {
    public void save(){
        System.out.println("book dao save ...2");
    }

    @PostConstruct //构造方法后
    public void init(){
        System.out.println("init ...2");
    }

    @PreDestroy //彻底销毁前
    public void destroy(){
        System.out.println("destory ...2");
    }
}