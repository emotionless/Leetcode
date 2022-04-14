class Solution {
public:
    
    int dr[4] = {0, 1, 0, -1};
    int dc[4] = {1, 0, -1, 0};
    
    int hashVal(int a, int b) {
        return a*100000 + b;
    }
    
    void dfs(int r, int c, int d, vector<vector<int>> &ans) {
        if (ans.size() == n*m) return;
        int now = hashVal(r, c);
        if (r >= 0 && r < n && c >= 0 && c < m && visited.find(now) == visited.end()) {
            ans.push_back({r, c});
        }
        visited.insert(now);
        
        int ar = r + dr[d], ac = c + dc[d];
        int h = hashVal(ar, ac);
        if (visited.find(h) == visited.end()) {
            dfs(ar, ac, (d+1)%4, ans);
        } else {
            int dir = (d - 1 + 4) % 4;
            dfs(r + dr[dir], c + dc[dir], (d)%4, ans);
        }
        
        return;
    }
    
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        n = rows;
        m = cols;
        vector<vector<int>> ans;
        dfs(rStart, cStart, 0, ans);
        
        return ans;
    }
private:
    int n, m;
    unordered_set<int> visited;
};