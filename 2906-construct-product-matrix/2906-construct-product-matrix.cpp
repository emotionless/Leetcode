class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int n =  grid.size();
        int m = grid[0].size();

        long long  suffix = 1ll;
        vector<vector<int>> preMul(n, vector<int>(m, 1));
        vector<vector<int>> sufMul(n, vector<int>(m, 1));
        const int MOD = 12345;

        for (int i = n - 1; i  >=  0; i--) {
            for (int j =  m - 1; j  >= 0;  j--) {
                sufMul[i][j] = suffix;
                suffix = (suffix * grid[i][j]) % MOD;
            }
        }

        long long  prefix = 1ll;

        for (int i = 0; i  <  n; i++) {
            for (int j =  0; j < m;  j++) {
                preMul[i][j] = (prefix * sufMul[i][j])%MOD;
                prefix = (prefix * grid[i][j]) % MOD;
            }
        }
        return preMul;
    }
};