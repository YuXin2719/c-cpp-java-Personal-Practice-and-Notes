package chapter07;

import java.util.ArrayList;
import java.util.Comparator;
import java.util.HashSet;

public class Java09_Collection_Set {
    public static void main(String[] args) {

        //TODO 集合 - Collection - set
        //HashSet : Hash + Set
        //Hash : 哈希算法,散列算法(严格意义上不可逆)
        // (哈希算法计算同一个值的结果是固定的,假设用哈希计算A结果为2,再次计算A结果还是2)
        // 所以我们可以往HashSet放重复的数据,但是存储的数据不会有重复的,例如往HashSet内放两次A,但是最后HashSet内只存一个A
        //ArrayList : 数组(有容量这个参数)
        //LinkedList : 链表(没有容量这个参数)
        HashSet set = new HashSet(); //底层确实是数组,但是Hash算法导致数据放入数组的时候顺序被打乱
        //TODO 增加数据
        set.add("zhangsan");
        set.add("zhangsan");
        set.add("lisi");
        set.add("wangwu");

        //TODO 修改数据(实际上没有直接修改的方法,只能先删除再增加)

        //TODO 删除数据
        set.remove("wangwu");

        //TODO 查询数据(没有对应的查询方式,得不到数据的索引,经过hash计算后也不知道数据位置.但是可以遍历)
        for (Object o : set) {
            System.out.println(o);
        }

        System.out.println(set);


    }
}

