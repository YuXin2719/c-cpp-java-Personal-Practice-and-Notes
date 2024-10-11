package chapter05;

import java.text.SimpleDateFormat;
import java.util.Calendar;
import java.util.Date;
import java.util.Random;
import java.util.UUID;

public class Java08_Object_Date_Util {
    public static void main(String[] args) throws Exception {

        //TODO 常见类和对象
        //封装工具类

        System.out.println(StringUtil.isEmpty(null));
        System.out.println(StringUtil.isEmpty(""));
        System.out.println(StringUtil.isEmpty("    "));
        System.out.println(StringUtil.isEmpty("abc"));

        System.out.println(StringUtil.makeString());
        System.out.println(StringUtil.makeString("abcdefg123456", 6));

        System.out.println(StringUtil.formatDate(new Date(), "yyyy-MM-dd"));
        System.out.println(StringUtil.parseDate("2024-10-11", "yyyy-MM-dd"));
    }
}

//字符串工具类
//1.工具类不应该创建对象才能使用,也就意味着,可以直接使用类中的属性和方法,一般都声明为静态的
//2.工具类对外提供的属性和方法都应该是公共的
//3.为了使用者开发方便,应该尽量提供丰富的方法和属性
class StringUtil {
    //非空判断
    public static boolean isEmpty(String s) {
        //1.如果字符串为null,为空
        //2.如果字符串为空字符串,为空
        //3.如果字符串全都是空格,为空
        //其中23是可以一起判断的
        if (s == null || "".equals(s.trim())) {
            return true;
        }

        return false;
    }

    public static boolean isNotEmpty(String s) {
        return !isEmpty(s);
    }

    //生成随机字符串
    public static String makeString() {
        return UUID.randomUUID().toString();
    }

    public static String makeString(String from, int len) {
        if (len < 1) {
            return "";
        } else {
            char[] chars = from.toCharArray();
            StringBuilder stringBuilder = new StringBuilder();
            for (int i = 0; i < len; i++) {
                Random random = new Random();
                int n = random.nextInt(chars.length);
                char c = chars[n];
                stringBuilder.append(c);
            }
            return stringBuilder.toString();
        }
    }

    //转换字符串 : ISO8859-1 => str => UTF-8
    //source 来源
    public static String transform(String source, String encodeFrom, String encodeTo) throws Exception {
        byte[] bytes = source.getBytes(encodeFrom);
        return new String(bytes, encodeTo);
    }

    //字符串转换为日期
    //parse 解析,format 格式
    public static Date parseDate(String dateString, String format) throws Exception {
        SimpleDateFormat simpleDateFormat = new SimpleDateFormat(format);
        return simpleDateFormat.parse(dateString);
    }

    //日期转换为字符串
    public static String formatDate(Date date, String format) throws Exception {
        SimpleDateFormat simpleDateFormat = new SimpleDateFormat(format);
        return simpleDateFormat.format(date);
    }

}