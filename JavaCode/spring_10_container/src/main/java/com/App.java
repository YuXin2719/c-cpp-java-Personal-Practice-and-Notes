package com;

import com.itheima.dao.BookDao;
import org.springframework.context.ApplicationContext;
import org.springframework.context.support.ClassPathXmlApplicationContext;
import org.springframework.context.support.FileSystemXmlApplicationContext;

import java.awt.print.Book;

public class App {
    public static void main(String[] args) {
        //1.加载类路径下的配置文件
        ApplicationContext ctx = new ClassPathXmlApplicationContext("applicationContext.xml");
        //2.从文件系统下加载配置文件
//        ApplicationContext ctx = new FileSystemXmlApplicationContext("E:\\c.---c.---java-exercise\\JavaCode\\spring_10_container\\src\\main\\resources\\applicationContext.xml");

//        BookDao bookDao = (BookDao) ctx.getBean("bookDao");
//        BookDao bookDao=ctx.getBean("bookDao", BookDao.class);
        //以上两种写法意义相同
        BookDao bookDao = ctx.getBean(BookDao.class);

        bookDao.save();
    }
}
