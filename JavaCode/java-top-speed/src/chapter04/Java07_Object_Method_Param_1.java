package chapter04;

import netscape.security.UserTarget;

public class Java07_Object_Method_Param_1 {
    public static void main(String[] args) {

        //TODO 面向对象 - 方法
        //Java中方法参数的传递为值传递
        //基本数据类型:数值
        //引用数据类型:引用地址
//        String s = "abc";
//        test(s);
//        System.out.println(s); //"abc10"?
        User user = new User();
        user.name = "zhangsan";
        test(user);
        System.out.println(user.name);

        //字符串拼接机制:
        // 在 Java 中，当一个字符串（如 "zhangsan"）与其他基本数据类型（这里是 int 类型的 10）进行拼接操作时,
        // Java 会自动将基本数据类型转换为字符串类型，然后再进行拼接
        String name = "zhangsan" + 10;
        System.out.println(name);
    }

//    public static void test(int i) {
//        i = i + 10;
//    }

//    public static void test(String s) {
//        s = s + 10;
//    }

    public static void test(User user) {
        user.name = "lisi";
    }
}

class User {
    String name;
}