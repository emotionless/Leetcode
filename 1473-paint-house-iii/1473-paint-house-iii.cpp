class Solution {
public:
    const int INF = 10000000;
    
    int solve(int ind, int prev, int have, vector<int> &houses, vector<vector<int>> &cost) {
        if (ind == n) {
            if (have == 0) return 0;
            return INF;
        }
        if (have < 0) return INF;
        int &ret = dp[ind][prev][have];
        if (ret != -1) return ret;
        ret = INF;
        if (houses[ind]) {
            ret = solve(ind + 1, houses[ind], have - (prev != houses[ind]), houses, cost);
        } else {
            for (int i = 1; i <= m; i++) {
                ret = min(ret, cost[ind][i-1] + solve(ind + 1, i, have - (prev != i), houses, cost));
            }
        }
        return ret;
    }
    
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int n, int m, int target) {
        this->n = n;
        this->m = m;
        dp.resize(n, vector<vector<int>>(m + 1, vector<int>(target + 1, -1)));
        int ans = solve(0, 0, target, houses, cost);
        return ans == INF? -1 : ans;
    }
private:
    int n, m;
    vector<vector<vector<int>>> dp;
};