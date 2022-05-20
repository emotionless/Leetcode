class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        if (n == 1 && m == 1) return 1 - obstacleGrid[0][0];
        vector<vector<int>> dp(n, vector<int> (m, 0));
        dp[0][0] = 1 - obstacleGrid[0][0];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i == j && i == 0) continue;
                dp[i][j] = ((i?dp[i-1][j]:0) + (j?dp[i][j-1]:0)) * (1 - obstacleGrid[i][j]);
            }
        }
        return dp[n-1][m-1];
    }
};