class Solution {
    public int maxAdjacentDistance(int[] nums) {
        int n = nums.length;
        int mx = 0;
        for (int i = 1; i < n; i++) {
            mx = Math.max(mx, Math.abs(nums[i] - nums[i-1]));
        }
        mx = Math.max(mx, Math.abs(nums[0] - nums[n-1]));

        return mx;
    }
}