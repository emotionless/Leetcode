class Solution {
public:
    
    int solve(int st, int ed, vector<int> &stones) {
        if (st >= ed) {
            return 0;
        }
        int &ret = dp[st][ed];
        if (ret != -1) return ret;
        ret = 0;
        ret = csum[ed + 1] - csum[st + 1] - solve(st + 1, ed, stones);
        ret = max(ret, csum[ed] - csum[st] - solve(st, ed - 1, stones));
        return ret;
    }
    
    int stoneGameVII(vector<int>& stones) {
        int n = stones.size();
        dp.resize(n, vector<int>(n, -1));
        csum.resize(n + 1, 0);
        for (int i = 0; i < n; i++) {
            csum[i+1] = stones[i] + csum[i];
        }
        return solve(0, n - 1, stones);
    }
private:
    vector<vector<int>> dp;
    vector<int> csum;
};