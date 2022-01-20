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
        for (auto &v : nums) {
            v++;
        }
        int n = nums.size();
        dp.resize(n, vector<int>(4, -1));
        return solve(0, 0, nums);
    }
private:
    vector<vector<int>> dp;
};