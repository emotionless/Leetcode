class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        int m = points[0].size();
        vector<vector<long long>> dp(n, vector<long long>(m, 0));
        for (int i = n - 1; i >= 0; i--) {
            long long mx = 0;
            for (int j = 0; j < m; j++) {
                if ((i+1) < n) {
                    mx = max(mx - 1, dp[i+1][j]);
                }
                dp[i][j] = max(mx + points[i][j], dp[i][j]);
            }
            mx = 0;
            for (int j = m-1; j >= 0; j--) {
                if ((i+1) < n) {
                    mx = max(mx - 1, dp[i+1][j]);
                }
                dp[i][j] = max(mx + points[i][j], dp[i][j]);
            }
        }
        return *max_element(dp[0].begin(), dp[0].end());
    }
};