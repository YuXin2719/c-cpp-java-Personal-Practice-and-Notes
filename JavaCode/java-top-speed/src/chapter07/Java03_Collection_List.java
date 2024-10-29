package chapter07;

import java.util.ArrayList;

public class Java03_Collection_List {
    public static void main(String[] args) {

        //TODO 集合 - Collection - List
        //          ArrayList : Array + List
        //TODO List : 列表,清单
        //  按照数据插入顺序进行存储
        //TODO Array : 数组,阵列

        //TODO 创建第一个集合对象: ArrayList
        ArrayList list = new ArrayList(3); //Alt + 回车: 自动包含      ctrl + p: 显示该方法参数列表
        //1.不需要传递构造参数,直接new就可以,底层数组为空数组
        //2.构造参数需要传递一个int类型的值,用于设定底层数组的长度
        //3.构造参数需要传递一个Collection集合类型的值,用于将其他集合中的数据放置在当前集合中

        //TODO 增加数据
        // add方法可以增加数据,只要将数据作为参数传递到add方法即可
        // 添加数据时,如果集合中没有任何数据,那么底层会创建长度为10的数组

        //TODO 使用ArrayList的情况下，使用指定大小构造器，扩容后容量会变为指定大小的 1.5 倍

        list.add("zhangsan");
        list.add("zhangsan");
        list.add("wangwu");
        list.add("zhaoliu");
        //TODO 访问集合中的数据
        //获取集合中的条数
        System.out.println(list.size());
        //获取指定位置的数据,可以采用索引的方式
        System.out.println(list.get(1));
        //遍历集合中的数据
        for (int i = 0; i < list.size(); i++) {
            System.out.println("遍历集合中的数据:" + list.get(i));
        }
        //TODO 如果循环遍历集合数据时,那么可以采用特殊的for循环
        //for (循环对象:集合)
        for (Object obj : list) {
            System.out.println("特殊遍历集合中的数据:" + obj);
        }

        //TODO 修改数据
        //将指定位置的数据进行修改,set方法需要传递两个参数,第一个参数表示数据的位置,第二个参数表示要修改的值
        //这个方法会返回结果,返回的就是更新前的值
        Object oldVal = list.set(1, "lisi");
        System.out.println("修改前的值:" + oldVal);

        //TODO 删除数据
        //将指定位置的数据进行删除,remove方法需要传递一个参数,这个参数表示要删除的数据的位置
        //这个方法会返回结果,返回的就是删除的值
        Object removeVal = list.remove(1);
        System.out.println("删除的值:" + removeVal);

        //TODO 打印集合对象
        System.out.println(list);

        System.out.println("main方法执行完毕");

    }
}
