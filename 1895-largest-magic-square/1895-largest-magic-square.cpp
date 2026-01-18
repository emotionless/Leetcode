class Solution {
public:
    
    bool isMagic(int i, int j, int k, const vector<vector<int>> &grid) {
        int sum = 0;
        for (int p = j; p <= (j + k); p++) {
            sum += grid[i][p];
        }
        for (int x = i; x <= (i + k); x++) {
            int rowSum = 0;
            for (int y = j; y <= (j + k); y++) {
                rowSum += grid[x][y];
            }
            if (rowSum != sum) return false;
        }
        for (int y = j; y <= (j + k); y++) {
            int colSum = 0;
            for (int x = i; x <= (i + k); x++) {
                colSum += grid[x][y];
            }
            if (colSum != sum) return false;
        }
        int diagSum = 0;
        for (int p = 0; p <= k; p++) {
            diagSum += grid[i+p][j+p];
        }
        if (diagSum != sum) return false;
        
        diagSum = 0;
        for (int p = 0; p <= k; p++) {
            diagSum += grid[i+p][j+k-p];
        }
        if (diagSum != sum) return false;
        
        return true;
    }
    
    int largestMagicSquare(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                for (int k = min(n - i - 1, m - j - 1); k >= 0; k--) {
                    if (isMagic(i, j, k, grid)) {
                        ans = max(ans, k);
                        break;
                    }
                }
            }
        }
        return ans + 1;
    }
};