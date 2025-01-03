class Solution {
    public int waysToSplitArray(int[] nums) {
        long sum = 0;
        int n = nums.length;
        for (int num : nums) {
            sum += num;
        }
        long csum = 0;
        int ans = 0;
        for (int i = 0; i < n - 1; i++) {
            sum -= 2*nums[i];
            if (sum <= 0) {
                ans++;
            }
        }
        return ans;
    }
}