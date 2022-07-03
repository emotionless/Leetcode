class Solution {
public:
    const int MOD = 1e9 + 7;
    int dr[4] = {0, 1, 0, -1};
    int dc[4] = {1, 0, -1, 0};
    
    int dfs(int r, int c, vector<vector<int>> &grid) {
        int &ret = dp[r][c];
        if (ret != -1) return ret;
        ret = 1;
        for (int i = 0; i < 4; i++) {
            int ar = r + dr[i];
            int ac = c + dc[i];
            if (ar < 0 || ar >= n || ac < 0 || ac >= m || grid[ar][ac] <= grid[r][c]) continue;
            ret = (ret + dfs(ar, ac, grid)) % MOD;
        }
        return ret;
    }
    
    int countPaths(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        dp.resize(n, vector<int>(m, -1));
        
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                ans = (ans + dfs(i, j, grid)) % MOD;
            }
        }
        return ans;
    }
private:
    int n, m;
    vector<vector<int>> dp;
};