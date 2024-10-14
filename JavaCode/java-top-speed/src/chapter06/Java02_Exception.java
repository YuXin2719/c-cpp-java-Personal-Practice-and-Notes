package chapter06;

public class Java02_Exception {
    public static void main(String[] args) {

        //TODO - 异常
        /*

        异常处理语法:

        TODO try : 尝试
        TODO catch : 捕捉
            捕捉多个异常的时候,需要先捕捉范围小的异常,然后再捕捉范围大的异常
        TODO finally : 最终

        try {
            可能会出现异常的代码
            如果出现异常,那么JVM会将异常进行封装,形成一个具体的异常类,然后将这个异常抛出
            所有的异常对象都可以被抛出
        } catch ( 抛出的异常对象 对象引用 ) {
            异常的解决方案
        } catch() {

        } finally {
            无论解决没解决,最终一定会执行的代码逻辑
        }

         */
        int i = 0;
        int j = 0;

        try {
            j = 10 / i;
        } catch (ArithmeticException e) {
//            e.getMessage(); //错误的消息
//            e.getCause(); //错误的原因
//            e.printStackTrace(); //打印异常发生时堆栈跟踪信息
            i = 10;
            j = 10 / i;
        } finally {
            System.out.println("最终执行的代码");
        }

        System.out.println(j);

    }
}