package chapter07;

import java.util.Collection;
import java.util.HashMap;
import java.util.Map;
import java.util.Set;

public class Java11_Collection_Map_1 {
    public static void main(String[] args) throws Exception {

        //TODO 集合 - Map
        //HashMap ： Hash + Map
        //数据存储是无序的
        //由于也使用的Hash算法,所以不能放重复数据,Hash算法会根据<K,V>键值对的Key来判断数据是否相同,相同的数据会直接覆盖原数据
        HashMap<String, String> map = new HashMap();

        //添加数据 + 修改数据
//        map.put("a", "0");
//        Object oldVal = map.put("a", "1"); //返回旧的值,如果没有旧的值就返回空
////        System.out.println(oldVal);
//
//        //添加数据
//        map.putIfAbsent("b", "2");
//        map.putIfAbsent("b", "3"); //该方法就是:如果b已经有数据了那就不会覆盖
//
//        //修改数据
//        Object b = map.replace("c", "4"); //返回修改之前的值,且只会替换和修改,不会添加新的数据
//        System.out.println(b);

        map.clear();
        map.put("zhangsan", "1");
        map.put("lisi", "2");
        map.put("wangwu", "3");

        //TODO 获取map集合中所有的key
//        Set set = map.keySet();
//        for (Object o : set) {
//            System.out.println(map.get(o));
//        }
//        System.out.println(map.containsKey("zhangsan"));
//
//        Collection values = map.values();
//        map.containsValue("1");
//
//        System.out.println(map);

        //TODO 获取键值对对象
//        Set<Map.Entry<String, String>> entries = map.entrySet(); //Entry表示map中的一个键值对
//        for (Map.Entry<String, String> entry : entries) {
//            System.out.println(entry);
//            System.out.println(entry.getKey() + "=" + entry.getValue()); //和上面这行输出的完全一样，一个意思
//        }

//        map.remove("zhangsan");
        map.remove("zhangsan", "1"); //只有当zhangsan = 1时才会删除

//        map.size();
//        map.isEmpty();
//        map.clear();
//        map.clone();

        System.out.println(map);

    }
}
