class Solution {
public:
    
    int dfs(int ind) {
        if (vis[ind]) return 0;
        vis[ind] = true;
        int ret = 1;
        for (auto v : adj[ind]) {
            ret += dfs(v);
        }
        return ret;
    }
    
    long long distance(vector<int> &a, vector<int> &b) {
        return (a[0] - b[0] + 0ll) * (a[0] - b[0]) + (0ll + a[1] - b[1]) * (a[1] - b[1]);
    }
    
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size();
        adj.resize(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j) continue;
                if (distance(bombs[i], bombs[j]) <= (long long)bombs[i][2]*(long long)bombs[i][2]) {
                    adj[i].push_back(j);
                }
            }
        }
        vis.resize(n, false);
        int ans = 0;
        for (int i = 0; i < n; i++) {
            vis.clear();
            vis.resize(n, false);
            ans = max(ans, dfs(i));
        }
        return ans;
    }
private:
    vector<bool> vis;
    vector<vector<int>> adj;
};