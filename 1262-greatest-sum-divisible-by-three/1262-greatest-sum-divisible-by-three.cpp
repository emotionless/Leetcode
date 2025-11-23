class Solution {
public:
    
    int solve(int ind, int sum, const vector<int> &nums) {
        if (ind == (nums.size())) {
            if (sum % 3 == 0) return 0;
            return INT_MIN;
        }
        int &ret = dp[ind][sum];
        if (ret != -1) return ret;
        ret = 0;
        ret = solve(ind + 1, sum, nums);
        ret = max(ret, nums[ind] + solve(ind + 1, (sum + nums[ind]) % 3, nums));
        return ret;
    }
    
    int maxSumDivThree(vector<int>& nums) {
        int n = nums.size();
        dp.resize(n, vector<int>(3, -1));
        return solve(0, 0, nums);
    }
private:
    vector<vector<int>> dp;
};