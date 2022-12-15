class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.length();
        int m = text2.length();
        int dp[n+1][m+1];
        memset(dp, 0, sizeof dp);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if (text1[i] == text2[j]) {
                    dp[i][j] = ((i && j)?dp[i-1][j-1] : 0) + 1;
                } else {
                    dp[i][j] = max(i?dp[i-1][j]: 0, j?dp[i][j-1]:0);
                }
            }
        }
        return dp[n-1][m-1];
    }
};