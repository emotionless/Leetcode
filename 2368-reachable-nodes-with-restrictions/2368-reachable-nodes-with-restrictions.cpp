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
    
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        adj.resize(n);
        vis.resize(n, false);
        for (auto &edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        for (auto &node : restricted) {
            vis[node] = true;
        }
        return dfs(0);
    }
private:
    vector<bool> vis;
    vector<vector<int>> adj;
};