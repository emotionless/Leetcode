class Solution {
public:
    
    int solve(int ind) {
        if (vis[ind]) return INT_MAX;
        vis[ind] = true;
        int ret = INT_MAX;
        for (auto &v : adj[ind]) {
            ret = min(ret, v.second);
            ret = min(ret, solve(v.first));
        }
        return ret;
    }
    
    int minScore(int n, vector<vector<int>>& roads) {
        adj.resize(n + 1);
        for (auto &road : roads) {
            adj[road[0]].push_back({road[1], road[2]});
            adj[road[1]].push_back({road[0], road[2]});
        }
        vis.resize(n + 1, false);
        return solve(1);
    }
private:
    vector<bool> vis;
    vector<vector<pair<int, int>>> adj;
};