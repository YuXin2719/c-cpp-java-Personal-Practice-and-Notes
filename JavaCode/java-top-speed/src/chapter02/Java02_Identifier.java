package chapter02;

public class Java02_Identifier {
    public static void main(String[] args) {

        //TODO 标识符
        //标识数据的符号，称之为标识符
        //变量名称（name）就是标识符
        //标识符主要用于起名
        String name = "zhangsan";

        //TODO 标识符的命名规则
        //1.英文拉丁字母
        String username = "zhangsan";
        String xingming = "lisi";
        //2.符号
        //TODO 标识符只能采用下划线_和美元$符号。其他符号不能使用，称之为特殊符号
        //空格属于特殊符号，不能作为标识符使用
        String _name = "wangwu";
        String $name = "wangwu";
        //3.数字
        //TODO 阿拉伯数字0-9可以作为标识符使用，但是不能开头
        //数字如果在标识符的开头位置，那么他会被识别为数字，而不是标识符，所以会发生错误
        //String 1name="zhgangsan";
        String name1 = "zhgangsan";

        //4.在大括号范围内，标识符能重复
        //String name="zhaoliu";
        //TODO 标识符是区分大小写的
        String Name = "zhangsan";

        //5.Java语言中预先定义了一些标识符名称，称之为关键字或者保留字
        //可以使用大写来实现关键字的定义，但是容易产生歧义，所以不推荐
        String Public = "zhangsan";

        //6.命名规范：驼峰标识
        String userName = "zhangsan";

        //7.标识符的长度
        //没有长度的限制
    }
}
