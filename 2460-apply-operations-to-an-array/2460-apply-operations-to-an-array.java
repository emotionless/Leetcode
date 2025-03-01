class Solution {
    public int[] applyOperations(int[] nums) {
        int j = 0;
        for (int i = 0; i < nums.length - 1; i++) {
            if (nums[i] == nums[i+1]) {
                nums[i] = nums[i]*2;
                nums[i+1] = 0;
            }
            if (nums[i] > 0) {
                nums[j++] = nums[i];
            }
        }
        nums[j++] = nums[nums.length - 1];
        while (j < nums.length) {
            nums[j++] = 0;
        }
        return nums;
    }

}