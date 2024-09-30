package chapter04;

public class Java14_Object_3 {
    public static void main(String[] args) {

        //TODO 面向对象
//        AAA aaa = new AAA();
//        BBB aaa = new BBB();
        BBB aaa = new BBB(); //使用什么方法取决于用的什么类型
        test(aaa);

        //多态其实就是约束了对象的使用场景,给了BBB但是当成AAA来用
        //方法的重载:方法名相同,参数列表不同(个数,顺序,类型)
        //如果找不到,会提升数据类型,找父类:
        //AAA -> Object
        //BBB -> AAA -> Object
    }

    static void test(AAA aaa) {
        System.out.println("aaa");
    }

//    static void test(BBB bbb) {
//        System.out.println("bbb");
//    }
}

class AAA {

}

class BBB extends AAA {

}