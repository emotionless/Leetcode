class Solution {
public:
    int maxProductPath(vector<vector<int>>& grid) {
        int n = grid.size();
        if (n == 0) return 0;
        int m = grid[0].size();
        
        vector<vector<long long>> mn_mat(n, vector<long long>(m, 0ll));
        vector<vector<long long>> mx_mat(n, vector<long long>(m, 0ll));
        
        for(int i = n - 1; i >= 0; i--) {
            for(int j = m - 1; j >= 0; j--) {
                mn_mat[i][j] = LLONG_MAX;
                mx_mat[i][j] = LLONG_MIN;
                if ((j+1) < m) {
                    mn_mat[i][j] = min(mn_mat[i][j], min(mn_mat[i][j+1] * grid[i][j], mx_mat[i][j+1] * grid[i][j]));
                    mx_mat[i][j] = max(mx_mat[i][j], max(mx_mat[i][j+1] * grid[i][j], mn_mat[i][j+1] * grid[i][j]));
                }
                if ((i+1) < n) {
                    mn_mat[i][j] = min(mn_mat[i][j], min(mn_mat[i+1][j] * grid[i][j], mx_mat[i+1][j] * grid[i][j]));
                    mx_mat[i][j] = max(mx_mat[i][j], max(mx_mat[i+1][j] * grid[i][j], mn_mat[i+1][j] * grid[i][j]));
                }
                if (mn_mat[i][j] == LLONG_MAX) mn_mat[i][j] = grid[i][j];
                if (mx_mat[i][j] == LLONG_MIN) mx_mat[i][j] = grid[i][j];
                // cout << i << " " << j << " " << mn_mat[i][j] << " " << mx_mat[i][j] << endl;
            }
        }
        return max(-1ll, mx_mat[0][0]) % 1000000007;
    }
};