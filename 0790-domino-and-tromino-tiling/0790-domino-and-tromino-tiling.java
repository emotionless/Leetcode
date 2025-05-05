class Solution {
    int MOD = 1000000007;
    int solve(int ind, int msk, int[][] dp) {
        if (ind == -1) {
            if (msk == 0) return 1;
            else return 0;
        }
        int ret = dp[ind][msk];
        if (ret != -1) return ret;
        ret = 0;
        if (msk == 0) {
            ret = (ret + solve(ind - 1, 0, dp)) % MOD;
            ret = (ret + solve(ind - 1, 3, dp)) % MOD;
            ret = (ret + solve(ind - 1, 1, dp)) % MOD;
            ret = (ret + solve(ind - 1, 2, dp)) % MOD;
            
        } else if (msk == 1) {
            ret = (ret + solve(ind - 1, 2, dp)) % MOD;
            ret = (ret + solve(ind - 1, 3, dp)) % MOD;
        } else if (msk == 2) {
            ret = (ret + solve(ind - 1, 1, dp)) % MOD;
            ret = (ret + solve(ind - 1, 3, dp)) % MOD;
        } else {
            ret = solve(ind - 1, 0, dp) % MOD;
        }
        dp[ind][msk] = ret;
        return ret;
    }

    public int numTilings(int n) {
        int[][] dp = new int[n][4];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 4; j++) {
                dp[i][j] = -1;
            }
        }
        return solve(n-1, 0, dp);
    }
}