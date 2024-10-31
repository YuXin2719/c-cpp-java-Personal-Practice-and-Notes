package chapter07;

import java.util.ArrayList;
import java.util.HashSet;

public class Java09_Collection_Set_1 {
    public static void main(String[] args) {

        //TODO 集合 - Collection - set
        HashSet set = new HashSet();

        ArrayList List = new ArrayList();
        List.add("zhangsan");
        List.add("lisi");
        List.add("wangwu");
        set.addAll(List);

        Object[] array = set.toArray();
        System.out.println(set.isEmpty());
//        set.clear();
        System.out.println(set.contains("zhangsan"));
        System.out.println(set.size());
        Object clone = set.clone();
        System.out.println(clone);

        System.out.println(set);

    }
}

