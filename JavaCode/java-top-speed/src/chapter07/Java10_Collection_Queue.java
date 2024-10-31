package chapter07;

import java.util.ArrayList;
import java.util.concurrent.ArrayBlockingQueue;

public class Java10_Collection_Queue {
    public static void main(String[] args) throws Exception {

        //TODO 集合 - Collection - Queue
        //ArrayBlockingQueue : Array + Blocking(阻塞,堵住) + Queue
        ArrayBlockingQueue queue = new ArrayBlockingQueue(3); //底层数组容量,这里意味着最多放三条数据
        //add方法如果增加不了数据,直接发生错误
//        queue.add("zhangsan");
//        queue.add("lisi");
//        queue.add("wangwu");
//        queue.add("zhaoliu"); //发生错误,Queue full(满了)

//        queue.put("zhangsan");
//        System.out.println("第一个人挂号");
//        queue.put("lisi");
//        System.out.println("第二个人挂号");
//        queue.put("wangwu");
//        System.out.println("第三个人挂号");
//        //三个数据已满,之后的数据被阻塞
//        queue.put("zhaoliu");
//        System.out.println("第四个人挂号");

        boolean zhangsan = queue.offer("zhangsan"); //返回boolean类型表示数据是否放入成功
        System.out.println(zhangsan);
        boolean lisi = queue.offer("lisi");
        System.out.println(lisi);
        boolean wangwu = queue.offer("wangwu");
        System.out.println(wangwu);
        boolean zhaoliu = queue.offer("zhaoliu");
        System.out.println(zhaoliu);

//        System.out.println(queue.poll()); //poll从集合中取出数据(取最先放入的那个数据),取出后集合内就没有取出的数据了
//        System.out.println(queue.poll());
//        System.out.println(queue.poll());
//        System.out.println(queue.poll());

        System.out.println(queue.take());
        System.out.println(queue.take());
        System.out.println(queue.take());
        //三个数据已经全部取出,这时处于阻塞状态,等新的数据进入还会继续取出
        System.out.println(queue.take());

//        queue.size();
//        queue.isEmpty();
//        queue.clear();
//        queue.contains();

        System.out.println(queue);

    }
}
