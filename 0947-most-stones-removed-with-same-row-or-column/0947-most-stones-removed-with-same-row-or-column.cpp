class Solution {
public:
    /*
    void dfs(int cur, vector<bool> &vis, const vector<vector<int>> &adj) {
        vis[cur] = true;
        for (auto v : adj[cur]) {
            if (!vis[v]) {
                dfs(v, vis, adj);
            }
        }
    }
    
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        if (n == 0) {
            return 0;
        }
        vector<bool> vis(n, false);
        vector<vector<int>> adj;
        adj.resize(n);
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1]) {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        int comp = 0;
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                comp++;
                dfs(i, vis, adj);
            }
        }
        return n - comp;
    }
    */
    
    int find(int x) {
        if (par.find(x) == par.end()) {
            comp++;
            return par[x] = x;
        } else if (par[x] == x) return x;
        return par[x] = find(par[x]);
    }
    
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        par.clear();
        for (auto stone : stones) {
            int x = find(stone[0]);
            int y = find(~stone[1]);
            if (x != y) comp--;
            par[x] = y;
        }
        return n - comp;
    }
private:
    int comp = 0;
    unordered_map<int, int> par;
};