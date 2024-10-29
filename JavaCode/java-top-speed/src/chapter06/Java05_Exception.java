package chapter06;

public class Java05_Exception {
    public static void main(String[] args) {

        //TODO - 异常
        //5.格式化异常:NumberFormatException
//        String s = "a123";
//        Integer i = Integer.parseInt(s);
//
//        System.out.println(i);

        //6.类型转换错误:ClassCastException
        Object obj = new User5();
        if (obj instanceof Emp5) { //判断对象是不是特定类型的实例
            Emp5 emp = (Emp5) obj;
        }
    }
    
}

class User5 {

}

class Emp5 {

}