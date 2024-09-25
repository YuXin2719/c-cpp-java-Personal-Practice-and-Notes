package chapter02;

public class Java03_Datatype_1 {
    public static void main(String[] args) {

        //TODO 基本数据类型

        //TODO 1.整数类型
        //byte 8位
        byte b = 10;
        //short 16位
        short s = 10;
        //int 32位
        int i = 10;
        //long 64位
        long l = 10;

        //TODO 2.浮点类型：含有小数点的数据类型
        //根据计算精度分为
        //默认情况下，小数点的数据类型会被识别为精度较高的double类型
        //TODO float：单精度浮点类型，数据需要使用F或者f结尾
        float f = 1.0f;
        //double：双精度浮点类型
        double d = 1.0;

        //TODO 3.字符类型
        //字符类型就是使用符号来标识文字内容
        char c = '@';

        //TODO 4.布尔类型
        //true，false，标识判断条件是否成立，如果成立，取值为true，如果不成立，取值为false
        boolean bln = true;
    }
}
