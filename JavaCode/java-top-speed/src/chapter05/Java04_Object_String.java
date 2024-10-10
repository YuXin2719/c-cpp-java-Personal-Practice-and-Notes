package chapter05;

public class Java04_Object_String {
    public static void main(String[] args) throws Exception {

        //TODO 常见类和对象
        //TODO 字符串连续字符组成形成的数据整体
        //字符串类:java.long.String
        //字符串,字符,字节的关系
        String name = "zhangsan";
        String name2 = "zhangsan";
        String name3 = "zhangsan";
        String name4 = "zhangsan";
        String name1 = new String("zhangsan"); //ctrl + p 可以显示所有构建方法

        //char数组可以变成字符串
        char[] cs = {'a', '中', '国'};
        String s = new String(cs);
        System.out.println(s);

        byte[] bs = {-28, -72, -83, -27, -101, -67}; //三个字节得到一个字符,前三个是中,后三个是国
        String s1 = new String(bs, "UTF-8");
        System.out.println(s1);

        //转义字符: \" => 文字内容的双引号
        //\'(') , \t(制表符,tab键) , \n(换行) , \\(\)
        String s2 = "\"";
        System.out.println(s2);
        System.out.println("\'");
        System.out.println("a\tb");
        System.out.println("c\nd");
        System.out.println("e\\f");
    }
}