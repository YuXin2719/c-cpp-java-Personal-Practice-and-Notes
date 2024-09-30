package chapter04;

public class Java07_Object_Method_Param {
    public static void main(String[] args) {

        //TODO 面向对象 - 方法
        //使用外部数据控制方法内部实现的操作,使用的是参数语法实现,也叫做方法参数
        //语法:方法名( 参数类型 参数名称 )
        //参数列表
        //语法:方法名( 参数类型1 参数名称1 , 参数类型2 参数类型2 )

        User07 user = new User07();
        String name = "zhangsan";
        int age = 30;
        //传递参数
        //user.sayHello(name, age);

        //当方法传递多个参数的时候,需要注意:
        //1.参数个数需要匹配
        //2.参数类型需要匹配
        //3.参数顺序需要匹配

        //TODO 4.当参数的个数不确定,但是类型相同时,可以采用特殊的参数语法声明:可变参数
        //如果参数还包含其他含义的参数,那么可变参数应该放在最后
        //语法:参数类型... 参数名称
        user.test(30);
        user.test(30, "zhangsan");
        user.test(30, "zhangsan", "lisi", "wangwu");
    }
}

class User07 {

    void sayHello(String name, int age) {
        //使用参数
        System.out.println("Hello " + name + ',' + age);
    }

    void test(int age, String... name) {
        System.out.println(name);
    }
}