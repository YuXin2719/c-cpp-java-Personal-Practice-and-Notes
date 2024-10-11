package chapter05;

import java.text.SimpleDateFormat;
import java.util.Calendar;
import java.util.Date;

public class Java07_Object_Date {
    public static void main(String[] args) throws Exception {

        //TODO 常见类和对象

        //日历类
        //获取当前日期的日历对象
        Calendar instance = Calendar.getInstance();
        System.out.println(instance);

        System.out.println(instance.get(Calendar.YEAR));
        System.out.println(instance.get(Calendar.MONTH)); //从0开始,所以假如现在是10月,但是显示9
        System.out.println(instance.get(Calendar.DATE));
        System.out.println(instance.get(Calendar.DAY_OF_WEEK)); //周日是 1，周一为 2，周二为 3，周三为 4
//        System.out.println(instance.get(Calendar.DAY));

        instance.setTime(new Date()); //让日历指向某一天
        instance.add(Calendar.YEAR, -1); //将当前的年份减一年,其他日,月同理
    }
}