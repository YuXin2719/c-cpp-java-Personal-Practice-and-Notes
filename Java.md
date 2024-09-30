# Java基础复习

配套课程：【尚硅谷】7天搞定Java基础，Java零基础极速入门https://www.bilibili.com/video/BV1o841187iP/?p=5

2023 4 28

# 一、java基础常识

![屏幕截图 2023-04-28 164539](E:\c.---c.---java-exercise\photo\屏幕截图 2023-04-28 164539.png)

<img src="image-20240925214630883.png" alt="image-20240925214630883" style="zoom:67%;" />

- JDK：java编程环境
- JRE：java运行环境
- JVM：java虚拟机

**编译器文件：**javac.exe

**源文件：**xxx.java

**字节码文件/类文件：**xxx.class

**启动Java虚拟机文件：**java.exe



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



## 1.变量原理

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



## 2.标识符

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



# 二、数据类型

![屏幕截图 2023-04-29 011933](E:\c.---c.---java-exercise\photo\屏幕截图 2023-04-29 011933.png)

## 1.基本数据类型

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

## 2.数据类型之间的转换

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

## 3.引用数据类型

```java
package chapter02;

public class Java03_Datatype_3 {
    public static void main(String[] args) {

        //TODO 引用数据类型
        //所谓的引用数据类型，其实就是可以被引用的数据类型
        String s = "abc";

        int i = 10; //10直接存储在向量存储内，没有指向其他数据存储，所以不是引用数据类型
    }
}

```



# 三、运算符

![屏幕截图 2023-04-29 122215](E:\c.---c.---java-exercise\photo\屏幕截图 2023-04-29 122215.png)



## 1.算数运算符：一元运算符+二元运算符

```java
package chapter02;

public class Java04_Operator {
    public static void main(String[] args) {

        //TODO 运算符
        //所谓的运算符就是参与数据运算的符号。Java定义的，无法自行定义

        //TODO 表达式
        //所谓的表达式就是采用运算符和数据连接在一起形成符合Java语法规则的指令代码，称之为表达式

        //TODO 算数运算符  最小使用的类型是int类型
        //1.二元运算符 ： 两个元素参与运算的运算符，1 + 2
        //  TODO 算术表达式 = 元素1 二元运算符 元素2
        //  TODO 这个表达式是有结果的，就需要有类型，这里的类型是元素中类型最大的那一种
        //   TODO 最小使用的类型是int类型
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
        byte b3 = (byte) (b1 + b2);//强制转换

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



## 2.赋值运算符

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



## 3.关系运算符

```java
package chapter02;

public class Java04_Operator_2 {
    public static void main(String[] args) {

        //TODO 运算符 - 关系运算符
        //所谓的关系运算符其实就是用于比较两个数据之间关系的运算符
        //关系运算符基本语法结构：
        //关系表达式 元素1（数据1/表达式1） 关系运算符[==,!=,>,>=,<,<=] 元素2（数据2/表达式2）、
        //关系表达式的结果为布尔类型：如果表达式的结果和预想一样，那么结果为true，如果表达式的结果和预想不一样，那么结果为false
        int i = 10;
        int j = 20;
        System.out.println(i > j); //false
        System.out.println(i < j); //true
        System.out.println(i == j); //false，双等号表示两个数据是否相等
        System.out.println(i != j); //true，感叹号表示两个数据是否不相等
        System.out.println(i >= j); //false，大于等于
        System.out.println(i <= j); //true，小于等于
    }
}

```



## 4.逻辑运算符

```java
package chapter02;

public class Java04_Operator_3 {
    public static void main(String[] args) {

        //TODO 运算符 - 逻辑运算符
        //逻辑运算符其实就是用于描述多个条件表达式之间的关系的运算符
        //TODO 基本语法结构：
        //变量 = （条件表达式1） 逻辑运算符 （条件表达式2）
        //结果变量的类型是布尔类型

        //TODO 逻辑运算符：&，称之为与运算
        //与运算，要求两个条件表达式都必须计算出结果，只有两个结果都为true的时候，最终结果为true，其他情况都为false
        int i = 10;
        boolean result = (i > 5) & (i < 20);
        System.out.println(result);

        //TODO 逻辑运算符：|，称之为或运算
        //或运算，要求两个表达式都能计算出结果，只要有任何一个结果为true，那么最后结果都为true
        //两个表达式结果都为false，最终结果才为false
        int j = 10;
        boolean result1 = (j > 5) | (j < 9);
        System.out.println(result1);

        //TODO 逻辑运算符：&&，称为短路与运算
        //短路与运算，会根据第一个条件表达式的结果来判断，是否执行第二个表达式
        //如果第一个表达式的结果为false，那么无需执行第二个表达式
        int t = 10;
        int y = 20;
        boolean result2 = (t > 10) && (++y > 30);
        System.out.println(result2);
        System.out.println(y); //20

        //TODO 逻辑运算符：||，称为短路或运算
        //短路与运算，会根据第一个条件表达式的结果来判断，是否执行第二个表达式
        //如果第一个表达式的结果为true，第二个表达式无需执行
        int n = 10;
        int s = 20;
        boolean result3 = (n == 10) || (++s > 30);
        System.out.println(result3);
        System.out.println(s); //20

        //TODO 逻辑运算符：！，逻辑非（相反）运算符
        int b = 10;
        boolean result4 = i == 10;
        System.out.println(!result4); //false
    }
}

