class Solution {
public:
        int numberOfSubmatrices(vector<vector<char>>& A) {
        int n = A.size(), m = A[0].size(), res = 0;
        vector<vector<int>> X(n + 1, vector<int>(m + 1));
        vector<vector<int>> Y(n + 1, vector<int>(m + 1));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                X[i + 1][j + 1] = X[i][j + 1] + X[i + 1][j] - X[i][j] + (A[i][j] == 'X');
                Y[i + 1][j + 1] = Y[i][j + 1] + Y[i + 1][j] - Y[i][j] + (A[i][j] == 'Y');
                if (X[i + 1][j + 1] == Y[i + 1][j + 1] && X[i + 1][j + 1] > 0) {
                    res++;
                }
            }
        }
        return res;
    }
};