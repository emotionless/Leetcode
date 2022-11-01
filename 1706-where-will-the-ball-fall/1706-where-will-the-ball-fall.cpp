class Solution {
public:
    
    int dr[4] = {0, 1, 0};
    int dc[4] = {1, 0, -1};
    
    
    int dfs(int i, int j, int preI, int preJ, vector<vector<int>> &mat) {
        if (i == (N - 1)) return j/3;
        int &ret = dp[i][j];
        if (ret != -1) return ret;
        ret = -1;
        for (int k = 0; k < 3; k++) {
            int ai = i + dr[k];
            int aj = j + dc[k];
            if (ai < 0 || ai >= N || aj < 0 || aj >= M || mat[ai][aj] == false) continue;
            if (ai == preI && aj == preJ) continue;
            ret = dfs(ai, aj, i, j, mat);
        }
        return ret;
    }
    
    vector<int> findBall(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> mat(n*3, vector<int>(m*3, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1)
                    mat[i*3][j*3 + 1] = mat[i*3][j*3 + 2] = mat[i*3 + 1][j*3 + 2] = mat[i*3 + 1][j*3 + 0] = mat[i*3 + 2][j*3 + 0] = mat[i*3 + 2][j*3 + 1] = true;
                else
                    mat[i*3][j*3 + 0] = mat[i*3][j*3 + 1] = mat[i*3 + 1][j*3 + 0] = mat[i*3 + 1][j*3 + 2] = mat[i*3 + 2][j*3 + 1] = mat[i*3 + 2][j*3 + 2] = true;
            }
        }
        N = n*3, M = m*3;
        dp.resize(n*3, vector<int>(m*3, -1));
        vector<int> ans;
        for (int i = 0; i < m; i++) {
            ans.push_back(dfs(0, i*3 + 1, 0, i*3 + 1, mat));
        }
        return ans;
    }
private:
    vector<vector<int>> dp;
    int N, M;
};