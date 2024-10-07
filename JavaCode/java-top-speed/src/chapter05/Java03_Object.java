package chapter05;

public class Java03_Object {
    public static void main(String[] args) {

        //TODO 常见类和对象
        //数组
        //创建数组的时候编译器会自动帮我们赋默认值
        String[] nums = new String[3];
//        nums[0] = 1;
        for (String num : nums) {
            System.out.println(num); //String本质上也是对象,所以这里是null
        }

        String[] names = {"zhangsan", "lisi", "wangwu"};
        System.out.println(names);
        for (String name : names) {
            System.out.println(name);
        }

        //二维数组(叫二维数组,但不是真的二维)
        System.out.println(names.length);
        String[][] names2 = {{"zhangsan", "lisi", "wangwu"}, {"zhangsan", "lisi"}, {"zhangsan"}};

        //标准的二维数组
        String[][] names3 = new String[3][3];

        names3[0][1] = "zhangsan";

        System.out.println(names3[0][1]);

        //遍历数组的每个元素
        for (int row = 0; row < 3; row++) { //row行
            for (int col = 0; col < 3; col++) { //col列
                System.out.println("第" + (row + 1) + "行 " + "第" + (col + 1) + "列 的值为 " + names3[row][col]);
            }
        }

    }
}