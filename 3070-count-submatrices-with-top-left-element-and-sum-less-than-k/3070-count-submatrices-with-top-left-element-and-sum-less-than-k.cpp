class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> dp(2, vector<int>(m+1, 0));
        int cnt = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                dp[i&1][j] = dp[(i-1)&1][j] + dp[i&1][j-1] - dp[(i-1)&1][j-1] + grid[i-1][j-1];
                if (dp[i&1][j] <= k) cnt++;
                else break;
            }
        }
        return cnt;
    }
};