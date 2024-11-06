package chapter09;

public class Java01_Thread {
    public static void main(String[] args) {

        //TODO 线程
        //Thread是线程类
        //currentThread 方法用于获取当前正在运行的线程
        //getName 方法用于获取线程的名称

        //TODO 创建线程
//        Thread t = new Thread();
        MyThread t = new MyThread();

        //TODO 启动线程
        t.start();

        //main方法运行在main线程中
        System.out.println(Thread.currentThread().getName());
    }
}

//TODO 声明自定义线程类
class MyThread extends Thread {
    //重写运行指令

    @Override
    public void run() {
        System.out.println("MyThread : " + Thread.currentThread().getName());
    }
}