```



## 5.三元运算符

```java
package chapter02;

public class Java04_Operator_4 {
    public static void main(String[] args) {

        //TODO 运算符 - 三元运算符
        //所谓的三元运算符其实就是三个元素参与运算的运算符
        //基本语法结构：
        //变量 = （条件表达式）？（任意表达式1）：（任意表达式2）
        //运算规则：判断条件表达式的结果，如果为true，那么执行表达式1的值，如果为false，执行表达式2的值
        int i = 10;
        int j = 20;

        int k = (i == 10) ? 1 + 1 : 2 + 2;
        System.out.println(k);
    }
}

```



# 四、流程控制

## 1.顺序执行

```java
package chapter03;

public class Java01_FlowControl {
    public static void main(String[] args) {

        //TODO 流程控制
        //所谓的流程控制，其实就是计算机在执行代码时，对指令代码的执行顺序的控制
        //Java中的流程控制主要分三种：
        //1.顺序执行：代码出现的先后顺序，以及语法的先后顺序
        //变量在使用之前，必须声明并且初始化
        int i = 10;
        int j = 20;
        System.out.println(i + j);
        //2.分支执行
        //3.重复执行
    }
}

```

## 2.分支执行

### ①可选分支，必选分支，多分支

```java
package chapter03;

public class Java02_FlowControl {
    public static void main(String[] args) {

        //TODO 流程控制 - 分支执行
        //分支结构
        //TODO 1.可选分支：单分支结构
        System.out.println("第一步");
        System.out.println("第二步");
        //判断：条件表达式的结果知否为true，如果为true，执行分支逻辑，如果为false，不执行分支逻辑
        //判断的语法使用if关键字，表示如果，在条件表达式之前使用，如果结果为true，那么分支逻辑应该在后续的大括号中执行
//        int i = 20;
//        if (i == 10) {
//            System.out.println("分支");
//        }

        //TODO 2.必选分支：双分支结构（二选一）
        //语法上使用if...else操作，这里的else表达其他场合
//        int i = 10;
//        if (i == 10) {
//            System.out.println("分支1");
//        } else {
//            System.out.println("分支2");
//        }

        //TODO 3.多分支结构
        //if...else if...else
        int i = 30;
        if (i == 10) {
            System.out.println("分支1");
        } else if (i == 20) {
            System.out.println("分支2");
        }
//        else {
//            System.out.println("分支3");
//        }

        System.out.println("第三步");


    }
}

```

### ②特殊的分支结构

<img src="image-20240928104924518.png" alt="image-20240928104924518" style="zoom:67%;" />

```java
package chapter03;

public class Java03_FlowControl {
    public static void main(String[] args) {

        //TODO 流程控制 - 分支执行
        //特殊的分支结构
        //switch ( 数据 ) {}
        //switch语法会对数据进行判断，如果等于某一个分支数据的值，那么执行相应分支的逻辑代码和以下的逻辑代码
        //如果一个分支都无法匹配，那么一个分支都不会执行，如果想要无法匹配也需要执行分支（必选分支），那么可以增加default关键字
        //如果想要执行某一个分支后，不想继续执行其他分支的话，可以使用break关键字跳出分支
        System.out.println("第一步");
        System.out.println("第二步");
        int i = 10;
        switch (i) {
            case 10:
                System.out.println("分支1");
                break;
            case 20:
                System.out.println("分支2");
            case 30:
                System.out.println("分支3");
            default: //加上这个就变成必选的了
                System.out.println("其他分支");

        }
        System.out.println("第三步");
    }
}

```

### ③小练习

```java
package chapter03;

public class Java04_FlowControl_test {
    public static void main(String[] args) {

        //TODO 流程控制 - 分支执行 - 小练习
        int age = 30;
        //儿童（0~6），少年（7~17），青年（18~40），中年（41~65），老年（66）
        //if...else if...else if...else ： 多分支判断
        //switch...case...case...default ： 等值分支判断
        if (0 <= age && age <= 6) {
            System.out.println("儿童");
        } else if (7 <= age && age <= 17) {
            System.out.println("少年");
        } else if (18 <= age && age <= 40) {
            System.out.println("青年");
        } else if (41 <= age && age <= 65) {
            System.out.println("中年");
        } else if (66 <= age) {
            System.out.println("老年");
        } else {
            System.out.println("错误");
        }
    }
}

```

## 3.重复执行（循环执行）

### ①while

```java
package chapter03;

