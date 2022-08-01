class Solution {
public:
    int uniquePaths(int n, int m) {
        vector<vector<int>> dp(n, vector<int>(m, 0));
        
        for (int i = n-1; i >= 0; i--) {
            for (int j = m-1; j >= 0; j--) {
                if (i == (n-1) && j == (m-1)) {
                    dp[i][j] = 1;
                } else {
                    dp[i][j] = ((i+1) < n? dp[i+1][j] : 0) + ((j+1) < m? dp[i][j+1] : 0);
                }
            }
        }
        return dp[0][0];
    }
};