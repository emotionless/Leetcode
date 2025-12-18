class Solution {
public:
    long long maximumProfit(vector<int>& prices, int k) {
        int n = prices.size();
        vector<vector<vector<long long>>> dp(
            n, vector<vector<long long>>(k + 1, vector<long long>(3, 0)));
        // initialize the state on day 0
        for (int j = 1; j <= k; j++) {
            dp[0][j][1] = -prices[0];
            dp[0][j][2] = prices[0];
        }

        for (int i = 1; i < n; i++) {
            for (int j = 1; j <= k; j++) {
                dp[i][j][0] =
                    max(dp[i - 1][j][0], max(dp[i - 1][j][1] + prices[i],
                                             dp[i - 1][j][2] - prices[i]));
                dp[i][j][1] =
                    max(dp[i - 1][j][1], dp[i - 1][j - 1][0] - prices[i]);
                dp[i][j][2] =
                    max(dp[i - 1][j][2], dp[i - 1][j - 1][0] + prices[i]);
            }
        }

        return dp[n - 1][k][0];
    }
};