public class Java05_FlowControl {
    public static void main(String[] args) {

        //TODO 流程控制 - 重复执行（循环执行）
        //根据条件重复执行某段代码
        //Java中主要用于循环的语法有3个：
        //1.while：有条件重复
        //while (条件表达式) {需要循环的代码}
        //基本的执行原理：while循环会判断条件表达式的结果是否为true
        // 如果为true，会执行大括号内的逻辑代码，代码执行完毕后，会重新对条件表达式进行判断
        // 如果为false，那么跳出循环结构
        System.out.println("第一步");
        int age = 30;
        while (age < 40) { //执行十次
            System.out.println("循环的代码");
            age++;
        }
        //2.do...while
        //3.for
        System.out.println("第二步");
    }
}

```

### ②do...while



```java
package chapter03;

public class Java05_FlowControl {
    public static void main(String[] args) {

        //TODO 流程控制 - 重复执行（循环执行）
        //根据条件重复执行某段代码
        //Java中主要用于循环的语法有3个：
        //1.while：有条件重复
        //while (条件表达式) {需要循环的代码}
        //基本的执行原理：while循环会判断条件表达式的结果是否为true
        // 如果为true，会执行大括号内的逻辑代码，代码执行完毕后，会重新对条件表达式进行判断
        // 如果为false，那么跳出循环结构
        System.out.println("第一步");
        int age = 40;
//        while (age < 40) { //执行十次
//            System.out.println("循环的代码");
//            age++;
//        }

        //2.do...while
        //语法执行原理和while基本相同，区别在于循环代码是否至少执行一次
        //while循环语法可能执行，可能不执行
        //do...while循环语法中的循环代码至少执行一次
        /*
        do {
            循环代码
        } while(条件表达式)
         */
        do {
            System.out.println("循环的代码");
        } while (age < 40);
        //3.for
        System.out.println("第二步");
    }
}

```

### ③for

```java
package chapter03;

public class Java05_FlowControl {
    public static void main(String[] args) {

        //TODO 流程控制 - 重复执行（循环执行）
        //根据条件重复执行某段代码
        //Java中主要用于循环的语法有3个：
        //1.while：有条件重复
        //while (条件表达式) {需要循环的代码}
        //基本的执行原理：while循环会判断条件表达式的结果是否为true
        // 如果为true，会执行大括号内的逻辑代码，代码执行完毕后，会重新对条件表达式进行判断
        // 如果为false，那么跳出循环结构
        System.out.println("第一步");
        int age = 40;
//        while (age < 40) { //执行十次
//            System.out.println("循环的代码");
//            age++;
//        }

        //2.do...while
        //语法执行原理和while基本相同，区别在于循环代码是否至少执行一次
        //while循环语法可能执行，可能不执行
        //do...while循环语法中的循环代码至少执行一次
        /*
        do {
            循环代码
        } while(条件表达式)
         */
        do {
            System.out.println("循环的代码");
        } while (age < 40);

        //3.for
        //如果条件表达式返回结果为false，那么跳过循环语句，直接执行后续代码，如果返回结果为false，那么执行循环语句
        //初始化表达式用于对条件表达式中是用到的变量进行初始化
        //循环代码执行后，会重新进行表达式的判断，如果判断结果为true，会重复执行循环代码
        /*
        for( 初始化表达式 ; 条件表达式 ; 更新表达式 ) {
            循环的代码
        }
         */
        for (int i = 30; i < 40; i++) {
            System.out.println("循环的代码");
            System.out.println(i);
        }

        System.out.println("第二步");
    }
}

```

### ④break和continue关键字

```java
package chapter03;

public class Java05_FlowControl_1 {
    public static void main(String[] args) {

        //TODO 流程控制 - 重复执行（循环执行）
//        for (int i = 0; i < 10; i++) {
//            if (i != 4) {
//                System.out.println(i);
//            }
//        }

        //break关键字会跳出循环，不再执行循环后续的操作
        //continue关键字会跳过循环，执行下一次循环
        for (int i = 0; i < 10; i++) {
            if (i == 4) {
                //切断，跳出循环
                //break;
                continue;
            }
            System.out.println(i);
        }

    }
}

```

### ⑤小练习 - 九层妖塔

```java
package chapter03;

public class Java06_FlowControl_test {
    public static void main(String[] args) {

        //TODO 流程控制 - 小练习
        //九层妖塔
        /*
         *
         ***
         *****
         *******
         *********
         ***********
         *************
         ***************
         *****************
         */

        int level = 9; //优化代码，修改层数改这个数值就可以了

        //0 -> 8
        //1 -> 7
        //2 -> 6
        //...
        for (int i = 0; i < level; i++) {
            for (int n = 0; n < (level - 1) - i; n++) { //最后一层开头不需要空格
                System.out.print(' '); //打印开头的空格
            }

            //0 -> 1
            //1 -> 3
            //2 -> 5
            //3 -> 7
            //...
            for (int j = 0; j < 2 * i + 1; j++) {
                System.out.print('*'); //打印*号
            }
            System.out.println();
        }

    }
}

```



# 五、面向对象

## 1.基本语法

```java
package chapter04;

