package chapter04;

public class Java08_Object_Static {
    public static void main(String[] args) {

        //TODO 面向对象
        //针对于具体对象的属性称之为对象属性,成员属性,实例属性
        //针对于具体对象的方法称之为对象方法,成员方法,实例方法
        //把和对象无关,只和类相关的称之为静态
        //和类相关的属性称之为静态属性
        //和类相关的方法称之为静态方法
        //静态语法就是在属性和方法前增加static关键字
//        Chinese c = new Chinese();
//        Chinese c = null;
//        c.name = "zhangsan";
//
//        System.out.println("Hello " + c.name + ", " + c.nationnality);

        //静态不用创建对象就能访问
        Bird.fly();
        System.out.println(Bird.type);
    }
}

class Bird {
    static String type = "鸟";

    static void fly() {
        System.out.println("飞...");
    }
}

class Chinese {
    String name;

    //国籍
    String nationnality = "中国";
}
