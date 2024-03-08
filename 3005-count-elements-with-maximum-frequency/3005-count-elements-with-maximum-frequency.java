class Solution {
    public int maxFrequencyElements(int[] nums) {
        int[] cnt = new int[101];
        int mx = 0;
        for (int i = 0; i < nums.length; i++) {
            cnt[nums[i]]++;
            mx = Math.max(mx, cnt[nums[i]]);
        }
        int ans = 0;
        for (int i = 1; i <= 100; i++) {
            if (cnt[i] == mx) {
                ans += mx;
            }
        }
        return ans;
    }
}