class Solution {
public:
    
    vector<int> addVector(vector<int> &a, vector<int> &b) {
        for (int i = 0; i < 26; i++) {
            a[i] += b[i];
        }
        return a;
    }
    
    vector<int> solve(int cur, int pre, string &labels) {
        vector<int> ret(26, 0);
        ret[labels[cur] - 'a']++;
        for (auto &v : adj[cur]) {
            if (v == pre) continue;
            auto now = solve(v, cur, labels);
            ret = addVector(ret, now);
        }
        ans[cur] = ret[labels[cur] - 'a'];
        return ret;
    }
    
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string &labels) {
        adj.resize(n);
        ans.resize(n, 0);
        for (auto &edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        solve(0, -1, labels);
        return ans;
    }
private:
    vector<vector<int>> adj;
    vector<int> ans;
};