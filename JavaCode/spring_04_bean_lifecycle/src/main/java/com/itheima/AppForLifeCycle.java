package com.itheima;

import com.itheima.dao.BookDao;
import org.springframework.context.ApplicationContext;
import org.springframework.context.support.ClassPathXmlApplicationContext;

public class AppForLifeCycle {
    public static void main(String[] args) {
        ClassPathXmlApplicationContext ctx=new ClassPathXmlApplicationContext("applicationContext.xml");
//        ctx.registerShutdownHook(); //注册关闭钩子 - 容器在启动以后如果要关闭Java虚拟机将先关闭容器，关闭钩子在任何时间都可以注册，但是close放在前面会提前关闭，比较暴力

        BookDao bookDao = (BookDao) ctx.getBean("bookDao");
        bookDao.save();
        ctx.close();
    }
}