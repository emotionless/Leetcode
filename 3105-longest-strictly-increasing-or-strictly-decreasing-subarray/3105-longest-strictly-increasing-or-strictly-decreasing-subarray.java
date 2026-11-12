class Solution {
    public int longestMonotonicSubarray(int[] nums) {
        int n = nums.length;
        int increasing = 1;
        int decreasing = 1;
        int ans = 1;
        for (int i = 1; i < n; i++) {
            if (nums[i] > nums[i-1]) {
                increasing++;
            } else {
                increasing = 1;
            }
            if (nums[i] < nums[i-1]) {
                decreasing++;
            } else {
                decreasing = 1;
            }
            ans = Math.max(ans, increasing);
            ans = Math.max(ans, decreasing);
        }
        return ans;
    }
}