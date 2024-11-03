package chapter07;

import java.util.Arrays;
import java.util.List;

public class Java12_Collection_Util {
    public static void main(String[] args) throws Exception {

        //TODO 集合 - Arrays
        int[] is = {3, 5, 1, 2, 4};
        int[] is1 = {1, 2, 3, 4, 5};
        int[] is2 = {1, 2, 3, 4, 5, 6};

        //静态方法可以直接使用
        System.out.println(Arrays.toString(is));
        System.out.println(is);

        //构建集合的同时传入数据
        List<Integer> list = Arrays.asList(1, 2, 3, 4, 5);

        //排序(默认为升序)
        Arrays.sort(is);
        System.out.println(Arrays.toString(is));

        //二分查找法,必须是排序后的数组,下面是查找5所在的位置
        System.out.println(Arrays.binarySearch(is, 5));

        //数组的比较,相同的位置每个值相等就是true
        System.out.println(Arrays.equals(is2, is1));


    }
}
