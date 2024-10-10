package chapter05;

public class Java04_Object_String_1 {
    public static void main(String[] args) throws Exception {

        //TODO 常见类和对象
        //TODO 字符串操作

        //TODO 拼接:将多个字符串拼在一起
//        String s = "a" + "b"; //"ab"
//        String s1 = "ab"; //上下两种写法完全没有区别
//
//        String s2 = "abc" + 1 + 2; //abc12
//        String s3 = 1 + "abc" + 2; //1abc2
//        String s4 = 1 + 2 + "abc"; //3abc TODO 加号会从左到右顺序计算
//
//        System.out.println(s.hashCode());
//        System.out.println(s1.hashCode());
//        System.out.println(s2);
//        System.out.println(s3);
//        System.out.println(s4);
//
//        System.out.println(s1.concat("abc")); //ababc concat()字符串拼接功能

        //TODO 字符串的比较
//        String a = "a";
//        String b = "A";

        //判断是否相等,字符串的每一个字符都相等才是相等
//        System.out.println(a.equals(b));
        //忽略大小写的相等
//        System.out.println(a.equalsIgnoreCase(b));

        //比较大小
        //i = 正数,a > b
        //i = 负数,a < b
        //i = 0,a = b

//        byte b1 = (byte) 'A';
//        byte b2 = (byte) 'a';
//        System.out.println("A = " + b1);
//        System.out.println("a = " + b2);
//
//        int i = a.compareTo(b); //得出的是字节码的差值
//        System.out.println(i);
        //忽略大小写的比较
//        System.out.println(a.compareToIgnoreCase(b));

        //TODO 字符串的截断操作:截取字符串的操作
//        String s = "  Hello World   ";
        //子字符串
        //substring方法用于截取字符串,现在传递两个参数
        // 第一个参数标识截取字符串的起始位置(索引,包含)
        // 第二个参数标识截取字符串的结束位置(索引,不包含)
        //包前不包后
//        System.out.println(s.substring(0, 3));
//        System.out.println(s.substring(0, "Hello".length()));
//        System.out.println(s.substring(6, s.length()));
        //substring方法如果只传递一个参数,那么就表示从指定位置开始截取字符串,然后截取到最后
//        System.out.println(s.substring(6));

        //分解字符串:根据指定的规则对字符串进行分解,可以将一个完整的字符串,分解成几个部分
//        String[] s1 = s.split(",");
//        System.out.println(s1.length);
//        for (String string : s1) {
//            System.out.println(string);
//        }

        //TODO trim:去掉字符串的首尾空格的意思
//        System.out.println("!" + s.trim() + "!");

        //TODO 字符串的替换
//        String s = "Hello World zhangsan"; //想得到的替换结果是Hello Java Java
//        //替换
//        System.out.println(s.replace("World", "Java"));
//        //replaceAll按照指定的规则进行替换
//        System.out.println(s.replaceAll("World|zhangsan", "Java"));

        //TODO 字符串的大小写转换
//        String s = "Hello World";
//
//        System.out.println(s.toLowerCase()); //全部变成小写
//        System.out.println(s.toUpperCase()); //全部变成大写
//        String className = "user"; //u + ser
//
//        String s1 = className.substring(0, 1); //u
//        String s2 = className.substring(1); //ser
//
//        System.out.println(s1.toUpperCase() + s2);

        //TODO 字符串的查找
        String s = " ";
//        char[] chars = s.toCharArray(); //得到字符数组
//        byte[] bytes = s.getBytes("UTF-8"); //得到字节码数组
        //charAt可以传递索引定位字符串中指定位置的字符
//        System.out.println(s.charAt(1));
        //indexOf方法用于获取数据在字符串中第一次出现的位置
//        System.out.println(s.indexOf("World")); //找到该字符串在原字符串的位置
        //lastIndexOf方法用于获取数据在字符串中最后一次出现的位置
//        System.out.println(s.lastIndexOf("World"));

        //是否包含指定的字符串,返回布尔类型
//        System.out.println(s.contains("Hello123"));
        //判断字符串是否以指定的数据开头,返回布尔类型
//        System.out.println(s.startsWith("Hello"));
        //判断字符串是否以指定的数据结尾,返回布尔类型
//        System.out.println(s.endsWith("World"));
        //判断字符串是否为空,空格其实是一个特殊的字符,所以看不到,但是不为空
        System.out.println(s.isEmpty());


    }
}