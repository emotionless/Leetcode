class Solution {
    int maxSum(int[] nums, int mul) {
        int sum = 0;
        int ans = 0;
        for (int i = 0; i < nums.length; i++) {
            int num = mul * nums[i];
            sum += num;
            if (sum < 0) {
                sum = 0;
            }
            ans = Math.max(ans, sum);
        }
        return ans;
    }
    public int maxAbsoluteSum(int[] nums) {
        return Math.max(maxSum(nums, 1), maxSum(nums, -1));
    }
}