package chapter04;

import java.util.*;
import java.sql.Date;

public class Java10_Object_Import {
    public static void main(String[] args) {

        //TODO 面向对象 - Import
        //import主要用于在使用类之前准备好
        //import语句只能使用在package后,class前
        //import关键字可以多次使用,导入多个类
        //如果同一个包中需要导入大量的类,那么可以使用通配符*简化操作
        //如果import了不同包中相同的类,那么还是需要使用时增加包名

        //chapter04.Java10_Object_Import
//        java.long.String name="zhangsan";
        String name1 = "zhangsan";

        java.util.Date d = new java.util.Date();
        new ArrayList();

        new chapter04.Java10_Object_Import();
        new Java10_Object_Import();
        new User10();
    }
}

class User10 {

}
