class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector< vector<int> > dp(n+1, vector<int>(m+1, 0));
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                dp[i][j] = dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1] + matrix[i-1][j-1];
                // cout << dp[i][j];
            }
            // cout << endl;
        }
        int ans = 0;
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                int st = 0, ed = min(n-i, m - j);
                int pos = -1;
                while(st <= ed) {
                    int k = (st + ed)/2;
                    int sum = dp[i+k][j+k] - dp[i+k][j-1] - dp[i-1][j+k] + dp[i-1][j-1];
                    if (sum == (k+1)*(k+1)) {
                        pos = k;
                        st = k + 1;
                    } else {
                        ed = k - 1;
                    }
                }
                ans += pos+1;
            }
        }
        return ans;
    }
};