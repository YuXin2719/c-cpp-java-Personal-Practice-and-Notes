package chapter10;

import java.lang.reflect.Constructor;
import java.lang.reflect.Field;
import java.lang.reflect.Method;
import java.lang.reflect.Modifier;

public class Java01_Reflect {
    public static void main(String[] args) throws Exception {
        //TODO 反射

        //多态
        User user = new Child();
        user.test1();
//        user.test2();

        //类对象(把编译后的字节码文件当成对象)
        Class<? extends User> aClass = user.getClass();

        //TODO 获取类的名称
        System.out.println(aClass.getName()); //获取类的完整名称(包含包名)
        System.out.println(aClass.getSimpleName()); //获取类的名称
        System.out.println(aClass.getPackage().getName()); //获取类的包的名称

        //TODO 获取类的父类
        Class<?> superclass = aClass.getSuperclass();
        System.out.println(superclass);

        //TODO 获取类的接口
        Class<?>[] interfaces = aClass.getInterfaces();
        System.out.println(interfaces.length);

        //TODO 获取类的属性
        Field f = aClass.getField("xxxxx"); //根据属性名称获取属性(获取的是public访问权限的属性,其他权限的属性无法取到)
        Field f1 = aClass.getDeclaredField("xxxxx"); //所有权限的属性都可以取到

        Field[] fields = aClass.getFields(); //获取全部public权限的属性
        Field[] declaredFields = aClass.getDeclaredFields(); //获取所有权限的所有属性

        //TODO 获取类的方法
        Method method = aClass.getMethod("test2"); //获取public权限的某个方法
        aClass.getDeclaredMethod("test2"); //获取所有权限的某个方法

        Method[] methods = aClass.getMethods(); //获取全部public权限的方法
        Method[] declaredMethods = aClass.getDeclaredMethods(); //获取全部权限的所有方法

        //TODO 构造方法
        Constructor<? extends User> constructor = aClass.getConstructor(); //返回一个public构造方法对象
        Constructor<?>[] constructors = aClass.getConstructors(); //返回所有public构造方法对象
        Constructor<? extends User> declaredConstructor = aClass.getDeclaredConstructor(); //返回一个构造方法对象
        Constructor<?>[] declaredConstructors = aClass.getDeclaredConstructors(); //返回所有构造方法对象

        //TODO 获取权限(修饰符) : 多个修饰符会融合成一个int值
        int modifiers = aClass.getModifiers();
        boolean aPrivate = Modifier.isPrivate(modifiers); //通过Modifier的方法判断这个int值是什么访问权限
    }
}

class User {
    public void test1() {
        System.out.println("test1...");
    }
}

class Child extends User {
    public void test2() {
        System.out.println("test2...");
    }
}