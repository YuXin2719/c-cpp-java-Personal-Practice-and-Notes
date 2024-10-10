package chapter05;

public class Java04_Object_String_2 {
    public static void main(String[] args) throws Exception {

        //TODO 常见类和对象

        //StringBuilder:构建字符串

//        String s = "";
//        for (int i = 0; i < 100; i++) {
//            s = s + i; //0123,...
//        }
//        System.out.println(s);

        //"a" + "b" => "ab"

//        StringBuilder stringBuilder = new StringBuilder();
//        for (int i = 0; i < 100; i++) {
//            stringBuilder.append(i);
//        }
//        System.out.println(stringBuilder.toString());

        StringBuilder stringBuilder = new StringBuilder();
        stringBuilder.append("abc"); //将"abc"追加到stringBuilder的末尾
        System.out.println(stringBuilder.toString());
        System.out.println(stringBuilder.length());
        System.out.println(stringBuilder.reverse()); //反转字符串
        stringBuilder.insert(1, "d"); //在b前面插入d adbc
    }
}