package chapter10;

import java.lang.reflect.Constructor;
import java.lang.reflect.Field;
import java.lang.reflect.Method;

public class Java03_Reflect_Test {
    public static void main(String[] args) throws Exception {

        //TODO 反射 - 练习
        //员工的登录功能

        //declaredConstructor 构造方法对象
        Class empClass = Emp.class;
        Constructor declaredConstructor = empClass.getDeclaredConstructor();
        //构建对象
        Object emp = declaredConstructor.newInstance(); //构建实例

        //获取对象的属性
        Field account = empClass.getField("account");
        Field password = empClass.getField("password");

        //给emp对象的属性赋值
        account.set(emp, "admin");
        password.set(emp, "admin");

        //获取登录方法
        Method login = empClass.getMethod("login");

        //调用方法
        Object result = login.invoke(emp);

        System.out.println(result);

    }
}

//员工
class Emp {
    public String account;
    public String password;

    public boolean login() {
        if ("admin".equals(account) && ("admin".equals(password))) {
            return true;
        } else {
            return false;
        }
    }
}