public class Java01_Object {
    public static void main(String[] args) {

        //TODO 面向对象
        //所谓的面向对象，其实就是分析问题时，以问题所涉及的事或者物为中心的分析方式
        //类和对象
        //类表示归纳和整理
        //对象就表示具体的事物
        //TODO class（类）
        /*
        类的基本语法结构：
        class 类名（命名规范，第一个字母大写） {
        特征（属性），
        功能（方法）

        创建对象的语法：
        new 类名()；
        }
         */

        //问题：做一道菜，红烧排骨
        //类：菜。对象：红烧排骨

        //TODO 1.先声明类
        //TODO 2.创建对象
        //TODO 3.声明属性，所谓的属性就是类中的变量
        //变量类型 变量名称 = 变量值
        //属性类型 属性名称 = 属性值
        //TODO 4.声明方法
        //void 方法名(参数) {功能代码}
        //TODO 5.执行方法
        //对象.属性
        //对象.方法()

        //引用数据类型
        Cooking c = new Cooking();
        c.name = "红烧排骨";
        c.food = "排骨";
        c.execute();

        Cooking c1 = new Cooking();
        c1.name = "红烧鱼";
        c1.food = "鲫鱼";
        c1.execute();
    }
}

class Cooking {

    //特征（属性）
    //名字
    String name;
    //菜的类型
    String type = "红烧";
    //食材
    String food;
    //佐料
    String relish = "大料";

    void execute() {
        System.out.println("菜品名称:" + name);
        System.out.println("菜的类型:" + type);
        System.out.println("菜的食材:" + food);
        System.out.println("菜的佐料:" + relish);

        System.out.println("准备食材");
        System.out.println("准备佐料");
        System.out.println("开始烹饪");
        System.out.println("烹饪完成");
    }
}
```

## 2.案例分析

```java
package chapter04;

public class Java02_Object {
    public static void main(String[] args) {

        //TODO 面向对象

        //类:动物
        //对象:猫,狗
        Animal a1 = new Animal();
        a1.type = "猫";
        a1.name = "小黑";
        a1.run();

        Animal a2 = new Animal();
        a2.type = "狗";
        a2.name = "大黄";
        a2.run();
    }
}

class Animal {

    String type;
    String name;

    void run() {
        System.out.println(type + ' ' + name + "跑开了");
    }
}
```

```java
package chapter04;

public class Java02_Object_1 {
    public static void main(String[] args) {

        //TODO 面向对象
        //狗:2只,小黑,小白
        Dog dog1 = new Dog();
        dog1.color = "white";
        dog1.name = "小白";
        dog1.run();

        Dog dog2 = new Dog();
        dog2.color = "black";
        dog2.name = "小黑";
        dog2.run();
    }
}

class Dog {
    String color;
    String name;

    void run() {
        System.out.println(color + "色的小狗" + name + "跑开了");
    }
}
```

```java
package chapter04;

public class Java02_Object_2 {
    public static void main(String[] args) {

        //TODO 面向对象

        Teacher teacher1 = new Teacher();
        teacher1.name = "zhangsan";
        teacher1.teach();

        Sdudent sdudent1 = new Sdudent();
        sdudent1.name = "lisi";
        sdudent1.sdudy();
    }
}

class Teacher {
    String name;

    void teach() {
        System.out.println(name + "老师在讲课");
    }
}

class Sdudent {
    String name;

    void sdudy() {
        System.out.println("学生" + name + "在听课");
    }
}
```

## 3.类和对象

```java
User04 user = new User04();
```

<img src="image-20240929193516378.png" alt="image-20240929193516378" style="zoom:67%;" />

1. **栈：方法，属性**
2. **堆：对象**
3. **元空间：类的信息**

```java
package chapter04;

public class Java04_Object_class {
    public static void main(String[] args) {

        //TODO 面向对象
        //类:结构体,包含了属性(特征)和方法(行为)
        //会有很多的对象
        //class : 关键字(全是小写的)
        //类名:类的名称,标识符,遵循规则,一般情况下,类名的首写字母是大写的(规范,不必须)

        //对象:类的实例化(具象化)
        //new 类名(),小括号需要增加
        //new 也是关键字,表示创建一个具体的对象,而且使用一次,创建一次,每次都是全新的
        //一般new出来的对象会赋值给变量,方便重复使用
        //变量的类型就是对象的类型
        //TODO 对象是将内存地址赋值给了变量,所以变量其实引用了内存中的对象,所以称之为引用变量
        //而变量的类型称之为引用数据类型
//        new User04();
//        new User04();
//        new User04();
        User04 user = new User04();

        //TODO 特殊的对象:空对象,没有引用的对象,称之为空对象,关键字对象
        //所有引用类型变量的默认取值就是null
        User04 user1 = null;
    }
}

class User04 {

}
```

## 4.属性

```java
package chapter04;

