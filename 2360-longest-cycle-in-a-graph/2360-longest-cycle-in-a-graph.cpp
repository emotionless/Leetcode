class Solution {
public:
    
    int dfs(int cur) {
        if (vis[cur]) return 0;
        vis[cur] = true;
        return 1 + dfs(adj[cur]);
    }
    
    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        priority_queue<pair<int, int>> pq;
        vector<int> cnt(n, 0);
        adj = edges;
        vis.resize(n, false);
        int i = 0;
        for (auto &v : edges) {
            if (v != -1) {
                cnt[v]++;
                cnt[i]++;
            }
            i++;
        }
        for (int i = 0; i < n; i++) {
            pq.push({-cnt[i], i});
        }
        while (pq.size()) {
            auto top = pq.top();
            if (-top.first >= 2) break;
            pq.pop();
            if (vis[top.second]) continue;
            vis[top.second] = true;
            if (edges[top.second] == -1) continue;
            cnt[edges[top.second]]--;
            
            pq.push({-cnt[edges[top.second]], edges[top.second]});
        }
        int ans = -1;
        for (int i = 0;i < n; i++) {
            if (!vis[i]) {
                ans = max(ans, dfs(i));
            }
        }
        return ans;
    }
private:
    vector<bool> vis;
    vector<int> adj;
};