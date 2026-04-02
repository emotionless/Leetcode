class Solution {
public:
    const int MINIMUM  = -1000000;
    int solve(int i, int j, int n, int m, vector<vector<int>> &coins, int k) {
        if (i == (n-1) && j == (m-1)) {
            if (k > 0) return max(0,  coins[i][j]);
            return coins[i][j];
        }
        if (i >= n || j >= m) return MINIMUM;
        int &ret = dp[i][j][k];
        if (ret != MINIMUM) return ret;
        ret = MINIMUM;
        ret = coins[i][j] + max(solve(i + 1, j, n, m, coins, k), solve(i, j + 1, n, m, coins, k));
        if (k > 0) {
            ret = max(ret, max(solve(i + 1, j, n, m, coins, k - 1), solve(i, j + 1, n, m, coins, k - 1)));
        }
        return ret;
    }
    int maximumAmount(vector<vector<int>>& coins) {
        int n = coins.size();
        int m = coins[0].size();
        dp.resize(n, vector<vector<int>>(m, vector<int>(3, MINIMUM)));
        return solve(0, 0, n, m, coins, 2);
    }
private:
    vector<vector<vector<int>>> dp;
};