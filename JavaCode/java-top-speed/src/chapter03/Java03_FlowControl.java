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
