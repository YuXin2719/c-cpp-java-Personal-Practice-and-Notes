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
        int i = 10;
        if (i == 10) {
            System.out.println("分支1");
        } else {
            System.out.println("分支2");
        }

        System.out.println("第三步");


    }
}
