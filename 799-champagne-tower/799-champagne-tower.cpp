class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<vector<double>> mat(query_row + 1, vector<double>(query_row + 1, 0.0));
        mat[0][0] = poured;
        for (int i = 0; i < query_row; i++) {
            for (int j = 0; j <= i; j++) {
                mat[i+1][j] += max(0.0, (mat[i][j] - 1.0)/2.0);
                mat[i+1][j+1] += max(0.0, (mat[i][j] - 1.0)/2.0);
            }
        }
        return min(1.0, mat[query_row][query_glass]);
    }
};