package chapter04;

public class Java04_Object_class {
    public static void main(String[] args) {

        //TODO 面向对象
        //类:结构体,包含了属性(特征)和方法(行为)
        //会有很多的对象
        //class : 关键字(全是小写的)
        //类名:类的名称,标识符,遵循规则,一般情况下,类名的首写字母是大写的(规范,不必须)

        //对象:类的实例化(具象化)
        //new 类名(),小括号需要增加
        //new 也是关键字,表示创建一个具体的对象,而且使用一次,创建一次,每次都是全新的
        //一般new出来的对象会赋值给变量,方便重复使用
        //变量的类型就是对象的类型
        //TODO 对象是将内存地址赋值给了变量,所以变量其实引用了内存中的对象,所以称之为引用变量
        //而变量的类型称之为引用数据类型
//        new User04();
//        new User04();
//        new User04();
        User04 user = new User04();

        //TODO 特殊的对象:空对象,没有引用的对象,称之为空对象,关键字对象
        //所有引用类型变量的默认取值就是null
        User04 user1 = null;
    }
}

class User04 {

}