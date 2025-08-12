class Solution {
public:
    int apply(int num) {
        int ret = 1;
        for (int i = 0; i < X; i++) {
            ret = ret * num;
            if (ret > 300) ret = 301;
        }
        return ret;
    }
    int solve(int remaining, int cur) {
        if (remaining == 0) {
            return 1;
        } else if (remaining < 0) return 0;
        if (cur > remaining) return 0;
        int &ret = dp[remaining][cur];
        if (ret != -1) return ret;
        ret = 0;
        ret = solve(remaining, cur + 1);
        ret += solve(remaining - apply(cur), cur + 1);
        // cout << remaining << " " << cur << " " << ret << endl;

        return ret;
    }
    int numberOfWays(int n, int x) {
        X = x;
        dp.resize(n + 1, vector<int>(n + 1, -1));
        return solve(n, 1);
    }
private:
    int X;
    vector<vector<int>> dp;
};