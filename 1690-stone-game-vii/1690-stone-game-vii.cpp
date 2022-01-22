class Solution {
public:
    
    int solve(int st, int ed, vector<int> &stones) {
        if (st >= ed) {
            return 0;
        }
        int &ret = dp[st][ed];
        if (ret != -1) return ret;
        ret = 0;
        ret = csum[st + 1][ed] - solve(st + 1, ed, stones);
        ret = max(ret, csum[st][ed-1] - solve(st, ed - 1, stones));
        return ret;
    }
    
    int stoneGameVII(vector<int>& stones) {
        int n = stones.size();
        dp.resize(n, vector<int>(n, -1));
        csum.resize(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            int sum = 0;
            for (int j = i; j < n; j++) {
                sum += stones[j];
                csum[i][j] = sum;
            }
        }
        return solve(0, n-1, stones);
    }
private:
    vector<vector<int>> dp, csum;
};