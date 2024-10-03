package chapter04;

public class Java25_Object {
    public static void main(String[] args) {

        //TODO 面向对象
        //类的主要两种
        //1.主要用于编写逻辑
        //2.主要用于建立数据模型(下面的例子User25就数据数据模型)
        //TODO 重点是建立数据模型(bean)
        //TODO bean类的设计规范:bean规范
        //1.类要求必须含有无参,公共的构造方法
        //2.属性必须私有化,然后提供公共的,set,get构造方法
        User25 user = new User25();
        user.setAccount("admin");
        user.setPassword("admin");
        System.out.println(login(user));
    }

    //登录功能不应该设置在用户类里,因为不需要每个用户都有自己的登录方法,这个功能交给服务器就好了(目前这个类代指服务器)
    public static boolean login(User25 user) {
        if (user.getAccount().equals("admin") && user.getPassword().equals("admin")) {
            return true;
        } else {
            return false;
        }

    }
}

class User25 {
    //用户的账号和密码应该是私有的,所以这里的属性应该是private,外界访问或者修改应该提供对应的方法
    private String account;
    private String password;

    public String getAccount() {
        return account;
    }

    public String getPassword() {
        return password;
    }

    public void setAccount(String account) {
        this.account = account;
    }

    public void setPassword(String password) {
        this.password = password;
    }
}