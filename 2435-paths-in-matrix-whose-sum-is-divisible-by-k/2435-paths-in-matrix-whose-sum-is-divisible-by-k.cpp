class Solution {
public:
    const int INF = 1000000000;
    const int MOD = 1e9 + 7;
    int solve(int i, int j, int sum, int k, vector<vector<int>>& grid) {
        if (i < 0 || i >= n || j < 0 || j >= m) return 0;
        if (i == (n-1) && j == (m-1)) {
            return (sum + grid[i][j]) % k == 0;
        }
        int &ret = dp[i][j][sum];
        if (ret != -1) return ret;
        ret = 0;
        ret = solve(i + 1, j, (sum + grid[i][j]) % k, k, grid);
        ret = (ret + solve(i, j + 1, (sum + grid[i][j]) % k, k, grid)) % MOD;
        return ret;
    }
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        n = grid.size();
        m = grid[0].size();
        dp.resize(n, vector<vector<int>>(m, vector<int>(k, -1)));
        return solve(0, 0, 0, k, grid);
    }
private:
    int n, m;
    vector<vector<vector<int>>> dp;
};