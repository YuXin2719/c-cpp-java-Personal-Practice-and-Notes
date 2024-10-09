package chapter05;

public class Java03_Object_Test_3 {
    public static void main(String[] args) {

        //TODO 常见类和对象
        //数组 - 数据查询
        int[] nums = {1, 2, 3, 4, 5, 6, 7};

        //查询目标
        int targetNum = 5;
        int start = 0;
        int end = nums.length - 1;
        int middle = 0;
        int targetIndex = 0;
        while (start <= end) {
            middle = (start + end) / 2;
            if (nums[middle] > targetNum) {
                end = middle - 1;
            } else if (nums[middle] == targetNum) {
                targetIndex = middle;
                break;
            } else {
                start = middle + 1;
            }
        }
        System.out.println("数据在数组的位置：" + targetIndex);

    }
}