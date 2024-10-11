package chapter05;

import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.SimpleTimeZone;

public class Java06_Object_Date {
    public static void main(String[] args) throws Exception {

        //TODO 常见类和对象
        //Date:日期类
        //时间戳:单位毫秒
        System.out.println(System.currentTimeMillis());

        //Date:日期类
        //Calender:日历类
        Date date = new Date();
        System.out.println(date);

        //Java格式化日期格式:
        //y (Y) -> 年 -> yyyy
        //m (M) -> MM : 月份 , mm : 分钟
        //d (D) -> dd : 一个月中的日期 , D : 一年中的日期
        //h (H) -> h : 12进制 , HH : 24进制
        //s (S) -> s : 秒 , S : 毫秒

        //Date -> String
        SimpleDateFormat sdf = new SimpleDateFormat("yyyy-MM-dd");
        String format = sdf.format(date); //转换为指定格式的字符串
        System.out.println(format);

        //String -> Date
        String DateString = "2022-06-01";
        Date parse = sdf.parse(DateString);//对字符串进行解析,转换为Date
        System.out.println(parse);

        //根据时间戳构建指定的日期对象
//        date.setTime(System.currentTimeMillis());
        //获取时间戳
//        date.getTime();
        System.out.println(parse.before(date));
        System.out.println(parse.after(date));
    }
}