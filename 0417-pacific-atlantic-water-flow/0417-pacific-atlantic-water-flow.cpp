class Solution {
public:
    
    int dr[4] = {-1, 0, 1, 0};
    int dc[4] = {0, 1, 0, -1};
    
    void dfs(int i, int j, int val, int n, int m, const vector<vector<int>> &heights) {
        if (dp[i][j]&val) return;
        dp[i][j] |= val;
        for (int k = 0; k < 4; k++) {
            int ax = i + dr[k];
            int ay = j + dc[k];
            if (ax < 0 || ay < 0 || ax >= n || ay >= m) continue;
            if (heights[ax][ay] < heights[i][j]) continue;
            dfs(ax, ay, val, n, m, heights);
        }
    }
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        dp.resize(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            dfs(i, 0, 1, n, m, heights);
            dfs(i, m-1, 2, n, m, heights);
        }
        for (int i = 0; i < m; i++) {
            dfs(0, i, 1, n, m, heights);
            dfs(n-1, i, 2, n, m, heights);
        }
        vector<vector<int>> ans;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (dp[i][j] == 3) {
                    ans.push_back({i, j});
                }
            }
        }
        return ans;
    }
private:
    vector<vector<int>> dp;
};