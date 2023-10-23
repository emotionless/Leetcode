class Solution {
public:
    
    int solve(int alice, int bob) {
        
        int ret = 0;
        // cout << alice << " " << bob << endl;
        if (alice == bob) {
            ret = amount[alice]/2;
        } else {
            ret = amount[alice];
        }
        if (adj[alice].size() == 0) {
            return ret;
        }
        int a = amount[alice], b = amount[bob];
        amount[alice] = amount[bob] = 0;
        int mx = -1000000;
        for (auto &v : adj[alice]) {
            if (revAdj[bob].size())
                mx = max(mx, ret + solve(v, revAdj[bob][0]));
            else
                mx = max(mx, ret + solve(v, bob));
        }
        amount[alice] = a;
        amount[bob] = b;
        return mx;
    }
    
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& _amount) {
        for (auto &edge : edges) {
            conn[edge[0]].push_back(edge[1]);
            conn[edge[1]].push_back(edge[0]);
        }
        
        build(0);
        
        amount = _amount;
        return solve(0, bob);
    }
    
    void build(int u) {
        vis[u] = true;
        for (auto &v : conn[u]) {
            if (!vis[v]) {
                adj[u].push_back(v);
                revAdj[v].push_back(u);
                build(v);
            }
        }
    }
    
private:
    unordered_map<int, vector<int>> conn, adj, revAdj;
    vector<int> amount;
    unordered_map<int, bool> vis;
    
};

/*

    0       1
2       5       3

4

        0
    2       4
1
    3
     
*/