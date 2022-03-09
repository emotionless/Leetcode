class Solution {
public:
    
    void dfs(int u, int p, vector<vector<int>> &adj, vector<bool> &visited, vector<vector<int>> &ans) {
        visited[u] = true;
        for (auto v : adj[u]) {
            if (visited[v]) continue;
            ans[v].push_back(p);
            dfs(v, p, adj, visited, ans);
        }
    }
    
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj;
        adj.resize(n);
        for (auto edge : edges) {
            adj[edge[0]].push_back(edge[1]);
        }
        vector<vector<int>> ans;
        ans.resize(n);
        
        vector<bool> visited;
        for (int i = 0; i < n; i++) {
            visited.clear();
            visited.resize(n, false);
            dfs(i, i, adj, visited, ans);
        }
        for (auto &v : ans) {
            sort(v.begin(), v.end());
        }
        return ans;
    }
};