public class Java05_Object_Field {
    public static void main(String[] args) {

        //TODO 面向对象
        //所谓的属性,其实就是类的对象的相同特征
        //语法和变量的声明很像
        //属性类型 属性名称 = 属性值
        //如果在声明属性的同时进行了初始化复制,那么所有对象的属性就完全相同
        //如果希望每一个对象的属性不一致,那么可以不用在声明属性的时候进行初始化
        //那么属性会在构造对象的时候默认初始化,而默认初始化的值取决于属性的类型
        //byte,short,int,long => 0
        //float,double => 0.0
        //boolean flg = false
        //char = 空字符
        //引用数据类型 => null

        //变量的作用域非常小,只在当前的大括号内有效
        //属性不仅仅在当前类中有效,而且可以随着对象在其他地方使用
        //变量使用前必须初始化,否则会出现错误,属性可以不用初始化,因为JVM会帮助我们自动完成初始化
        String name = "zhangsan";

    }
}

class User05 {
    //String name = "zhangsan";
    String name;
}
```

## 5.方法

```java
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
```

## 6.方法参数

```java
package chapter04;

public class Java07_Object_Method_Param {
    public static void main(String[] args) {

        //TODO 面向对象 - 方法
        //使用外部数据控制方法内部实现的操作,使用的是参数语法实现,也叫做方法参数
        //语法:方法名( 参数类型 参数名称 )
        //参数列表
        //语法:方法名( 参数类型1 参数名称1 , 参数类型2 参数类型2 )

        User07 user = new User07();
        String name = "zhangsan";
        int age = 30;
        //传递参数
        //user.sayHello(name, age);

        //当方法传递多个参数的时候,需要注意:
        //1.参数个数需要匹配
        //2.参数类型需要匹配
        //3.参数顺序需要匹配

        //TODO 4.当参数的个数不确定,但是类型相同时,可以采用特殊的参数语法声明:可变参数
        //如果参数还包含其他含义的参数,那么可变参数应该放在最后
        //语法:参数类型... 参数名称
        user.test(30);
        user.test(30, "zhangsan");
        user.test(30, "zhangsan", "lisi", "wangwu");
    }
}

class User07 {

    void sayHello(String name, int age) {
        //使用参数
        System.out.println("Hello " + name + ',' + age);
    }

    void test(int age, String... name) {
        System.out.println(name);
    }
}
```

## 7.方法参数 - 传值方式

```java
package chapter04;

import netscape.security.UserTarget;

public class Java07_Object_Method_Param_1 {
    public static void main(String[] args) {

        //TODO 面向对象 - 方法
        //Java中方法参数的传递为值传递
        //基本数据类型:数值
        //引用数据类型:引用地址
//        String s = "abc";
//        test(s);
//        System.out.println(s); //"abc10"?
        User user = new User();
        user.name = "zhangsan";
        test(user);
        System.out.println(user.name);

        //字符串拼接机制:
        // 在 Java 中，当一个字符串（如 "zhangsan"）与其他基本数据类型（这里是 int 类型的 10）进行拼接操作时,
        // Java 会自动将基本数据类型转换为字符串类型，然后再进行拼接
        String name = "zhangsan" + 10;
        System.out.println(name);
    }

//    public static void test(int i) {
//        i = i + 10;
//    }

//    public static void test(String s) {
//        s = s + 10;
//    }

    public static void test(User user) {
        user.name = "lisi";
    }
}

class User {
    String name;
}
```

## 8.静态

```java
package chapter04;

public class Java08_Object_Static {
    public static void main(String[] args) {

        //TODO 面向对象
        //针对于具体对象的属性称之为对象属性,成员属性,实例属性
        //针对于具体对象的方法称之为对象方法,成员方法,实例方法
        //把和对象无关,只和类相关的称之为静态
        //和类相关的属性称之为静态属性
        //和类相关的方法称之为静态方法
        //静态语法就是在属性和方法前增加static关键字
//        Chinese c = new Chinese();
//        Chinese c = null;
//        c.name = "zhangsan";
//
//        System.out.println("Hello " + c.name + ", " + c.nationnality);

        //静态不用创建对象就能访问
        Bird.fly();
        System.out.println(Bird.type);
    }
}

class Bird {
    static String type = "鸟";

    static void fly() {
        System.out.println("飞...");
    }
}

class Chinese {
    String name;

    //国籍
    String nationnality = "中国";
}

```

```java
package chapter04;

public class Java08_Object_Static_1 {
    public static void main(String[] args) {

        //TODO 面向对象 - 静态

        //TODO 先有类,再有对象
        //成员方法可以访问静态属性和静态方法
        //静态方法不可以访问成员属性和成员方法
        Test t = new Test();
        t.sex = "女";
        t.test();
//        t.test1();
//        Test.test1();
    }
}

class Test {
    String name; //成员属性
    static String sex; //静态属性

    void test() { //成员方法
//        test1();
//        System.out.println(sex);
        System.out.println("test...");
    }

    static void test1() { //静态方法
//        test();
//        System.out.println(name);
//        System.out.println("test1...");
    }
}


class Bird1 {
    static String type = "鸟";

    static void fly() {
        System.out.println("飞...");
    }
}
```

## 9.静态代码块

```java
package chapter04;

