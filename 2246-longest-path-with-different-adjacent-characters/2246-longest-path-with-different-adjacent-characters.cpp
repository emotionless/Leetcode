class Solution {
public:
    
    int dfs(int u, string &s, int &ans) {
        int ret = 0;
        for (auto &v : adj[u]) {
            int nxt = dfs(v, s, ans);
            if (s[v] == s[u]) nxt = 0;
            ans = max(ans, ret + nxt + 1);
            ret = max(ret, nxt);
        }
        return ret + 1;
    }
    
    int longestPath(vector<int>& parent, string s) {
        int n = parent.size();
        if (n == 0) return 0;
        adj.resize(n);
        for (int i = 1; i < n; i++) {
            adj[parent[i]].push_back(i);
        }
        int ans = 1;
        dfs(0, s, ans);
        
        return ans;
    }
private:
    vector<vector<int>> adj;
};