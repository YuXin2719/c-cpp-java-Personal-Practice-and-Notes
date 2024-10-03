package chapter04;

public class Java26_Object {
    public static void main(String[] args) {

        //TODO 面向对象 - 作用域
        User26 user = new User26();
        user.test();
    }
}

class Person26 {
    public static String name = "zhangsan";
}

class User26 extends Person26 {
    public static String name = "lisi";

    //    public void test() {
////        String name = "wangwu";
//
//        //如果属性和(局部)变量的名称相同,访问时如果不加修饰符,那么优先访问变量
//        System.out.println(this.name);
//        System.out.println(super.name);
//    }
    public static void test() {
        //我们所谓的继承,实际上是对象和对象之间的继承,所以说super,this是对象之间的关系
        //但是当前的name属性已经和对象没关系了,也就失去了对象的意义
        //所以这里就不要纠结super和this的问题了
        //如果想访问Person26的name,还真就得Person26.name
        System.out.println(Person26.name);
    }
}