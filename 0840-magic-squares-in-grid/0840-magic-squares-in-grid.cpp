class Solution {
public:
    bool isMagic(int i, int j, const vector<vector<int>> &grid) {
        int sum = grid[i][j] + grid[i][j + 1] + grid[i][j + 2];
        set<int> num;
        for (int k = 0; k < 3; k++) {
            int cs = 0;
            int s = 0;
            for (int l = 0; l < 3; l++) {
                cs += grid[i+k][j+l];
                s += grid[i+l][j+k];
                if (grid[i+k][j+l] < 10 && grid[i+k][j+l] > 0)
                    num.insert(grid[i+k][j+l]);
            }
            if (cs != sum || s != sum) return false;
        }
        if (num.size() != 9) return false;
        return sum == (grid[i][j] + grid[i+1][j+1] + grid[i+2][j+2]) && sum == (grid[i+2][j] + grid[i+1][j + 1] + grid[i][j + 2]);
    }
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int ans = 0;
        int n = grid.size();
        if (n == 0) return 0;
        int m = grid[0].size();
        if (m == 0) return 0;
        for (int i = 0; (i + 2) < n; i++) {
            for (int j = 0; (j + 2) < m; j++) {
                if (isMagic(i, j, grid)) {
                    ans++;
                }
            }
        }
        return ans;
    }
};