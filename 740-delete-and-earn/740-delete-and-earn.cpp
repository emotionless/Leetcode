class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        unordered_map<int, int> value;
        for (auto v : nums) {
            value[v] += v;
        }
        set<int> s(nums.begin(), nums.end());
        vector<int> arr(s.begin(), s.end());
        int n = arr.size();
        vector<int> dp(arr[n-1] + 3, 0);
        for (int i = arr[n - 1]; i >= 0; i--) {
            int mx = value[i];
            mx = dp[i+2] + value[i];
            mx = max(mx, dp[i+1]);
            dp[i] = mx;
        }
        return dp[arr[0]];
    }
};