public class Java08_Object_Static_2 {
    public static void main(String[] args) {

        //TODO 面向对象 - 静态

        //TODO 类的信息加载完成后,会自动调用静态代码快,可以完成静态属性的初始化功能
        //TODO 对象准备创建时,也会自动调用代码块,但不是静态的
//        User08.test();
        new User08();
    }
}

class User08 {
    static {
        //静态代码块
        System.out.println("静态代码块执行1");
    }

    static {
        //静态代码块
        System.out.println("静态代码块执行2");
    }

    static void test() {
        System.out.println("test...");
    }

    {
        //静态代码块
        System.out.println("代码块执行1");
    }

    static {
        //静态代码块
        System.out.println("静态代码块执行3");
    }

    {
        //静态代码块
        System.out.println("代码块执行1");
    }
}
```

## 10.包

```java
package chapter04;

public class Java09_Object_Package {
    public static void main(String[] args) {

        //TODO 面向对象 - package - 包
        //package容纳类
        //基本语法:package 包完整路径;
        //路径中的多个包使用.隔开
        //java.long.Object
        //主要功能用于分类管理

        //一个类可以没有包,但是package不能在同一个源码文件中使用多次
        //包名为了区分类名,所以一般全部都是小写
        //java.long.Object  java和long是包,Object是类,为了区分,不强制规定

        //Java中存在不同包的相同名称的类,可以使用包进行区分
        //一般情况下,在使用类的情况下,我们都会使用类的全名(包名 + 类名)
        new java.util.Date();
    }
}

```

## 11.Import - 导入类

**Alt + 回车：自动导入类**

```java
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

```

## 12.构造方法

```java
package chapter04;

public class Java11_Object_Instance {
    public static void main(String[] args) {

        //TODO 面向对象 - 构建对象
        //构造方法:专门用于构建对象
        //如果一个类中没有任何的构造方法，那么JVM会自动添加一个公共的,无参的构造方法,方便对象的调用
        //TODO 基本语法:类名(){}
        //1.构造方法也是方法,但是没有void关键字
        //2.方法名和类名完全相同
        //3.如果类中没有构造方法,那么JVM会提供默认的构造方法
        //4.如果类中有构造方法,那么JVM不会提供默认的构造方法
        //5.构造方法也是方法,所以也可以传递参数,但是一般传递参数的目的是用于对象属性的赋值
        System.out.println("before...");
        User11 user = new User11("zhangsan");
        System.out.println("after...");
        user.test();
        System.out.println(user.username);
        //TODO 代码块，是在构造对象之前执行的

    }
}

class User11 {
    String username;

    {
        System.out.println("代码块1");
    }

    User11(String name) {
        username = name;
        System.out.println("user...");
    }

    {
        System.out.println("代码块2");
    }

    void test() {
        System.out.println("test...");
    }

    {
        System.out.println("代码块3");
    }
}
```

## 13.继承

<img src="image-20240929234419004.png" alt="image-20240929234419004" style="zoom: 67%;" />

```java
package chapter04;

public class Java12_Object_Extends {
    public static void main(String[] args) {

        //TODO 面向对象 - 继承
        //面向对象中有非常重要的三个特征:继承,封装,多态
        //类存在父子关系,子类可以直接获取到父类的成员属性和方法
        //类的继承只能是单继承,一个类只能有一个父类,不能存在多个父类
        //一个父类可以有多个子类

        //继承采用extends语法:子类 extends 父类
        Child c = new Child();
        System.out.println(c.name);
        c.test();
    }
}

class Parent {
    String name = "zhangsan";

    void test() {
        System.out.println("test");
    }
}

class Child extends Parent {

}
```

## 14.super、this

1. **super.表示父类**
2. **this.表示子类**

```java
package chapter04;

public class Java12_Object_Extends_1 {
    public static void main(String[] args) {

        //TODO 面向对象 - 继承
        //如果父类和子类含有相同的属性,那么可以采用特殊的关键字进行区分
        Child1 c = new Child1();
//        System.out.println(c.name);
        c.test();
    }
}

class Parent1 {
    String name = "zhangsan";
}

class Child1 extends Parent1 {
    String name = "lisi";

    void test() {
        System.out.println(super.name);
        System.out.println(this.name);
        System.out.println(name);
    }
}
```

## 15.继承、构造方法

<img src="image-20240930125043588.png" alt="image-20240930125043588" style="zoom: 67%;" />

```java
package chapter04;

public class Java12_Object_Extends_2 {
    public static void main(String[] args) {

        //TODO 面向对象 - 继承
        //构造方法
        //父类对象是在子类对象创建前创建完成的,创建子类对象前,会调用父类的构造方法完成父类的创建
        //默认情况下,子类对象创建时,会默认调用父类的构造方法完成父类对象的创建,使用的是super方式,只不过JVM自动完成
        //如果父类提供构造方法,那么JVM不会提供默认的构造方法,那么子类应该显示调用super方法构建父类对象
        Child2 c1 = new Child2();
        Child2 c2 = new Child2();
        Child2 c3 = new Child2();

        //new : 只会构建一个对象
        //子类中的父类属性是继承过来的,并不是真的创建了一个父类对象,只有子类对象,里面包含了父类属性,构建器也是在创建对象之后运行的
    }
}

