package chapter07;

import java.util.ArrayList;
import java.util.Comparator;

public class Java08_Collection_Sort {
    public static void main(String[] args) {

        //TODO 集合 - Collection
        //Sort 排序
        ArrayList list = new ArrayList();
        list.add(1);
        list.add(3);
        list.add(2);

        //1, 3, 2 => 3, 1, 2 => 3, 2, 1
        //3, 2, 1

        //排序需要传递一个实现了比较器接口的对象
        list.sort(new NumberComparator());

        System.out.println(list);

    }
}

class NumberComparator implements Comparator<Integer> { //ctrl + o: 选择需要重写的方法
    @Override
    public int compare(Integer o1, Integer o2) {
        //TODO 如果第一个数比第二个数要大,那么返回结果为正数,表示升序
//        return o1 - o2;
        //TODO 如果第一个数比第二个数要小,那么返回结果为负数,表示降序
//        return o2 - o1;
        //TODO 如果第一个数比第二个数一样大,那么返回结果为0
        return 0;
    }
}
