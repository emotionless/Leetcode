class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        unordered_map<int, int> value;
        for (auto v : nums) {
            value[v] += v;
        }
        vector<int> dp(10003, 0);
        for (int i = 10000; i >= 0; i--) {
            int mx = value[i];
            mx = dp[i+2] + value[i];
            mx = max(mx, dp[i+1]);
            dp[i] = mx;
        }
        return dp[0];
    }
};