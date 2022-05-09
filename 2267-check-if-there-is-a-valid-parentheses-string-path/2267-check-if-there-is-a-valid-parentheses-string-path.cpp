class Solution {
public:
    
    bool solve(int x, int y, int tot, vector<vector<char>> &s) {
        if (tot < 0) return 0;
        if (x == (n-1) && y == (m-1)) {
            return (tot + (s[x][y] == ')'? -1 : 1)) == 0;
        }
        
        if (x > (n-1) || y > (m-1)) return 0;
        
        int &ret = dp[x][y][tot];
        if (ret != -1) return ret;
        ret = 0;
        ret = solve(x + 1, y, tot + (s[x][y] == ')'? -1 : 1), s);
        ret += solve(x, y + 1, tot + (s[x][y] == ')'? -1 : 1), s);
        return ret;
    }
    
    bool hasValidPath(vector<vector<char>>& grid) {
        n = grid.size();
        m = grid[0].size();
        dp.resize(n, vector<vector<int>>(m, vector<int>(201, -1)));
        
        return solve(0, 0, 0, grid);
    }
private:
    int n, m;
    vector<vector<vector<int>>> dp;
};