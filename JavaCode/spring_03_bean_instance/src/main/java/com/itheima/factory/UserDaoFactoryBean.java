package com.itheima.factory;

import com.itheima.dao.UserDao;
import com.itheima.dao.impl.UserDaoImpl;
import org.springframework.beans.factory.FactoryBean;

public class UserDaoFactoryBean implements FactoryBean<UserDao> {
    //代替原始实例工厂中创建对象的方法
    @Override
    public UserDao getObject() throws Exception {
        return new UserDaoImpl();
    }

    //确认对象的类型
    @Override
    public Class<?> getObjectType() {
        return UserDao.class; //给一个UserDao的字节码
    }

    @Override
    public boolean isSingleton() { //规定创建的是否为单例对象，true就是创建单例对象，false就是创建非单例对象
        //不重写这个方法，默认为单例对象
        return true;
    }
}
