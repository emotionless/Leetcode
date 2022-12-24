class Solution {
public:
    const int MOD = 1e9 + 7;
    
//     int solve(int ind, int state) {
//         if (ind == N) return state == 0;
//         if (ind > N) return 0;
//         int &ret = dp[ind][state];
//         if (ret != -1) return ret;
//         ret = 0;
//         if (state == 0) {
//             ret = solve(ind + 1, 0);
//             ret = (ret + (2*solve(ind + 1, 1)) % MOD)%MOD;
//         } else {
//             ret = (ret + solve(ind + 1, 1))%MOD;
//         }
//         ret = (ret + solve(ind + 2, 0)) % MOD;
//         return ret;
//     }
            
    int numTilings(int n) {
        dp.resize(3, vector<int>(2, 0));
        N = n;
        dp[N%3][0] = 1;
        for (int i = N - 1; i >= 0; i--) {
            dp[i%3][0] = ((dp[(i+1)%3][0] + dp[(i + 2)%3][0])%MOD + (2*dp[(i + 1)%3][1]) % MOD)%MOD;
            dp[i%3][1] = (dp[(i + 2)%3][0] + dp[(i + 1)%3][1]) % MOD;
        }
        return dp[0][0];
        // return solve(0, 0);
    }
private:
    int N;
    vector<vector<int>> dp;
};