package chapter06;

public class Java04_Exception {
    public static void main(String[] args) {

        //TODO - 异常
        //3.索引越界:ArrayIndexOutOfBoundsException
        String[] names = new String[3];
        names[0] = "zhangsan";
        names[1] = "lisi";
        names[2] = "wangwu";
        if (names.length == 4) {
            names[3] = "zhaoliu";
        }

        for (int i = 0; i < names.length; i++) {
            System.out.println(names[i]);
        }

        //4.字符串索引越界
        String s = "abc";
        System.out.println(s.charAt(0));

    }
}
