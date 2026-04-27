class Solution {
public:
    
    int dr[4] = {-1, 0, 1, 0};
    int dc[4] = {0, 1, 0, -1};
    
    bool isValid(int x, int y) {
        if (x == (n*3 - 2) && y == (m*3 - 2)) {
            return true;
        }
        vis[x][y] = false;
        int ret = 0;
        for (int i = 0; i < 4; i++) {
            int ax = x + dr[i];
            int ay = y + dc[i];
            if (ax < 0 || ax >= n*3 || ay < 0 || ay >= m*3 || vis[ax][ay] == false) continue;
            ret = ret + isValid(ax, ay);
            if (ret) break;
        }
        return ret;
    }
    
    bool hasValidPath(vector<vector<int>>& grid) {
        /*
        isConnected.resize(7, vector<vector<bool>> (7, vector<bool>(4, false)));
        isConnected[1][1][1] = true;
        isConnected[1][1][3] = true;
        isConnected[1][3][1] = true;
        isConnected[1][4][3] = true;
        isConnected[1][5][1] = true;
        isConnected[1][6][3] = true;
        
        isConnected[2][2][0] = true;
        isConnected[2][2][2] = true;
        isConnected[2][3][0] = true;
        isConnected[2][4][0] = true;
        isConnected[2][5][2] = true;
        isConnected[2][6][2] = true;
        
        isConnected[3][1][3] = true;
        isConnected[3][2][2] = true;
        isConnected[3][4][3] = true;
        isConnected[3][5][2] = true;
        isConnected[3][6][2] = true;
        isConnected[3][6][3] = true;
        
        isConnected[4][1][1] = true;
        isConnected[4][2][2] = true;
        isConnected[4][3][1] = true;
        isConnected[4][5][1] = true;
        isConnected[4][5][2] = true;
        isConnected[4][6][2] = true;
        
        isConnected[5][1][3] = true;
        isConnected[5][2][0] = true;
        isConnected[5][3][0] = true;
        isConnected[5][4][0] = true;
        isConnected[5][4][3] = true;
        isConnected[5][6][3] = true;
        
        isConnected[6][1][1] = true;
        isConnected[6][2][0] = true;
        isConnected[6][3][0] = true;
        isConnected[6][3][1] = true;
        isConnected[6][4][0] = true;
        isConnected[6][5][1] = true;
        */
        
        n = grid.size();
        if (n == 0) return true;
        m = grid[0].size();
        if (m == 0) return false;
        vis.resize(n*3, vector<bool>(m*3, false));
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                vis[i*3 + 0][j*3 + 1] = (grid[i][j] == 2 || grid[i][j] == 5 || grid[i][j] == 6);
                vis[i*3 + 1][j*3 + 0] = (grid[i][j] == 1 || grid[i][j] == 3 || grid[i][j] == 5);
                vis[i*3 + 1][j*3 + 1] = true;
                vis[i*3 + 1][j*3 + 2] = (grid[i][j] == 1 || grid[i][j] == 4 || grid[i][j] == 6);
                vis[i*3 + 2][j*3 + 1] = (grid[i][j] == 2 || grid[i][j] == 3 || grid[i][j] == 4);
            }
        }
        return isValid(1, 1);
    }
private:
    // vector<vector<vector<bool>>> isConnected;
    vector<vector<bool>> vis;
    int n, m;
};