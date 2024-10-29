package chapter06;

public class Java07_Exception {
    public static void main(String[] args) throws Exception {

        //TODO - 异常
        User8 user8 = new User8();

        int i = 10;
        int j = 0;

        try {
            user8.test(i, j);
        } catch (Exception e) {
            e.printStackTrace();
        }

    }
}

class User8 {
    //异常转换
    //如果方法中可能会出现问题,那么需要声明,告诉其他人,这个方法可能会出现问题
    //此时需要使用关键字throws
    //如果程序中需要手动抛出异常对象,那么需要使用throw关键字,然后new出异常对象
    public void test(int i, int j) throws Exception {
        try {
            System.out.println(i / j);
        } catch (ArithmeticException e) {
            throw new Exception();
        }

    }
}