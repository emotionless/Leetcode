class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n + 1, 0);
        dp[1] = 1;
        for (int i = 1; i <= n; i++) {
            dp[i] = n;
            for (int j = 1; j*j <= i; j++) {
                dp[i] = min(dp[i], dp[i - j*j] + 1);
            }
        }
        return dp[n];
    }
};