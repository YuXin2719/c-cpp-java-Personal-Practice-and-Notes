# Java基础复习

2023 4 28

## java基础常识

![屏幕截图 2023-04-28 164539](E:\c.---c.---java-exercise\photo\屏幕截图 2023-04-28 164539.png)![屏幕截图 2023-04-28 163333](E:\typora\photo\屏幕截图 2023-04-28 163333.png)

idea常用快捷键:

1. ctrl + D : 复制当前行
2. ctrl + R : 替换当前文字内容

![屏幕截图 2023-04-28 173433](E:\c.---c.---java-exercise\photo\屏幕截图 2023-04-28 173433.png)

Java的第一段代码

```java
package chapter01;

public class Java02_HelloJava {
    public static void main(String[] args){
        System.out.println("Hello Java");
    }
}

```



## 变量原理

```java
package chapter02;

public class Java01_Variable {
    public static void main(String[] args) {

        //TODO 变量
        //所谓的变量其实就是可以改变的向量存储
        //1.变量的声明
        //数据类型  变量的名称
        String name;//String是一个类，表示一串字符序列

        //2.变量的赋值
        //变量名称 = 数据
        name = "zhangsan";

        //3.变量的使用
        //直接访问变量的名称即可
        System.out.println(name);

        //将变量的声明和赋值在一行代码中完成
        String username = "lisi";
        System.out.println(username);

        //在使用变量之前，必须给变量赋值，将这个操作称之为变量的初始化
    }
}

```



## 标识符

```java
package chapter02;

public class Java02_Identifier {
    public static void main(String[] args){

        //TODO 标识符
        //表示数据的符号，称之为标识符
        //变量名称就是标识符
        //标识符主要用于起名
        String name = "zhangsan";

        //TODO 标识符的命名规则
        //1.英文拉丁字母
        String username = "zhangsan";
        String xingming = "lisi";

        //2.符号
        //@,#,%,$
        //标识符只能采用下划线和美元 _ $ ,其他符号不能使用，称之为特殊符号
        //空格也属于特殊符号，所以不能作为标识符使用

        //3.数字
        //阿拉伯数字 0 到 9 可以作为标识符使用,但是不能开头
        //数字如果在标识符的开头位置，那么会被识别为数字，而不是标识符，所以会发生错误
        //String 1name = "zhangsan";
        String name1 = "zhangsan";

        //4.在大括号的范围内，标识符不能重复
        String name2 = "zhangsan";
        //标识符是区分大小写的
        String Name = "zhangsan";

        //5.Java语言中预先定义好了一些标识符名称，称之为关键字或保留字
        //可以使用大写来实现关键字名称的定义，但是容易造成歧义，不建议使用
        String Public = "zhangsan";

        //6.驼峰标识，组合的单词第二个大写
        String userName = "zhangsan";

        //7.标识符的长度
        //没有长度的限制

    }
}

```



## 数据类型

![屏幕截图 2023-04-29 011933](E:\c.---c.---java-exercise\photo\屏幕截图 2023-04-29 011933.png)

### 基本数据类型

```java
package chapter02;

public class Java03_Datatype_1 {
    public static void main(String[] args){

        //TODO 基本数据类型

        //TODO 1.整数类型
        //byte : 8位
        byte b = 10;
        //short : 16位
        short s = 10;
        //int : 32位
        int i = 10;
        //long : 64位
        long lon = 10;

        //TODO 2.浮点类型：含有小数点的数据类型
        //根据计算精度分为
        //默认情况下，小数点的数据会被识别为精度较高的双精度double类型
        //float : 单精度浮点类型，数据需要使用F（f）结尾
        float f = 1.0F;
        //double : 双精度浮点类型
        double d = 2.0;

        //TODO 3.字符类型
        //所谓的字符类型，其实就是使用符号表示文字内容
        char c ='@';

        //TODO 4.布尔类型
        //true,false,表示判断条件是否成立，如果成立，取值为true，如果不成立，那么取值为false
        boolean bln = true;

    }
}

```

