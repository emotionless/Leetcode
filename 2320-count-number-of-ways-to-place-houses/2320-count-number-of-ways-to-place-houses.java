class Solution {

    int MOD = 1000000007;

    int solve(int ind, int f, int s, int[][][] dp) {
        if (ind < 0) return 1;
        if (dp[ind][f][s] != -1) return dp[ind][f][s];
        dp[ind][f][s] = 0;
        dp[ind][f][s] = (dp[ind][f][s] + solve(ind - 1, 0, 0, dp)) % MOD;
        if (f == 0)
            dp[ind][f][s] = (dp[ind][f][s] + solve(ind - 1, 1, 0, dp)) % MOD;
        if (s == 0)
            dp[ind][f][s] = (dp[ind][f][s] + solve(ind - 1, 0, 1, dp)) % MOD;
        if (f == 0 && s == 0)
            dp[ind][f][s] = (dp[ind][f][s] + solve(ind - 1, 1, 1, dp)) % MOD;
        
        return dp[ind][f][s];
    }
    int countHousePlacements(int n) {
        int[][][] dp = new int[n][2][2];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 2; j++) {
                dp[i][j][0] = dp[i][j][1] = -1;
            }
        }
        return solve(n-1, 0, 0, dp);
    }
}