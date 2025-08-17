class Solution {
public:
    double new21Game(int n, int k, int maxPts) {
        if (k == 0 || n >= (k+maxPts)) return 1.0;
        double prob = 1.0/(maxPts + 0.0);
        vector<double> dp(k+maxPts, 0.0);
        dp[0] = 1.0;
        double ans = 0.0;
        double sum = 1.0;
        for (int i = 1; i < (k + maxPts); i++) {
            dp[i] = sum * prob;
            if (i < k) sum += dp[i];
            if ((i-maxPts) >= 0) sum -= dp[i-maxPts];
            if (i >= k && i <= n) {
                ans += dp[i];
            }
        }
        return ans;
    }
};