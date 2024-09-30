package chapter04;

public class Java16_Object_Recursion {
    public static void main(String[] args) {

        //TODO 面向对象 - 递归
        //所谓的递归:方法调用自身,称之为递归方法
        //例如想求20以内的奇数之和
        //1 + 3 + 5 + 7 + 9 + ... + 19
        int result = computeAP(20);
        System.out.println(result);

        //阶乘 : 5! => 5 * 4 * 3 * 2 * 1
        //0的阶乘为1
        //一个大于1的阶乘等于这个数乘以这个数减一的阶乘
        int result1 = computeFactorial(5);
        System.out.println(result1);

        //1.递归方法应该有跳出的逻辑
        //2.调用自身时,传递的参数应该有规律
    }

    /*
    1是递归边界
    先不断的递归调用,到达边界之后开始逐步返回结果向上累加

    计算过程:
    当第一次调用computeAP(20)时，由于 20 是偶数，先将其变为 19。
    然后判断 19 不等于 1，执行return 19 + computeAP(17)。
    接着调用computeAP(17)，同样进行判断和计算，得到17 + computeAP(15)。
    以此类推，不断进行递归调用，直到num等于 1 时，开始返回结果并逐步向上累加。
    最终，通过这种递归的方式，实现了对 20 以内奇数的累加，得到结果 100。
     */
    public static int computeAP(int num) {
        num = num % 2 == 0 ? num - 1 : num;
        if (num == 1) {
            return 1;
        } else {
            return num + computeAP(num - 2);
        }
    }

    public static int computeFactorial(int num) {
        if (num <= 1) {
            return 1;
        } else {
            return num * computeFactorial(num - 1);
        }
    }
}