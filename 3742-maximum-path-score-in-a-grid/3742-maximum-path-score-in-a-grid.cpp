class Solution {
public:
    const int INF = 10000;
    int solve(int i, int j,  int k, vector<vector<int>>  &grid) {
        
        if (i >= n || j >= m || k < 0) return -INF;
        if (i == (n - 1) && j  == (m-1)) {
            return 0;
        }
        int &ret = dp[i][j][k];
        // cout << i << " " << j << " " << k << endl;
        if (ret != -1) return ret;
        ret = -INF;
        if ((i+1) < n)
            ret = max(ret, grid[i+1][j] + solve(i + 1, j, k - (grid[i+1][j]?1:0), grid));
        if ((j + 1) < m)
            ret = max(ret, grid[i][j+1] + solve(i, j + 1, k - (grid[i][j+1]?1:0), grid));
        return ret;
    }
    int maxPathScore(vector<vector<int>>& grid, int k) {
        n = grid.size();
        m  = grid[0].size();
        dp.resize(n, vector<vector<int>>(m,vector<int>(k+1,-1)));
        return max(-1, solve(0, 0,  k, grid));
    }
private:
    vector<vector<vector<int>>>dp;
    int n,m;
};