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
