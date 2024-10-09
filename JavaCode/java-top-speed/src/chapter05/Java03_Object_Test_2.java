package chapter05;

public class Java03_Object_Test_2 {
    public static void main(String[] args) {

        //TODO 常见类和对象
        //数组 - 选择排序
        int[] nums = {1, 4, 3, 5, 2};

        int maxIndex = 0;

        for (int i = 0; i < nums.length; i++) {
            for (int n = 0; n < nums.length - i; n++) {
                if (nums[n] > nums[maxIndex]) {
                    maxIndex = n;
                }
            }
            int tmp = nums[nums.length - 1 - i];
            nums[nums.length - 1 - i] = nums[maxIndex];
            nums[maxIndex] = tmp;
            maxIndex = 0;
        }

        for (int num : nums) {
            System.out.println(num);
        }

    }
}