class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        if(n == 0) return;
        int m = matrix[0].size();
        bool row0 = false, col0 = false;
        
        for(int i = 0; i < n; i++) {
            if(matrix[i][0] == 0) col0 = true;
        }
        for(int j = 0; j < m; j++) {
                if(matrix[0][j] == 0) row0 = true;
        }
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(matrix[i][j] == 0) {
                    matrix[i][0] = matrix[0][j] = 0;
                }
            }
        }
        for(int i = 1; i < n; i++) {
            for(int j = 1; j < m; j++) {
                if(matrix[i][0] == 0 || matrix[0][j] == 0) matrix[i][j] = 0;
            }
        }
        
        if(row0) {
            for(int i = 0; i < m; i++) matrix[0][i] = 0;
        }
        if(col0) {
            for(int i = 0; i < n; i++) matrix[i][0] = 0;
        }
        
        return;
    }
};