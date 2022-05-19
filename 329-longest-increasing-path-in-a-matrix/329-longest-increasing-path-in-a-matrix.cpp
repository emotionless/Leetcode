class Solution {
public:
    
    int dr[4] = {-1, 0, 1, 0};
    int dc[4] = {-0, 1, 0, -1};
    
    int solve(int x, int y, const vector<vector<int>> &matrix) {
        int &ret = dp[x][y];
        if (ret != -1) return ret;
        ret = 0;
        for (int i = 0; i < 4; i++) {
            int ax = x + dr[i];
            int ay = y + dc[i];
            if (ax < 0 || ax >= n || ay < 0 || ay >= m || matrix[ax][ay] <= matrix[x][y]) {
                continue;
            }
            ret = max(ret, 1 + solve(ax, ay, matrix));
        }
        return ret;
    }
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int ans = 0;
        n = matrix.size();
        m = matrix[0].size();
        dp.resize(n, vector<int>(m, -1));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                ans = max(ans, 1 + solve(i, j, matrix));
            }
        }
        return ans;
    }
    
private:
    vector<vector<int>> dp;
    int n, m;
};