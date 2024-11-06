package chapter09;

import com.sun.webkit.ThemeClient;

import javax.swing.plaf.TableHeaderUI;
import java.util.Hashtable;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;

public class Java06_Thread_Syn {
    public static void main(String[] args) throws Exception {

        //TODO 线程 - 同步
        //synchronized - 同步关键字
        //多个线程访问同步方法时,只能一个一个访问,同步操作
//        new Hashtable<>(); //同步类型的,安全
        //synchronized关键字还可以修饰代码块,称之为同步代码块
        /*
        synchronized( 用于同步的对象 ){
            处理逻辑
        }

         */
        Num num = new Num();

        User user = new User(num);
        user.start();

        Bank bank = new Bank(num);
        bank.start();

    }
}

class Num {

}

class Bank extends Thread {
    private Num num;

    public Bank(Num num) {
        this.num = num;
    }

    public void run() {

        synchronized (num) {
            try {
                Thread.sleep(2000);
            } catch (InterruptedException e) {
                throw new RuntimeException(e);
            }
            System.out.println("9:00,开门,开始叫号");
            num.notifyAll(); //用于唤醒在对象监视器上等待的所有线程
        }

    }
}

class User extends Thread {
    //    public synchronized void test() {
//
//    }
    private Num num;

    public User(Num num) {
        this.num = num;
    }

    public void run() {

        synchronized (num) {
            System.out.println("我是号码1,银行还没开门,我需要等一会儿");
            try {
                num.wait();
            } catch (InterruptedException e) {
                throw new RuntimeException(e);
            }
            System.out.println("叫到我的号了,该我办业务了");
        }

    }
}