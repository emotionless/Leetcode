class Solution {
public:
    long long maximumTotalDamage(vector<int>& power) {
        int n = power.size();
        int j = 0;
        sort(power.begin(), power.end());
        vector<long long> dp(n, 0);
        dp[0] = power[0];
        long long ans = dp[0];
        long long now = 0;
        for (int i = 1; i < n; i++) {
            if (power[i] == power[i-1]) {
                dp[i] = dp[i-1] + power[i];
            } else {
                while (j < i && power[j] < (power[i]-2)) {
                    now = max(now, dp[j]);
                    j++;
                }
                dp[i] = now + power[i];
            }
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};