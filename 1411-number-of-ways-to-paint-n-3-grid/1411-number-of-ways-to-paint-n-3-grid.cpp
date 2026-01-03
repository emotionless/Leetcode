class Solution {
public:
    const int MOD = 1e9 + 7;
    // int solve(int index, int fc, int sc, int tc, const int n) {
    //     if (index == n) return 1;
    //     int &ret = dp[index][fc][sc][tc];
    //     if (ret != -1) return ret;
    //     ret = 0;
    //     for (int i = 0; i < 3; i++) {
    //         for (int j = 0; j < 3; j++) {
    //             for (int k = 0; k < 3; k++) {
    //                 if (i != j && j != k && fc != i && sc != j && tc != k) {   
    //                     ret = (ret + solve(index + 1, i, j, k, n)) % MOD;
    //                 }
    //             }
    //         }
    //     }
    //     return ret;
    // }
    
    int numOfWays(int n) {
        int ans = 0;
        vector<int> save;
        dp.resize(2, vector<int>(1<<9, 1));
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                for (int k = 0; k < 3; k++) {
                    if (i != j && j != k) {
                        save.push_back((1<<i) + (1<<(3 + j)) + ((1<<(6 + k))));
                    }
                }
            }
        }
        for (int i = n - 2; i >= 0; i--) {
            for (auto num1 : save) {
                dp[i%2][num1] = 0;
                for (auto num2 : save) {
                    if (!(num1&num2)) {
                        dp[i%2][num1] = (dp[i%2][num1] + dp[(i+1)%2][num2]) % MOD;
                    }
                }
            }
        }
        for (auto num : save) {
            // cout << num << " " << dp[0][num] << endl;
            ans = (ans + dp[0][num]) % MOD;
        }
        return ans;
    }
private:
    vector<vector<int>> dp;
};