### 数据类型之间的转换

```java
package chapter02;

public class Java03_Datatype_2 {
    public static void main(String[] args){

   //TODO 数据类型的转换

        String name = "zhangsan";
        int age = 30;

        //byte -> short -> int -> long -> float -> double
        byte b =10;

        short s = b;

        int i = s;

        long lon = i;

        float f = lon;

        double d = f;

        //java中范围小的值可以转换为范围大的数据，但是范围大的数据无法直接转换为范围小的数据
        //如果想要将范围大的数据转换为范围小的数据，那么需要使用小括号进行强制转换

        int i1 = (int)d;

    }
}

```

### 引用数据类型

```java
package chapter02;

public class Java03_Datatype_3 {
    public static void main(String[] args){

    //TODO 引用数据类型，其实就是可以被引用的数据类型
        String s = "abc";

    }
}

```



## 运算符

![屏幕截图 2023-04-29 122215](E:\c.---c.---java-exercise\photo\屏幕截图 2023-04-29 122215.png)



### 算数运算符：一元运算符+二元运算符

```java
package chapter02;

public class Java04_Operator {
    public static void main(String[] args){

        //TODO 运算符
        //所谓的运算符就是参与数据运算的符号。Java定义的，无法自行定义

        //TODO 表达式
        //所谓的表达式就是采用运算符和数据连接在一起形成符合Java语法规则的指令代码，称之为运算符

        //TODO 算数运算符  最小使用的类型是int类型
        //1.二元运算符 ： 两个元素参与运算的运算符，1 + 2
        //  算术表达式 = 元素1 二元运算符 元素2
        //  这个表达式是有结果的，就需要有类型，这里的类型是元素中类型最大的那一种，最小使用的类型是int类型
        System.out.println(1 + 2); // 3
        System.out.println(2 - 2); // 0
        System.out.println(3 * 2); // 6
        System.out.println(4 / 2); // 2
        System.out.println(5 % 2); // 1 （取余，模运算）

        System.out.println(1 / 2); // 0 （int,int）（选俩元素中类型最大的那一种） => int  本来是0.5，这里把小数去掉
        System.out.println(1.0 / 2);//0.5 (double,int) => double

        byte b1 = 10;
        byte b2 = 10;
        //b1 + b2; (byte,byte) 不行
        byte b3 = (byte)(b1 + b2);//强制转换

        System.out.println(1 + 2 * 3);//7
        System.out.println((1 + 2) * 3);//9

        //2.一元运算符 ： 一个元素参与运算的运算符
        //++,--
        //++ 运算符的本质其实就是加1操作的简化版本，自增运算符  自减运算符同理
        //int i = 0;
        //int j = i;
        //i = i + 1;
        int i = 0;
        int j = i++;//TODO 先赋值后运算 先将i赋值给j，然后i = i + 1，++i就是先运算后赋值
        System.out.println("i = " + i);
        System.out.println("j = " + j);

    }
}

```



### 赋值运算符

```java
package chapter02;

public class Java04_Operator_1 {
    public static void main(String[] args){

        //TODO 运算符 - 赋值运算符
        //等号就是赋值运算符：将等号右边表达式的结果赋值给左边的变量
        //赋值运算符需要考虑类型的关系
        String name = "zhangsan";
        byte b = 10;
        short s = b;

        //TODO 复合赋值运算符： += ...
        //  如果元素进行运算后重新赋值给自己，那么可以将运算和赋值的符号进行简化
        //  如果使用了复合赋值运算符，那么数据的类型不会发生变化
        int i = 1;
        //i = i + 1;
        i += 1; //先加后等
        System.out.println(i);

        byte b1 = 10;
        //b1 = b1 + 20; //+是二元运算符，最小适用类型是int //int =>byte
        b1 += 20; //复合赋值运算符不会让数据类型发生变化

    }
}

```



### 关系运算符

```java

```

