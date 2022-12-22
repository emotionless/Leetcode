class Solution {
public:
    
    pair<int, int> getCost(int cur, int prev, const vector<vector<int>> &adjn) {
        if (dp[cur].find(prev) != dp[cur].end()) return dp[cur][prev];
        dp[cur][prev] = {0, 0};
        int ret = 0;
        int nodes = 1;
        for (auto v : adjn[cur]) {
            if (v != prev) {
                auto res = getCost(v, cur, adjn);
                ret += res.first + res.second;
                nodes += res.second;
            }
        }
        return dp[cur][prev] = make_pair(ret, nodes);
    }
    
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        adjn.resize(n);
        for (auto v : edges) {
            adjn[v[0]].push_back(v[1]);
            adjn[v[1]].push_back(v[0]);
        }
        vector<int> ans(n);
        for (int i = 0; i < n; i++) {
            auto cst = getCost(i, -1, adjn);
            ans[i] = cst.first;
        }
        return ans;
    }
private:
    vector<vector<int>> adjn;
    unordered_map<int, unordered_map<int, pair<int, int>>> dp;
};