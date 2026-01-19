class Solution {
public:
    int getSum(int i1,int j1, int  i2, int j2, vector<vector<int>> &dp) {
        return dp[i2][j2] - ((j1-1) >= 0? dp[i2][j1-1] : 0) - ((i1 - 1) >= 0? dp[i1-1][j2] : 0) + (((i1 - 1) >=  0 && (j1 - 1) >= 0)? dp[i1-1][j1-1] :  0);
    }
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> dp(n,  vector<int> (m, 0));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j  < m; j++) {
                if (i == 0 && j == 0) dp[i][j] = mat[i][j];
                else if (i == 0) dp[i][j] = dp[i][j-1] + mat[i][j];
                else if (j == 0) dp[i][j] = dp[i-1][j] + mat[i][j];
                else dp[i][j] = dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1] + mat[i][j]; 
            }
        }
        int ans = -1;
        int st = ans,  ed = n;
        for (int  i = 0; i  < n; i++)  {
            for (int j  = 0; j < m; j++)  {
                st = ans + 1;
                ed  = n;
                while (st <= ed) {
                    int mid = (st +  ed) / 2;
                    if ((i+mid) >= n || (j + mid) >= m) {
                        ed = mid  - 1;
                    }
                    else if (getSum(i, j, i+mid,j+mid, dp) <= threshold) {
                        ans = max(ans, mid);
                        st = mid + 1;
                    } else {
                        ed = mid - 1;
                    }
                }

            }
        }
        return ans + 1;
    }
};