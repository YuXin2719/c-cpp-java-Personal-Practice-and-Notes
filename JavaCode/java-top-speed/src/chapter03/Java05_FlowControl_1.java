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
