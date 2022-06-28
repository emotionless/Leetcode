class Solution {
public:
    
    const int MOD = 1e9 + 7;
    const int dices = 6;
    
    int solve(int ind, int prev1, int prev2) {
        if (ind == 0) return 1;
        int &ret = dp[ind][prev1][prev2];
        if (ret != -1) return ret;
        ret = 0;
        for (int i = 1; i <= dices; i++) {
            if (i != prev1 && i != prev2 && __gcd(i, prev1) == 1) {
                ret = (ret + solve(ind - 1, i, prev1)) % MOD;
            }
        }
        return ret;
    }
    
    int distinctSequences(int n) {
        dp.resize(n + 2, vector<vector<int>>(dices + 1, vector<int>(dices + 1, -1)));
        int ans = 0;
        for (int i = 1; i <= 6; i++) {
            ans = (ans + solve(n - 1, i, i)) % MOD;
        }
        return ans;
    }
private:
    vector<vector<vector<int>>> dp;
};