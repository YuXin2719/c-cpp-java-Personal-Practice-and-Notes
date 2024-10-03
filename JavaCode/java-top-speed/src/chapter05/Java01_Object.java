package chapter05;

public class Java01_Object {
    public static void main(String[] args) {

        //TODO 常见类和对象
        //java.long.Object : 对象
        Object obj = new Person01();

        //将对象转换成字符串
        //toString默认打印的就是对象的内存地址,所以,为了能够更直观的理解对象的内容,所以可以重写这个方法
        String s = obj.toString();
        System.out.println(s); //结果为:chapter05.User01@4554617c,其中4554617c代表该对象的哈西值,且为16进制的结果

        //TODO 获取对象的内存地址
        int i = obj.hashCode(); //简单的理解为:获取了对象的内存地址(并不是真正的内存地址,只是可以这么理解)
        System.out.println(i); //结果为:1163157884,这里也是该对象的哈西值,且和上面的4554617c是一个意思,只是这里显示的数字为10进制的

        //TODO 判断两个对象是否相等,如果相等,返回true,如果不相等,则返回false
        //equals方法比较对象时,默认比较的就是内存地址
        Person01 otherPerson = new Person01();
        System.out.println(otherPerson.hashCode());
        System.out.println(obj.equals(otherPerson));

        //getClass获取对象的类型信息
        Class<?> aClass = obj.getClass();
        System.out.println(aClass.getSimpleName());
        System.out.println(aClass.getPackage());
    }
}

class Person01 {
    public String name = "zhangsan";

    //ctrl + o 快捷键快速重写某个方法
//    @Override
//    public String toString() {
//        return "Person[" + name + "]"; // + 拼接字符串
//    }


    @Override
    public boolean equals(Object obj) {
        return true;
    }
}

class User01 extends Person01 {

}