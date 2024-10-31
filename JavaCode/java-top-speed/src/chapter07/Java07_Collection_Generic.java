package chapter07;

import java.util.ArrayList;

public class Java07_Collection_Generic {
    public static void main(String[] args) {

        //TODO 集合 - Collection
        //泛型语法
        //TODO 泛型和类型的区别
        //用于约束外部对象的使用场景,就是类型
        //用于约束内部对象的使用场景,就是泛型
        //有时,也把泛型称之为类型参数
        MyContainer<User7> myContainer = new MyContainer();
//        myContainer.data = new Object();

        //TODO 虽然User7是Object的子类,但是这里不能传入User7的对象,因为
        // 1.类型存在多态的使用
        // 2.泛型没有多态
//        test(myContainer);

    }

    public static void test(MyContainer<Object> myContainer) {
        System.out.println(myContainer);
    }
}

//TODO 容器类
//这里的C类似参数,数据data暂时没有被确定类型,使用的时候传入的什么类型这里的data就是什么类型
class MyContainer<C> {
    public C data;
}

class User7 {

}