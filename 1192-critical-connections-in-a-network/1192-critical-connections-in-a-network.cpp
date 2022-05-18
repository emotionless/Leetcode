class Solution {
public:
    
    void tarjan(int u, int p) {
        index[u] = low[u] = (++id);
        stk.push(u);
        isStacked[u] = true;
        for (auto v : adj[u]) {
            if (v == p) continue;
            if (index[v] == -1) {
                tarjan(v, u);
                low[u] = min(low[u], low[v]);
            } else if(isStacked[v] == true) {
                low[u] = min(low[u], index[v]);
            }
        }
        int v;
        cmp++;
        if (index[u] == low[u]) {
            do {
                v = stk.top();
                stk.pop();
                isStacked[v] = false;
                component[v] = cmp;
            } while(v != u);
        }

    }
    
    vector<vector<int>> criticalConnections(int n, const vector<vector<int>>& connections) {
        id = 0;
        cmp = 0;
        adj.resize(n);
        for(auto v : connections) {
            adj[v[0]].push_back(v[1]);
            adj[v[1]].push_back(v[0]);
        }
        
        index.resize(n, -1);
        tarjan(0, -1);
        vector<vector<int>> ans;
        for(auto v : connections) {
            if (component[v[0]] != component[v[1]]) {
                ans.push_back(v);
            }
        }
        return ans;
    }
private:
    int id = 0, cmp = 0;
    stack<int> stk;
    unordered_map<int, bool> isStacked;
    unordered_map<int, int> low, component;
    vector<vector<int>> adj;
    vector<int> index;
};