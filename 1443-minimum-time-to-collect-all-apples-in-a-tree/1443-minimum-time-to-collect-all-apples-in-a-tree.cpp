class Solution {
public:
    
    int solve(int curNode, int pre, vector<bool> &hasApple) {
        int ret = 0;
        for (auto &v : adj[curNode]) {
            if (v == pre) continue;
            int nxt = solve(v, curNode, hasApple);
            ret += nxt;
        }
        if (ret > 0 || hasApple[curNode]) ret += 2;
        return ret;
    }
    
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        adj.resize(n);
        for (auto &edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        return max(solve(0, -1, hasApple) - 2, 0);;
    }
private:
    vector<vector<int>> adj;
};