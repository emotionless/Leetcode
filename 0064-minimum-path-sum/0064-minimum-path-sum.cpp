class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int i, n = grid.size();
        int j, m = grid[0].size();
        for(i = n - 1; i >= 0; i--) {
            for(j = m-1; j >= 0; j--) {
                
                if (i == (n-1) && j == (m-1)) continue;
                int a = (i+1) < n? grid[i+1][j] : 1000000000;
                int b = (j+1) < m? grid[i][j+1] : 1000000000;
                grid[i][j] += min(a, b);
            }
        }
        return grid[0][0];
    }
};