package chapter04;

public class Java06_Object_Method {
    public static void main(String[] args) {

        //TODO 面向对象 - 方法
        //声明的语法:void 方法名() { 逻辑代码 }
        //声明的语法(补充):[方法的返回值类型][void] 方法名() { 逻辑代码 }
        //这里的void表示方法的结果:没有结果

        //方法的调用方式:对象.方法名()

        //使用用户账号和密码进行登陆
        //名词:用户,账号,密码
        //动词:登陆
        User06 user = new User06();
        boolean registerResult = user.register();
        if (registerResult) {
            System.out.println("注册成功");
            boolean loginResult = user.login();
            if (loginResult) {
                System.out.println("登录成功");
            } else {
                System.out.println("登录失败");
            }
        } else {
            System.out.println("注册失败");
        }

    }
}

class User06 {
    String cccount;
    String password;

    boolean register() { //注册
        System.out.println("用户注册");
        //返回结果:false
        return true;
    }

    boolean login() { //登陆
        System.out.println("用户登陆");
        return false;
    }
}