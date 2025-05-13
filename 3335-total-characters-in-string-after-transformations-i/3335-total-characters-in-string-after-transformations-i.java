class Solution {
    int MOD = 1000000007;

    int solve(char ch, int t, int[][] dp) {
        if (t <= 0) return 1;
        int p = (int) ch - (int)'a';
        if (dp[p][t] != -1) return dp[p][t];
        dp[p][t] = 0;

        int d = (int)'z' - (int) ch;
        d++;
        int ret = 0;
        if (t >= d) {
            ret = (solve('a',  t - d, dp) + solve('b',  t - d, dp)) % MOD;
        } else {
            ret = 1;
        }
        // System.out.println(ch + " " + t + " " + ret);
        return dp[p][t] = ret;
    }
    public int lengthAfterTransformations(String s, int t) {
        int ans = 0;
        int[][] dp = new int[26][t + 1];
        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < t + 1; j++) {
                dp[i][j] = -1;
            }
        }
        for (int i = 0; i < s.length(); i++) {
            ans = (ans + solve(s.charAt(i), t, dp)) % MOD;
        }
        return ans;
    }
}