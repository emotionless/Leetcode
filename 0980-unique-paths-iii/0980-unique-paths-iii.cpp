class Solution {
public:
    
    int dr[4] = {-1, 0, 1, 0};
    int dc[4] = {0, 1, 0, -1};
    
    void backTrack(int row, int col, vector<vector<int>> &grid, vector<vector<bool>> &visited, int cnt) {
        if (grid[row][col] == 2) {
            if (cnt == -1)
                ans++;
            return;
        }
        for (int i = 0; i < 4; i++) {
            int adjx = row + dr[i];
            int adjy = col + dc[i];
            if (adjx < 0 || adjx >= n || adjy < 0 || adjy >= m || grid[adjx][adjy] == -1) continue;
            if (visited[adjx][adjy]) continue;
            
            visited[row][col] = true;
            backTrack(adjx, adjy, grid, visited, cnt - 1);        
            visited[row][col] = false;
        }
    }
    
    int uniquePathsIII(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        int stx = 0, sty = 0, edx = 0, edy = 0;
        int target = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    stx = i, sty = j;
                } else if (grid[i][j] == 0) {
                    target++;
                }
            }
        }
        visited.resize(n, vector<bool>(m, false));
        visited[stx][sty] = true;
        backTrack(stx, sty, grid, visited, target);
        return ans;
    }
private:
    int n, m;
    int ans = 0;
    vector<vector<bool>> visited;
};