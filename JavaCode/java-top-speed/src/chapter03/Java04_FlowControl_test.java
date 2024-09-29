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
