class Solution {
    public long countSubarrays(int[] nums, int k) {
        int n = nums.length;
        int[] pos = new int[n];
        int mx = 0;
        for (int num : nums) {
            mx = Math.max(mx, num);
        }
        int ans = 0;
        int cnt = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (mx == nums[i]) {
                cnt++;
                pos[cnt] = i;
            }
            if (cnt >= k) {
                ans += n - (pos[cnt - k + 1]);
            }
        }
        return ans;
    }
}