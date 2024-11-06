package chapter10;

import java.lang.reflect.Constructor;
import java.lang.reflect.Field;
import java.lang.reflect.Method;

public class Java04_Reflect_Exception {
    public static void main(String[] args) throws Exception {

        //TODO 反射 - 练习
        //员工的登录功能

        //1.ClassNotFoundException,异常:类找不到
        //2.NoSuchMethodException,异常:方法找不到,没有方法
        //3.IllegalArgumentException,异常:参数异常
        //4.NoSuchFieldException,异常:没有属性
        //5.IllegalAccessException,异常:访问权限异常
        //6.InvocationTargetException,异常:调用目标异常

        //declaredConstructor 构造方法对象
//        Class empClass = Emp.class; //用类型获取类型信息
//        Class<? extends Emp> empClass = new Emp().getClass(); //也是用来获取类型信息的
        Class<?> empClass = Class.forName("chapter10.Emp"); //用字符串获取类型信息,和上面的作用没有本质区别

        Constructor declaredConstructor = empClass.getDeclaredConstructor();
        //构建对象
        Object emp = declaredConstructor.newInstance(); //构建对象实例

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
class Emp4 {
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