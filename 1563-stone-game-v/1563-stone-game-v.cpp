class Solution {
public:
    
    int solve(int st, int ed, vector<int> &stoneValue) {
        if (st >= ed) return 0;
        int &ret = dp[st][ed];
        if (ret != -1) return ret;
        ret = 0;
        int i = st, j = ed;
        for (int i = st; i < ed; i++) {
            int sum1 = prefix[st][i], sum2 = prefix[i+1][ed];
            if (sum1 < sum2) {
                ret = max(ret, sum1 + solve(st, i, stoneValue));
            } else if (sum2 < sum1) {
                ret = max(ret, sum2 + solve(i + 1, ed, stoneValue));
            } else {
                ret = max(sum1 + solve(st, i, stoneValue), sum2 + solve(i + 1, ed, stoneValue));
            }
        }
        return ret;
    }
    
    int stoneGameV(vector<int>& stoneValue) {
        int n = stoneValue.size();
        dp.resize(n, vector<int>(n, -1));
        prefix.resize(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            int sum = 0;
            for (int j = i; j < n; j++) {
                sum += stoneValue[j];
                prefix[i][j] = sum;
            }
        }
        return solve(0, n-1, stoneValue);
    }
private:
    vector<vector<int>> dp;
    vector<vector<int>> prefix;
};