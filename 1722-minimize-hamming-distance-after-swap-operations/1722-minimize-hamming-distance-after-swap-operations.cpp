class Solution {
public:
    
    void dfs(int u, vector<vector<int>> &adj, vector<int> &source, vector<int> &target) {
        if (visited[u] == true) {
            return;
        }
        visited[u] = true;
        counter[source[u]]++;
        targetCounter[target[u]]++;
        for (auto v : adj[u]) {
            if (!visited[v]) {
                dfs(v, adj, source, target);
            }
        }
        return;
    }
    
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        int n = source.size();
        vector<vector<int>> adj;
        adj.resize(n);
        visited.resize(n, false);
        for (auto v : allowedSwaps) {
            adj[v[0]].push_back(v[1]);
            adj[v[1]].push_back(v[0]);
        }
        int match = 0;
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                targetCounter.clear();
                counter.clear();
                dfs(i, adj, source, target);
                for (auto v : counter) {
                    match += min(v.second, targetCounter[v.first]);
                }
            }
        }
        return n - match;
    }
private:
    unordered_map<int, int> counter, targetCounter;
    vector<bool> visited;
};