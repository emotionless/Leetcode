class Solution {
public:
    int dr[4] = {-1, 0, 1, 0};
    int dc[4] = {0, 1, 0, -1};
    
    int closedIsland(int r, int c, vector<vector<int>> &grid) {
        if (r < 0 || r >= n || c < 0 || c >= m) return 0;
        if (grid[r][c] == 0) return 0;
        grid[r][c] = 0;
        int ret = 1;
        for (int i = 0; i < 4; i++) {
            int ax = r + dr[i];
            int ay = c + dc[i];
            ret += closedIsland(ax, ay, grid);
        }
        return ret;
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    ans = max(ans, closedIsland(i, j, grid));
                }
            }
        }
        return ans;
    }
private:
    int n, m;
};