package chapter07;

import javax.jws.soap.SOAPBinding;
import java.util.ArrayList;

public class Java06_Collection {
    public static void main(String[] args) {

        //TODO 集合 - Collection
        //泛型语法
        //<>内约束存放的数据类型
        ArrayList<Person6> list = new ArrayList();

//        Person6 user6 = new User6(); //左边限制使用场景,右边限制使用的方法
//        user6.testUser();
//        user6.testPerson();

        Person6 person6 = new Person6();
        User6 user6 = new User6();

        list.add(person6);
//        list.add(user6);

//        list.remove(0);

        //从集合中获取的对象类型为object
//        Object o = list.get(0);
        //如果想要执行对象的方法,那么需要进行强制类型转换
//        if (o instanceof Person6) {
//            Person6 p = (Person6) o;
//            p.testPerson();
//        }
        Person6 p = list.get(0);
        p.testPerson();


    }
}

class Person6 {
    public void testPerson() {
        System.out.println("Person...");
    }
}

class User6 {
    public void testUser() {
        System.out.println("user...");
    }
}