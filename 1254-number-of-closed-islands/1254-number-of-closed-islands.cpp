class Solution {
public:
    
    int dr[4] = {-1, 0, 1, 0};
    int dc[4] = {0, 1, 0, -1};
    
    bool isClosedIsland(int r, int c, vector<vector<int>> &grid) {
        if (r < 0 || r >= n || c < 0 || c >= m) return false;
        if (grid[r][c] == 1) return true;
        if (vis[r][c]) return true;
        vis[r][c] = true;
        bool ret = true;
        for (int i = 0; i < 4; i++) {
            int ax = r + dr[i];
            int ay = c + dc[i];
            ret = ret & isClosedIsland(ax, ay, grid);
        }
        return ret;
    }
    
    int closedIsland(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        vis.resize(n, vector<int>(m, false));
        int region = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 0 && !vis[i][j]) {
                    if (isClosedIsland(i, j, grid)) {
                        region++;
                    }
                }
            }
        }
        return region;
    }
private:
    int n, m;
    vector<vector<int>> vis;
};