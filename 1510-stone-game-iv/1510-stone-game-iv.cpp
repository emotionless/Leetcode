class Solution {
public:
    bool winnerSquareGame(int n) {
        vector<bool> dp(n + 1, false);
        dp[0] = true;
        for (int i = 1; i <= n; i++) {
            int sq = sqrt(i);
            bool check = false;
            for (int j = 1; j <= sq; j++) {
                if (dp[i-j*j] == false || (i-j*j) == 0) {
                    check = true;
                    break;
                }
            }
            dp[i] = check;
        }
        return dp[n];
    }
};