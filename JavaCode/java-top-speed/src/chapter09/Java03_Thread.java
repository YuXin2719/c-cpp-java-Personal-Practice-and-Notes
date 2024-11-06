package chapter09;

public class Java03_Thread {
    public static void main(String[] args) throws Exception {

        //TODO 线程 - 休眠
        //休眠3秒钟
        while (true) {
            Thread.sleep(3000); //单位:毫秒
            System.out.println("main线程执行完毕");
        }

    }
}
