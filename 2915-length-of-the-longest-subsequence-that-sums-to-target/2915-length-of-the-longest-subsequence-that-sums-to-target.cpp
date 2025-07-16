class Solution {
public:
    int solve(int ind, vector<int> &nums, int rem) {
        if (rem == 0) return 0;
        if (ind >= nums.size()) {
            return -100000;
        }
        int &ret = dp[ind][rem];
        if (ret != -1) return ret;
        ret = 0;
        ret = solve(ind + 1, nums, rem);
        if (nums[ind] <= rem) {
            ret = max(ret, 1 + solve(ind + 1, nums, rem - nums[ind]));
        }
        return ret;
    }
    int lengthOfLongestSubsequence(vector<int>& nums, int target) {
        int n = nums.size();
        dp.resize(n, vector<int>(target + 1, -1));
        return max(-1, solve(0, nums, target));
    }
private:
    vector<vector<int>> dp;
};