class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        if(n == 0) return;
        reverse(matrix.begin(), matrix.end());
        int i, j;
        for(i = 0; i < n; i++) {
            for(j = i+1; j < n; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
    }
};