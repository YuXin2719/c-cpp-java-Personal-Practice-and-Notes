package chapter07;

import java.util.ArrayList;
import java.util.LinkedList;

public class Java05_Collection_List_LinkedList {
    public static void main(String[] args) {

        //TODO 集合 - Collection - List
        //LinkedList : Linked(连接) + List
        //构建集合对象
        LinkedList list = new LinkedList();

        //增加第一个数据
        list.add("zhangsan");
        list.add("lisi");
        list.add("wangwu");
//        list.addFirst("lisi");
//        list.add(1, "wangwu");

        //TODO 获取数据
//        System.out.println(list.getFirst());
//        System.out.println(list.getLast());

        //TODO 获取数据（遍历数据）
//        System.out.println(list.get(1));
//        for (int i = 0; i < list.size(); i++) {
//            System.out.println(list.get(i));
//        }
//
//        for (Object o : list) {
//            System.out.println(o);
//        }

        //修改数据
//        list.set(1,"zhaoliu");
        
        //删除数据
        list.remove("zhangsan");

        //打印集合的数据
        System.out.println(list);


    }
}
