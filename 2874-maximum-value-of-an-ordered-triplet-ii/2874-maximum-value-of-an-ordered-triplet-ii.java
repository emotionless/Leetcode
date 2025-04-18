class Solution {
    public long maximumTripletValue(int[] nums) {
        int n = nums.length;
        long[] mx = new long[n];
        mx[n-1] = nums[n-1];
        for (int i = n - 2; i >= 0; i--) {
            mx[i] = Math.max(mx[i+1], nums[i]);
        }
        long ans = 0;
        long m = nums[0];
        for (int i = 1; i < n-1; i++) {
            ans = Math.max(ans, (m - nums[i]) * mx[i+1]);
            m = Math.max(m, nums[i]);
        }
        return ans;
    }
}