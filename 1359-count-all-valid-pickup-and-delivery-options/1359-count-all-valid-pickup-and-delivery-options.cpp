class Solution {
public:
    const int MOD = 1e9 + 7;
    
    int solve(int ind, int order, int n) {
        if (ind == n) {
            return 1;
        }
        int khoroch = n/2 - order;
        int delivery = ind - khoroch;
        delivery = khoroch - delivery;
        int &ret = dp[ind][order];
        if (ret != -1) return ret;
        ret = 0ll;
        if (delivery) {
            ret = (ret + (1ll * delivery*solve(ind + 1, order, n)) % MOD) % MOD;
        }
        if (order) {
            ret = (ret + (1ll * order*solve(ind + 1, order - 1, n)) % MOD) % MOD;
        }
        return ret;
    }
    
    int countOrders(int n) {
        dp.resize(n*2, vector<int>(n + 1, -1ll));
        return solve(0, n, 2*n);
    }
private:
    vector<vector<int>> dp;
};