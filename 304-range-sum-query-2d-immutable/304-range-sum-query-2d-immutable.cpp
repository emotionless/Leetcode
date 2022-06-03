class NumMatrix {
public:
    NumMatrix(vector<vector<int>>& matrix) {
        cumSum.clear();
        int n = matrix.size();
        int m = matrix[0].size();
        cumSum.resize(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cumSum[i][j] = matrix[i][j] + (i>0? cumSum[i-1][j]:0) + (j > 0?cumSum[i][j-1]:0) - ((i>0 && j>0)?cumSum[i-1][j-1]:0);
            }
        }
        
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return cumSum[row2][col2] - (col1 > 0? cumSum[row2][col1-1]:0) - (row1>0? cumSum[row1-1][col2]:0) + ((row1 > 0 && col1 > 0)?cumSum[row1-1][col1-1]:0);
    }
private:
    vector<vector<int>> cumSum;
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */