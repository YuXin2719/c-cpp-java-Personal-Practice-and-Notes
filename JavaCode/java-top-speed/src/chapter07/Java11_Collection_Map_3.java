package chapter07;

import java.util.HashMap;
import java.util.Iterator;
import java.util.Set;

public class Java11_Collection_Map_3 {
    public static void main(String[] args) throws Exception {

        //TODO 集合 - Map
        HashMap<String, Integer> map = new HashMap<String, Integer>();
        map.put("a", 1);
        map.put("b", 2);
        map.put("c", 3);

        Set<String> keys = map.keySet();

//        for (String key : keys) {
//            if ("b".equals(key)) {
//                map.remove(key);
//            }
//            System.out.println(map.get(key));
//        }

        //TODO 迭代器
        Iterator<String> iterator = keys.iterator();
        //hasNext方法用于判断是否存在下一条数据
        while (iterator.hasNext()) {
            //获取下一条数据
            String key = iterator.next();
            if ("b".equals(key)) {
                //remove方法只能对当前数据删除
                iterator.remove();
            }
            System.out.println(map.get(key));
        }


    }
}
