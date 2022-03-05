class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        unordered_map<int, int> value;
        int mx = 0;
        int mn = 100000;
        for (auto v : nums) {
            value[v] += v;
            mx = max(mx, v);
            mn = min(mn, v);
        }
        vector<int> dp(mx + 3, 0);
        for (int i = mx; i >= mn; i--) {
            int mx = value[i];
            mx = dp[i+2] + value[i];
            mx = max(mx, dp[i+1]);
            dp[i] = mx;
        }
        return dp[mn];
    }
};