class Solution {
public:
    const int INF = 1e6;
    const int MID = 2500;
    
    int solve(int ind, int sum, vector<int> &rods) {
        if (sum < 0 || sum > 2*MID) return -INF;
        if (ind == n) {
            if (sum == MID) {
                dp[ind][sum] = 0;
            } else {
                dp[ind][sum] = -INF;
            }
            return dp[ind][sum];
        }
        int &ret = dp[ind][sum];
        if (ret != -1) return ret;
        ret = 0;
        ret = solve(ind + 1, sum, rods);
        
        int ret1 = rods[ind] + solve(ind + 1, sum + rods[ind], rods);
        int ret2 = rods[ind] + solve(ind + 1, sum - rods[ind], rods);
        ret = max(ret, ret1);
        ret = max(ret, ret2);
        return ret;
    }
    
    int tallestBillboard(vector<int>& rods) {
        n = rods.size();
        dp.resize(n + 1, vector<int>(2*MID + 1, -1));
        
        return solve(0, MID, rods)/2;
    }
private:
    int n;
    vector<vector<int>> dp;
};