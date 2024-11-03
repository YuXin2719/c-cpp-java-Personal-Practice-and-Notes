package chapter07;

import java.util.HashMap;
import java.util.Hashtable;

public class Java11_Collection_Map_2 {
    public static void main(String[] args) throws Exception {

        //TODO 集合 - Map
        //Hashtable
        Hashtable hashtable = new Hashtable();
//        hashtable.put(null, null);
        HashMap hashMap = new HashMap();
        hashMap.put(null, null);
//        hashtable.put();
//        hashtable.get();
//        hashtable.remove();
        //TODO 1.底层实现方式不一样 : 继承的父类不一样
        //TODO 2.底层结构的容量不同 : HashMap默认数组容量为16,Hashtable默认数组容量为11
        //TODO 3.HashMap的K,V都可以为null,Hashtable的K,V不能为null
        //TODO 4.HashMap的数据定位采用的Hash算法,但是Hashtable采用的就是hashcode
        //TODO 5.HashMap的多线程性能较高,但是Hashtable较低(没有考虑)

    }
}
