package chapter04;

public class Java12_Object_Extends_1 {
    public static void main(String[] args) {

        //TODO 面向对象 - 继承
        //如果父类和子类含有相同的属性,那么可以采用特殊的关键字进行区分
        Child1 c = new Child1();
//        System.out.println(c.name);
        c.test();
    }
}

class Parent1 {
    String name = "zhangsan";
}

class Child1 extends Parent1 {
    String name = "lisi";

    void test() {
        System.out.println(super.name);
        System.out.println(this.name);
        System.out.println(name);
    }
}