class Parent2 {
    String username;

    Parent2(String name) {
        username = name;
        System.out.println("parent...");
    }
}

class Child2 extends Parent2 {
    Child2() {
        super("zhangsan");
        System.out.println("child...");
    }
}
```

## 16.多态

```java
package chapter04;

public class Java13_Object {
    public static void main(String[] args) {

        //TODO 面向对象 - 多态
        //所谓的多态,就是一个对象在不同场景下表现出来的不同状态和形态
        //多态语法其实就是对对象的使用场景进行了约束
        //一个对象可以使用的功能取决于引用变量的类型
        Person p = new Person();
        p.testPerson();
        Person p1 = new Boy();
        p1.testPerson();
        Person p2 = new Girl();
        p2.testPerson();

        Boy boy = new Boy();
        boy.testBoy();

        Girl girl = new Girl();
        girl.testGirl();
    }
}

class Person {
    void testPerson() {
        System.out.println("test person...");
    }
}

class Boy extends Person {
    void testBoy() {
        System.out.println("test boy...");
    }
}

class Girl extends Person {
    void testGirl() {
        System.out.println("test girl...");
    }
}
```

## 17.方法重载

```Java
package chapter04;

public class Java14_Object {
    public static void main(String[] args) {

        //TODO 面向对象
        //一个类中,不要能声明相同的方法,也不能声明相同的属性
        //这里相同的方法指的是方法名,参数列表相同,和返回值类型无关
        //如果方法名相同,但是参数列表(个数,顺序,类型)不相同,会认为是不同的方法,只不过名称一样
        //这个操作在Java中称为方法的重载
        //构造方法也存在方法的重载
        User14 user = new User14("zhangsan");
        user.login(1111);
        user.login("123123");
        user.login("zhangsan", "123123");
    }
}

class User14 {
    User14() {
        System.out.println("user...");
    }

    User14(String name) {
        System.out.println("user..." + name);
    }

    void login(String account, String password) {
        System.out.println("账号,密码登录");
    }

    void login(int tel) {
        System.out.println("手机验证码登录");
    }

    void login(String wx) {
        System.out.println("微信,支付宝登录");
    }
}
```

## 18.方法重载 - 小练习

```java
package chapter04;

public class Java14_Object_1 {
    public static void main(String[] args) {

        //TODO 面向对象
        //如果在一个构造方法中,想要调用其他的构造方法,那么需要使用特殊的关键字:this
        User141 user1 = new User141();
//        User141 user2 = new User141("zhangsan");
//        User141 user3 = new User141("zhangsan", "男");
    }
}

class User141 {
    User141() {
        this("zhangsan");
    }

    User141(String name) {
        this(name, "男");
    }

    User141(String name, String sex) {
        System.out.println(name + ',' + sex);
    }
}
```

```java
package chapter04;

public class Java14_Object_2 {
    public static void main(String[] args) {

        //TODO 面向对象
        byte b = 10;
//        test(b); //bbb
        //byte => 8
        //short => 16
        //char => 16
        //int => 32
        //基本数据类型在匹配方法时,可以在数值不变的情况下,扩大数据的精度
        //byte类型无法和char类型做转换,char没有负数,但是byte存在负数

        test(b);
    }

//    static void test(byte b) {
//        System.out.println("bbb");
//    }

//    static void test(short s) {
//        System.out.println("sss");
//    }

    static void test(char c) {
        System.out.println("ccc");
    }

    static void test(int i) {
        System.out.println("iii");
    }
}

```

```java
package chapter04;

public class Java14_Object_3 {
    public static void main(String[] args) {

        //TODO 面向对象
//        AAA aaa = new AAA();
//        BBB aaa = new BBB();
        BBB aaa = new BBB(); //使用什么方法取决于用的什么类型
        test(aaa);

        //多态其实就是约束了对象的使用场景,给了BBB但是当成AAA来用
        //方法的重载:方法名相同,参数列表不同(个数,顺序,类型)
        //如果找不到,会提升数据类型,找父类:
        //AAA -> Object
        //BBB -> AAA -> Object
    }

    static void test(AAA aaa) {
        System.out.println("aaa");
    }

//    static void test(BBB bbb) {
//        System.out.println("bbb");
//    }
}

class AAA {

}

class BBB extends AAA {

}
```

## 19.方法重写

```java
package chapter04;

public class Java15_Object {
    public static void main(String[] args) {

        //TODO 面向对象
        //方法的重写:父类对象的方法其实主要体现通用性,无法在特殊的场合下使用
        //          如果子类对象需要在特殊的场合下使用,那么就需要重写方法的逻辑,这个操作在Java中称之为方法的重写
        //这里的重写,并不意味着父类的方法被覆盖掉,只是在当前场合中不适用,如果使用super关键字,还是可以访问
        //方法的重写要求,子类的方法和父类的方法,方法名相同,返回值类型相同,参数列表相同
        Child15 child = new Child15();
        child.test();
    }
}

