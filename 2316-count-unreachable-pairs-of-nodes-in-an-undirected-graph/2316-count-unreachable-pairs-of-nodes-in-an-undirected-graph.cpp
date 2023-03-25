class Solution {
public:
    
    int dfs(int cur) {
        if (vis[cur]) return 0;
        vis[cur] = true;
        int ret = 1;
        for (auto &v : adj[cur]) {
            ret += dfs(v);
        }
        return ret;
    }
    
    long long countPairs(int n, vector<vector<int>>& edges) {
        adj.resize(n);
        vis.resize(n, false);
        for (auto &edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        long long sum = 0;
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                int cnt = dfs(i);
                ans += sum * cnt;
                sum += cnt;
            }
        }
        return ans;
    }
private:
    vector<bool> vis;
    vector<vector<int>> adj;
};