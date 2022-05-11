class Solution {
public:
    
    // int solve(int ind, int pre, vector<vector<int>> &dp) {
    //     if (ind < 0) return 1;
    //     int &ret = dp[ind][pre];
    //     if (ret != -1) return ret;
    //     ret = 0;
    //     for (int i = pre; i < 5; i++) {
    //         ret += solve(ind - 1, i, dp);
    //     }
    //     return ret;
    // }
    
    int countVowelStrings(int n) {
        vector<vector<int>> dp(2, vector<int>(5, 0));
        
        dp[n%2][0] = dp[n%2][1] = dp[n%2][2] = dp[n%2][3] = dp[n%2][4] = 1;
        
        for (int i = n-1; i >= 0; i--) {
            for (int j = 0; j < 5; j++) {
                dp[i%2][j] = 0;
                for (int k = j; k < 5; k++) {
                    dp[i%2][j] += dp[(i+1)%2][k];
                }
            }
        }
        return dp[0][0];
        
        // return solve(n-1, 0, dp);
    }
};