class Parent15 {
    String name = "zhangsan";

    void test() {
        System.out.println("parent test...");
    }
}

class Child15 extends Parent15 {
    String name = "lisi";

    void test() {
        System.out.println(this.name);
        System.out.println(super.name);
        super.test();
        System.out.println("child test...");
    }
}
```

## 20.方法重写 - 小练习

```java
package chapter04;

public class Java15_Object_1 {
    public static void main(String[] args) {

        //TODO 面向对象 - 重写
//        CCC ccc = new CCC();
//        DDD ddd = new DDD();
        CCC ddd = new DDD();
        //一个对象能使用什么方法,取决于引用变量的类型
        //一个对象能使用什么属性,取决于引用变量的类型

        //一个对象的方法具体的使用(直接,间接)是需要看具体的对象的
        //一个对象的属性具体的使用是不需要看具体的对象的
        //TODO 属性在哪里声明,在哪里使用
        System.out.println(ddd.sum());
    }
}

class CCC {
    int i = 10;

    int sum() {
        return getI() + 10;
    }

    int getI() {
        return i;
    }
}

class DDD extends CCC {
    int i = 20;

    int sum() {
        return getI() + 20;
    }

    int getI() {
        return i;
    }
}
```

## 21.递归

```java
package chapter04;

public class Java16_Object_Recursion {
    public static void main(String[] args) {

        //TODO 面向对象 - 递归
        //所谓的递归:方法调用自身,称之为递归方法
        //例如想求20以内的奇数之和
        //1 + 3 + 5 + 7 + 9 + ... + 19
        int result = computeAP(20);
        System.out.println(result);

        //阶乘 : 5! => 5 * 4 * 3 * 2 * 1
        //0的阶乘为1
        //一个大于1的阶乘等于这个数乘以这个数减一的阶乘
        int result1 = computeFactorial(5);
        System.out.println(result1);

        //1.递归方法应该有跳出的逻辑
        //2.调用自身时,传递的参数应该有规律
    }

    /*
    1是递归边界
    先不断的递归调用,到达边界之后开始逐步返回结果向上累加

    计算过程:
    当第一次调用computeAP(20)时，由于 20 是偶数，先将其变为 19。
    然后判断 19 不等于 1，执行return 19 + computeAP(17)。
    接着调用computeAP(17)，同样进行判断和计算，得到17 + computeAP(15)。
    以此类推，不断进行递归调用，直到num等于 1 时，开始返回结果并逐步向上累加。
    最终，通过这种递归的方式，实现了对 20 以内奇数的累加，得到结果 100。
     */
    public static int computeAP(int num) {
        num = num % 2 == 0 ? num - 1 : num;
        if (num == 1) {
            return 1;
        } else {
            return num + computeAP(num - 2);
        }
    }

    public static int computeFactorial(int num) {
        if (num <= 1) {
            return 1;
        } else {
            return num * computeFactorial(num - 1);
        }
    }
}
```

## 22.访问权限

```java
package chapter04;

public class Java17_Object_Access {
    public static void main(String[] args) {

        //TODO 面向对象 - 访问权限
        //public:公共的,访问权限修饰符
        //TODO Java的源码中,公共类只能有一个,而且必须与源码文件名相同
        //main方法:main方法是由JVM调用的,JVM调用时应该可以任意调用,而不用考虑权限问题

        //TODO Java中的访问权限主要分4中:
        // 1.private:私有的,同一个类中可以使用
        // 2.(default):默认权限,当不设定任何权限时,JVM会默认提供权限,包(路径权限)权限(同一个包下可以访问)(其他包和子包都不可以访问)
        // 3.protected:受保护的权限,子类可以访问,包权限(同包也可以访问)
        // 4.public:公共的,任意使用

        User17 user = new User17();
//        System.out.println(user.name);
        System.out.println(user.username);
        System.out.println(user.sex);
        System.out.println(user.age);
    }
}

class User17 {
    private String name;
    public String username;
    String sex;
    protected int age;

    void test() {
        System.out.println(name);
        System.out.println(username);
        System.out.println(age);
    }
}

class Child17 extends User17 {
    void test() {
        System.out.println(age);
    }
}
```

## 23.访问权限 - 小练习

```java
package chapter04;

public class Java17_Object_Access_1 {
    public static void main(String[] args) {

        //TODO 面向对象 - 访问权限
        Person17 person = new Person17();

        //private:同类
        //default:同类,同包(路径)
        //protected:同类,同包(路径),子类(优先保护和自己直接相关的子类)
        //public:公共的
        //所谓的访问权限,其实就是访问属性,方法的权力和限制
        //谁访问? Java17_Object_Access_1 -> super -> java.long.Object
        //访问谁的? Person17 -> super -> java.long.Object(clone)
//        Person.clone(); //所有类的父类都有Object类,clone是Object的一个protected方法,按理说子类可以访问,这里为什么不能用呢
    }
}

class Person17 {
    void test() throws Exception {
        clone();
    }
}
```

