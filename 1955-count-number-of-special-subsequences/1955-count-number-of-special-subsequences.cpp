class Solution {
public:
    const int MOD = 1e9 + 7;
    
    int solve(int ind, int pre, vector<int> &nums) {
        if (ind == nums.size()) {
            return pre == 3;
        }
        int &ret = dp[ind][pre];
        if (ret != -1) return ret;
        ret = 0;
        ret = solve(ind + 1, pre, nums);
        if (nums[ind] == pre || nums[ind] == (pre + 1)) {
            ret = (ret + solve(ind + 1, nums[ind], nums)) % MOD;
        }
        return ret;
    }
    
    int countSpecialSubsequences(vector<int>& nums) {
        // for (auto &v : nums) {
        //     v++;
        // }
        int n = nums.size();
        dp.resize(2, vector<int>(3, 0));
        // return solve(0, 0, nums);
        
        for (int i = n - 1; i >= 0; i--) {
            int val = nums[i];
            int cur = i%2;
            int next = (i+1)%2;
            if (val == 2) {
                dp[cur][val] = (1 + (dp[next][val] + dp[next][val])%MOD)%MOD;
                dp[cur][0] = dp[next][0];
                dp[cur][1] = dp[next][1];
            } else {
                dp[cur][0] = dp[next][0];
                dp[cur][1] = dp[next][1];
                dp[cur][2] = dp[next][2];
                
                dp[cur][val] = ((dp[next][val] + dp[next][val])%MOD + dp[next][val + 1]) % MOD;
            }
            
            // cout << i << " have: " << dp[i][0] << " " << dp[i][1] << " " << dp[i][2] << endl;
        }
        return dp[0][0];
    }
private:
    vector<vector<int>> dp;
};