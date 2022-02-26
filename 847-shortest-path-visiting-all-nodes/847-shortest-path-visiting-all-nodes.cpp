class Solution {
public:
    
    int solve(int mask, int cur, int n) {
        if (mask == ((1<<n)-1)) return 0;
        int &ret = dp[mask][cur];
        if (ret != -1) return ret;
        ret = 100000;
        for (int i = 0; i < n; i++) {
            if ((mask&(1<<i))) continue;
            ret = min(ret, dist[cur][i] + solve(mask|(1<<i), i, n));
        }
        return ret;
    }
    
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();
        if (n <= 1) return 0;
        dist.resize(n, vector<int>(n, 100000));
        for (int i = 0; i < n; i++) {
            for (auto v : graph[i]) {
                dist[i][v] = 1;
            }
        }
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
        int ans = INT_MAX;
        dp.resize(1<<n, vector<int>(n, -1));
        for (int i = 0; i < n; i++) {
            ans = min(ans, solve(1<<i, i, n));
        }
        return ans;
    }
private:
    vector<vector<int>> dp, dist;
};