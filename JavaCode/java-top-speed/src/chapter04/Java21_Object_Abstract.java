package chapter04;

public class Java21_Object_Abstract {
    public static void main(String[] args) {

        //TODO 面向对象 - 抽象 - Abstract
        //抽象类 : 不完整的类,就是抽象类
        //          abstract class 类名
        //      因为类不完整,所以无法直接构造对象
        //抽象方法 : 只有声明,没有实现的方法
        //          abstract 返回值类型 方法名(参数)

        //分析问题:对象(具体) => 类(抽象)
        //编写代码:类(抽象) => 对象(具体)

        //如果一个类中含有抽象方法,那么这个类是抽象类
        //如果一个类是抽象类,它的方法不一定是抽象方法
        //抽象类无法直接构建对象,但是可以通过子类间接构建对象
        //如果抽象类中含有抽象方法,那么子类继承抽象类,需要重写抽象方法,将方法补充完整

        //abstract关键字不能和final同时使用(抽象类和抽象方法都不可以同时出现这俩关键字)
//        Person21 person21 = new Person21();
        Chinese21 chinese21 = new Chinese21();
        chinese21.eat();
    }
}

abstract class Person21 {
    public abstract void eat();

    public void test() {

    }
}

class Chinese21 extends Person21 {
    public void eat() {
        System.out.println("中国人使用筷子吃饭");
    }
}