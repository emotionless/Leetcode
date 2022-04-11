class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> ans(n, vector<int>(m, 0));
        k %= (n*m);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int cur = i*m + j;
                int nxt = (cur + k) % (n*m);
                ans[nxt/m][nxt%m] = grid[i][j];
            }
        }
        return ans;
    }
};