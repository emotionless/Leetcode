class Solution {
public:
    int findMinimumCost(int ind, int pre, vector<int> &nums) {
        if (ind >= n) return nums[pre];
        int &ret = dp[ind][pre];
        if (ret != -1) return ret;
        ret = INF;
        if ((ind + 1) < n) {
            ret = min(ret, max(nums[ind], nums[ind+1]) + findMinimumCost(ind + 2, pre, nums));
            ret = min(ret, max(nums[ind], nums[pre]) + findMinimumCost(ind + 2, ind + 1, nums));
            ret = min(ret, max(nums[pre], nums[ind+1]) + findMinimumCost(ind + 2, ind, nums));
        } else {
            ret = min(ret, max(nums[ind], nums[pre]));
        }
        return ret;
    }

    int minCost(vector<int>& nums) {
        n = nums.size();
        dp.resize(n, vector<int>(n, -1));
        return findMinimumCost(1, 0, nums);
    }
private:
    vector<vector<int>> dp;
    int n;
    const int INF = 1000000000;
};