class Solution {
public:
    
    int dfs(int u) {
        int ret = 0;
        seen[u] = true;
        for (auto v : adj[u]) {
            if (!seen[v]) {
                if (vis.find(make_pair(u, v)) == vis.end()) {
                    ret++;
                }
                ret += dfs(v);
            }
        }
        // cout << u << " " << ret << endl;
        return ret;
    }
    
    int minReorder(int n, vector<vector<int>>& connections) {
        adj.resize(n);
        seen.resize(n, false);
        for (auto v : connections) {
            vis[make_pair(v[1], v[0])] = true;
            adj[v[0]].push_back(v[1]);
            adj[v[1]].push_back(v[0]);
        }
        return dfs(0);
    }
private:
    vector<vector<int>> adj;
    map<pair<int, int>, bool> vis;
    vector<bool> seen;
};