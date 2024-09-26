package chapter02;

public class Java04_Operator_3 {
    public static void main(String[] args) {

        //TODO 运算符 - 逻辑运算符
        //逻辑运算符其实就是用于描述多个条件表达式之间的关系的运算符
        //TODO 基本语法结构：
        //变量 = （条件表达式1） 逻辑运算符 （条件表达式2）
        //结果变量的类型是布尔类型

        //TODO 逻辑运算符：&，称之为与运算
        //与运算，要求两个条件表达式都必须计算出结果，只有两个结果都为true的时候，最终结果为true，其他情况都为false
        int i = 10;
        boolean result = (i > 5) & (i < 20);
        System.out.println(result);

        //TODO 逻辑运算符：|，称之为或运算
        //或运算，要求两个表达式都能计算出结果，只要有任何一个结果为true，那么最后结果都为true
        //两个表达式结果都为false，最终结果才为false
        int j = 10;
        boolean result1 = (j > 5) | (j < 9);
        System.out.println(result1);

        //TODO 逻辑运算符：&&，称为短路与运算
        //短路与运算，会根据第一个条件表达式的结果来判断，是否执行第二个表达式
        //如果第一个表达式的结果为false，那么无需执行第二个表达式
        int t = 10;
        int y = 20;
        boolean result2 = (t > 10) && (++y > 30);
        System.out.println(result2);
        System.out.println(y); //20

        //TODO 逻辑运算符：||，称为短路或运算
        //短路与运算，会根据第一个条件表达式的结果来判断，是否执行第二个表达式
        //如果第一个表达式的结果为true，第二个表达式无需执行
        int n = 10;
        int s = 20;
        boolean result3 = (n == 10) || (++s > 30);
        System.out.println(result3);
        System.out.println(s); //20

        //TODO 逻辑运算符：！，逻辑非（相反）运算符
        int b = 10;
        boolean result4 = i == 10;
        System.out.println(!result4); //false
    }
}
