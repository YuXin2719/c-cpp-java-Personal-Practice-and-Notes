package chapter04;

public class Java08_Object_Static_1 {
    public static void main(String[] args) {

        //TODO 面向对象 - 静态

        //TODO 先有类,再有对象
        //成员方法可以访问静态属性和静态方法
        //静态方法不可以访问成员属性和成员方法
        Test t = new Test();
        t.sex = "女";
        t.test();
//        t.test1();
//        Test.test1();
    }
}

class Test {
    String name; //成员属性
    static String sex; //静态属性

    void test() { //成员方法
//        test1();
//        System.out.println(sex);
        System.out.println("test...");
    }

    static void test1() { //静态方法
//        test();
//        System.out.println(name);
//        System.out.println("test1...");
    }
}


class Bird1 {
    static String type = "鸟";

    static void fly() {
        System.out.println("飞...");
    }
}