package chapter05;

public class Java02_Object {
    public static void main(String[] args) {

        //TODO 常见类和对象
        //数组
        User02 user1 = new User02();
        User02 user2 = new User02();
        User02 user3 = new User02();
        User02 user4 = new User02();

        user1.test();
        user2.test();
        user3.test();
        user4.test();

        //0,1,2,3
        User02[] user02s = new User02[4];
        for (int i = 0; i < user02s.length; i++) {
            user02s[i] = new User02();
        }
        for (int i = 0; i < user02s.length; i++) {
            user02s[i].test();
        }

        //TODO 数组的声明方式:类型[] 变量
        //TODO 数组的创建:new 类型[容量]
        String[] names = new String[3];
        //给数组的小格子添加数据,添加的方式为 : 数组变量[索引] = 数据
        //添加数据和访问数据试,索引是不能超过指定范围的(0 ~ 数组总长度 - 1)
        //如果重复给相同的索引添加数据,那么等同于修改数据
        names[0] = "zhangsan";
        names[0] = "zhaoliu";
        names[1] = "lisi";
        names[2] = "wangwu";

        //查询(访问)数据,访问的方式为 : 数组变量[索引]
//        System.out.println(names[0]);
//        System.out.println(names[1]);
//        System.out.println(names[2]);
        System.out.println("**************************************");
        for (int i = 0; i < 3; i++) {
            System.out.println(names[i]);
        }
    }
}

class User02 {
    public void test() {
        System.out.println("test...");
    }
}