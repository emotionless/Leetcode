class Solution {
public:
    int maximumJumps(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> dp(n, -n*2);
        dp[n-1] = 0;
        for (int i = n - 1; i >= 0; i--) {
            for (int j = i + 1; j < n; j++) {
                if (abs(nums[i] - nums[j]) <= target) {
                    dp[i] = max(dp[i], 1 + dp[j]);
                }
            }
        }
        return max(-1, dp[0]);
    }
};