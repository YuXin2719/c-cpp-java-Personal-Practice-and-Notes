package chapter04;

public class Java18_Object {
    public static void main(String[] args) {

        //TODO 面向对象 - 外部类 - 内部类
        //Java中不允许外部类使用private，protected修饰
        //只能使用public或者默认修饰
        //所谓的外部类，就是在源码中直接声明的类
        //所谓的内部类，就是类中声明的类

        //内部类被当成外部类的属性使用即可

        //因为内部类可以看作外部类的属性，所以需要构建外部类对象才可以使用
        OuterClass outer = new OuterClass();
        OuterClass.InnerClass innerClass = outer.new InnerClass();
    }

}

class OuterClass {
    public class InnerClass {

    }
}