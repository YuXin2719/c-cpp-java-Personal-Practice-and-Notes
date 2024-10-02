package chapter04;

public class Java19_Object {
    public static void main(String[] args) {

        //TODO 面向对象 - 单例模式
        //JVM默认给类提供的构造方法，其实就是公共的，无参的构造方法
        //1.类的创建过程复杂
        //2.类的对象消耗资源
//        User19 user = new User19();
        User19 instance1 = User19.getInstance();
        User19 instance2 = User19.getInstance();
        User19 instance3 = User19.getInstance();
        User19 instance4 = User19.getInstance();
        User19 instance5 = User19.getInstance();
        User19 instance6 = User19.getInstance();

        System.out.println(instance1 == instance6); //true
        System.out.println(instance1.equals(instance6)); //也是判断两个对象的内存地址是否相等 true
    }
}

class User19 {
    private static User19 user19 = null;

    private User19() {

    }

    public static User19 getInstance() { //静态方法不能访问成员属性，所以上面user19需要加static
        if (user19 == null) {
            user19 = new User19();
        }
        return user19;

    }
}