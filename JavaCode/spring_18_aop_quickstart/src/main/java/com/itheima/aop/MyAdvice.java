package com.itheima.aop;

import org.aspectj.lang.annotation.Aspect;
import org.aspectj.lang.annotation.Before;
import org.aspectj.lang.annotation.Pointcut;
import org.springframework.stereotype.Component;

@Component //告诉spring来加载我
@Aspect //告诉spring这个东西是用来做aop的
public class MyAdvice {
    @Pointcut("execution(void com.itheima.dao.BookDao.update())") //定义好切入点
    private void pt() {
    }

    @Before("pt()") //把切入点和通知绑定好
    public void method() {
        System.out.println(System.currentTimeMillis());
    }
}
