package chapter04;

public class Java20_Object {
    public static void main(String[] args) {

        //TODO 面向对象
        //如何保证在初始化一个数据之后不能再修改他？
        //Java中提供了一种语法,可以在数据初始化后不被修改,使用关键字final
        //final可以修饰变量,变量的值一旦初始化后无法修改
        //final可以修饰属性,那么JVM不能自动进行初始化,需要自己进行初始化,属性值不能发生变化
        //一般将final修饰的变量称之为常量,或者不可变变量
        //final可以修饰方法，这个方法不能被子类重写(子类可以继承父类,但是方法逻辑改不了)
        //final可以修饰类,这样类就没有子类了
        //final不可以修饰构造方法
        //final可以修饰方法的参数,一旦修饰,参数就无法修改

        final String name = "zhangsan";
        //name = "wangwu";
        System.out.println(name);

        User20 user = new User20("wangwu");
        //user.name = "zhangsan";
        System.out.println(user.name);

        //user.name = "lisi";
        System.out.println(user.name);
    }
}

final class User20 {
    public final String name;

    public User20(String name) {
        this.name = name;
    }

    public final void test() {

    }

    public void test1(final String name) {
//        name = "lisi";
    }
}

//class Child20 extends User20 {
//    public void test() {
//
//    }
//}