class Solution {
public:
    
    int solve(int r, int c1, int c2, vector<vector<int>> &grid) {
        if (r == n || c1 < 0 || c1 >= m || c2 < 0 || c2 >= m) return 0;
        int &ret = dp[r][c1][c2];
        if (ret != -1) return ret;
        ret = 0;
        int cur = grid[r][c1] + grid[r][c2];
        if (c1 == c2) {
            cur -= grid[r][c1];
        }
        ret = max(ret, solve(r + 1, c1 + 1, c2 + 1, grid));
        ret = max(ret, solve(r + 1, c1 + 1, c2, grid));
        ret = max(ret, solve(r + 1, c1 + 1, c2 - 1, grid));
        
        ret = max(ret, solve(r + 1, c1, c2 + 1, grid));
        ret = max(ret, solve(r + 1, c1, c2, grid));
        ret = max(ret, solve(r + 1, c1, c2 - 1, grid));
        
        ret = max(ret, solve(r + 1, c1 - 1, c2 + 1, grid));
        ret = max(ret, solve(r + 1, c1 - 1, c2, grid));
        ret = max(ret, solve(r + 1, c1 - 1, c2 - 1, grid));
        
        ret += cur;
        
        return ret;
    }
    
    int cherryPickup(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        dp.resize(n, vector<vector<int>> (m, vector<int>(m, -1)));
        
        return solve(0, 0, m-1, grid);
    }
private:
    int n, m;
    vector<vector<vector<int>>> dp;
};