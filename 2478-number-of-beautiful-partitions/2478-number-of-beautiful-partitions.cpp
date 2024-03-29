class Solution {
public:
    const int MOD = 1e9 + 7;
    inline bool isPrime(char &ch) {
        return ch == '2' || ch == '3' || ch == '5' || ch == '7';
    }
    
    int solve(int ind, int k, string &str, bool is) {
        if (ind == n) {
            return k == 0;
        }
        if (ind >= n || k == 0 || (!isPrime(str[ind]) && is)) return 0;
        int &ret = dp[ind][k][is];
        if (ret != -1) return ret;
        ret = 0;
        if (isPrime(str[ind])) {
            if (is) ret = solve(ind + minLength - 1, k, str, false);
            else ret = solve(ind + 1, k, str, false);
        } else {
            ret = (solve(ind + 1, k - 1, str, true) + solve(ind + 1, k, str, false)) % MOD;
        }
        return ret;
    }
    
    int beautifulPartitions(string s, int k, int ml) {
        n = s.size();
        dp.resize(n, vector<vector<int>>(k + 1, vector<int>(2, -1)));
        minLength = ml;
        
        return solve(0, k, s, true);
    }
private:
    int n, minLength;
    vector<vector<vector<int>>> dp;
};