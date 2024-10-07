package chapter05;

public class Java03_Object_Test_1 {
    public static void main(String[] args) {

        //TODO 常见类和对象
        //数组
        int[] nums = {1, 4, 3, 5, 2};
        for (int num : nums) {
            System.out.println(num);
        }
        //TODO 希望获取到的数据, 1,2,3,4,5
        for (int j = 0; j < nums.length - 1; j++) {
            for (int i = 0; i < nums.length - 1; i++) {
                if (nums[i] > nums[i + 1]) {
                    int tmp = nums[i + 1];
                    nums[i + 1] = nums[i];
                    nums[i] = tmp;
                }
            }
        }
        for (int num : nums) {
            System.out.println(num);
        }

    }
}