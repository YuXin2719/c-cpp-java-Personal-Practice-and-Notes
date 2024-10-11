package chapter05;

import java.util.Calendar;

public class Java09_Object {
    public static void main(String[] args) throws Exception {

        //TODO 常见类和对象
//        //等于
//        //基本数据类型,双等号比较数值
//        int i = 10;
//        int j = 10;
//        System.out.println(i == j);
//        double d = 10.0;
//        System.out.println(i == d);
//
//        //引用数据类型,双等号比较变量的内存地址
//        String s = "abc"; //字符串常量池
//        String s1 = "abc";
//        String s2 = new String("abc");
//        System.out.println(s == s1);
//        System.out.println(s == s2);
//        //equals用于比较字符串内容是否一致
//        System.out.println(s.equals(s2));
//
//        User9 user1 = new User9();
//        User9 user2 = new User9();
//        System.out.println(user1 == user2);
//        System.out.println(user1.equals(user2));

        //包装类型,也是引用数据类型
        //包装类型的比较建议用equals,不建议用双等号,因为以下原因
        //int => Integer => JVM为了操作方便,简化了很多操作
        //Integer缓存:-128 ~ 127
        Integer i1 = Integer.valueOf(-129);
        Integer i2 = Integer.valueOf(-129);

        System.out.println(i1 == i2);
        System.out.println(i1.equals(i2));

        //TODO 简单的说就是:以后所有的引用数据类型建议用equals,基本数据类型建议用双等号

    }
}

class User9 {
    //实际情况可以重写,但不是这么重写的
    @Override
    public int hashCode() {
        return 1;
    }

    @Override
    public boolean equals(Object obj) {
        return true;
    }
}