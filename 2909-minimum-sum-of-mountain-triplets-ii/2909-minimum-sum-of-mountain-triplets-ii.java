class Solution {
    public int minimumSum(int[] nums) {
        int n = nums.length;
        int[] leftMin = new int[n];
        int mn = nums[0];
        for (int i = 0; i < n; i++) {
            mn = Math.min(mn, nums[i]);
            leftMin[i] = mn;
        }
        mn = nums[n - 1];
        int ans = Integer.MAX_VALUE;
        for (int i = n - 2; i > 0; i--) {
            if (leftMin[i - 1] < nums[i] && mn < nums[i]) {
                ans = Math.min(ans, leftMin[i - 1] + nums[i] + mn);
            }
            mn = Math.min(mn, nums[i]);
        }
        return ans == Integer.MAX_VALUE? -1 : ans;
    }
}