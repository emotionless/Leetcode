class Solution {
    public int[] buildArray(int[] nums) {
        int n = nums.length;
        for (int i = 0; i < nums.length; i++) {
            int num = nums[i];
            int pre = n * num;
            if (num < i) {
                nums[i] = pre + nums[num]/n;
            } else {
                nums[i] = pre + nums[num];
            }
        }
        for (int i = 0; i < n; i++) {
            nums[i] %= n;
        }
        return nums;
    }
}