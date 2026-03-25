class Solution {
public:
    long long totalSum(vector<long long> &vec) {
        long long sum  = 0;
        for (auto &v : vec) sum += v;
        return  sum;
    }
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int n = grid.size();
        int m  = grid[0].size();

        vector<long long> rowSum(n, 0), colSum(m, 0);
        long long row = 0, col = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                colSum[j] += grid[i][j];
                rowSum[i] += grid[i][j];
            }
        }

        row = totalSum(rowSum);
        col = totalSum(colSum);
        long long sum  = 0;
        for (int i = 0; i < n; i++) {
            sum += rowSum[i];
            if (sum*2 == row) return true;
        }
        sum = 0;
        for (int i = 0; i < m; i++) {
            sum += colSum[i];
            if (sum*2 == col) return true;
        }
        return false;
    }
};