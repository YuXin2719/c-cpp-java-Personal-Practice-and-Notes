package chapter02;

public class Java01_variable {
    public static void main(String[] args) {

        //TODO 变量
        //所谓的变量，其实就是可以改变的向量存储
        //1.变量的声明
        //数据类型 变量的名称
        String name;
        //2.变量的赋值
        //变量名称 = 数据
        name = "zhangsan";
        //3.变量的使用
        //直接访问变量的名称
        System.out.println(name);

        //将变量的声明和赋值在一行代码中完成
        String username = "lisi";
        System.out.println(username);

        //TODO 在使用变量之前，必须要给变量赋值，这个操作称为变量的初始化
    }
}
