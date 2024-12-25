package com.itheima.dao.impl;

import com.itheima.dao.BookDao;
import org.springframework.beans.factory.annotation.Value;
import org.springframework.context.annotation.Scope;
import org.springframework.stereotype.Repository;

import javax.annotation.PostConstruct;
import javax.annotation.PreDestroy;

@Repository("bookDao")
public class BookDaoImpl implements BookDao {

    @Value("${name}")
    private String name;

    public void save() {
        System.out.println("book dao save ..." + name);
    }

    @PostConstruct //构造方法后
    public void init() {
        System.out.println("init ...");
    }

    @PreDestroy //彻底销毁前
    public void destroy() {
        System.out.println("destory ...");
    }
}