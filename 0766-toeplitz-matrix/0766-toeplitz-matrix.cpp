class Solution {
public:
    
    bool isSimilar(int i, int j, vector<vector<int>> &matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int tar = matrix[i][j];
        while (i < n && j < m) {
            if (matrix[i][j] != tar) return false;
            i++;
            j++;
        }
        return true;
    }
    
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        
        for (int i = 0; i < n; i++) {
            if (!isSimilar(i, 0, matrix)) {
                return false;
            }
        }
        for (int i = 0; i < m; i++) {
            if (!isSimilar(0, i, matrix)) {
                return false;
            }
        }
        return true;
    }
};