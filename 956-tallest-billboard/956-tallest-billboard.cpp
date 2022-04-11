class Solution {
public:
    const int INF = 1e6;
    int solve(int ind, int sum, int &ans, vector<int> &rods) {
        if (sum < 0 || sum > 5000) return -INF;
        if (ind == n) {
            if (sum == 2500) {
                dp[ind][sum] = 0;
            } else {
                dp[ind][sum] = -INF;
            }
            return dp[ind][sum];
        }
        int &ret = dp[ind][sum];
        if (ret != -1) return ret;
        ret = 0;
        ret = solve(ind + 1, sum, ans, rods);
        
        int ret1 = rods[ind] + solve(ind + 1, sum + rods[ind], ans, rods);
        int ret2 = rods[ind] + solve(ind + 1, sum - rods[ind], ans, rods);
        ret = max(ret, ret1);
        ret = max(ret, ret2);
        return ret;
    }
    
    int tallestBillboard(vector<int>& rods) {
        n = rods.size();
        int midSum = accumulate(rods.begin(), rods.end(), 0) / 2;
        dp.resize(n + 1, vector<int>(5009, -1));
        int ans = 0;
        return solve(0, 2500, ans, rods)/2;
    }
private:
    int n;
    vector<vector<int>> dp;
};