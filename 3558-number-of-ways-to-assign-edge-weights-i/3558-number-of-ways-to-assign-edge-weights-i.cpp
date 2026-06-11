class Solution {
public:
    int getDepth(int u, int pre, unordered_map<int, vector<int>> &adj) {
        int ret = 0;
        for (auto v : adj[u]) {
            if (v != pre) {
                ret = max(ret, 1 + getDepth(v, u, adj));
            }
        }
        return ret;
    }
    
    const int MOD = 1e9 + 7;
    
    int solve(int cur, int n, bool is) {
        if  (cur == n) {
            return is;
        }
        int &ret = dp[cur][is];
        if (ret != -1) return ret;
        ret = 0;
        // even
        ret = solve(cur + 1, n, is);

        // odd
        ret = (ret + solve(cur + 1, n, is^1)) % MOD;

        return ret;
    }

    int assignEdgeWeights(vector<vector<int>>& edges) {
        int m = edges.size();
        int n = m + 1;
        unordered_map<int, vector<int>> adj;
        for  (auto  edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        int depth = getDepth(1, -1, adj);

        dp.resize(depth, vector<int>(2, -1));

        return solve(0, depth, 0);
    }
private:
    vector<vector<int>> dp;
};