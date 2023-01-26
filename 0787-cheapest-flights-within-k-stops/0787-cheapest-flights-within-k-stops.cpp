class Solution {
public:
    const int INF = 100000000;
    int getCheapestPrice(int cur, int k, const int tar) {
        if (cur == tar) return 0;
        if (k < 0) return INF;
        int &ret = dp[cur][k];
        if (ret != -1) return ret;
        ret = INF;
        for (auto v : adjn[cur]) {
            ret = min(ret, v.second + getCheapestPrice(v.first, k - 1, tar));
        }
        return ret;
    }
    
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        adjn.resize(n);
        dp.resize(n, vector<int>(k+1, -1));
        for (auto v : flights) {
            adjn[v[0]].push_back({v[1], v[2]});
        }
        int ans = getCheapestPrice(src, k, dst);
        return ans == INF? -1 : ans;
    }
private:
    vector<vector<pair<int, int>>> adjn;
    vector<vector<int>> dp;
};