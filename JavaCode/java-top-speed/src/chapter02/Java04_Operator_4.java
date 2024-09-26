package chapter02;

public class Java04_Operator_4 {
    public static void main(String[] args) {

        //TODO 运算符 - 三元运算符
        //所谓的三元运算符其实就是三个元素参与运算的运算符
        //基本语法结构：
        //变量 = （条件表达式）？（任意表达式1）：（任意表达式2）
        //运算规则：判断条件表达式的结果，如果为true，那么执行表达式1的值，如果为false，执行表达式2的值
        int i = 10;
        int j = 20;

        int k = (i == 10) ? 1 + 1 : 2 + 2;
        System.out.println(k);
    }
}
