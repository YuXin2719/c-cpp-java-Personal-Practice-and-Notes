package chapter04;

public class Java24_Object {
    public static void main(String[] args) {

        //TODO 面向对象 - 匿名类
        //在某种场合下,类的名字不重要,我们只想使用类中的方法或功能
        //那么此时我们可以采用特殊的语法:匿名类
        //所谓的匿名类,就是没有名字的类

        Me me = new Me();
//        me.sayHello(new Zhangsan());
        me.sayHello(new Person24() {
            public String name() {
                return "wangwu";
            }
        });

        me.sayHello(new Person24() {
            public String name() {
                return "zhaoliu";
            }
        });

        new Bird24().fly();

        new Fly() {
            public void fly() {
                System.out.println("使用飞行器飞翔");
            }
        }.fly();
    }
}

interface Fly {
    public void fly();
}

class Bird24 implements Fly {
    public void fly() {
        System.out.println("使用翅膀飞翔");
    }
}

abstract class Person24 {
    public abstract String name();
}

class Me {
    public void sayHello(Person24 person24) {
        System.out.println("Hello " + person24.name());
    }
}

class Zhangsan extends Person24 {
    public String name() {
        return "zhangsan";
    }
}

class Lisi extends Person24 {
    public String name() {
        return "lisi";
    }
}