class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size();
        long long preSum = 0;
        for (auto x : nums) {
            preSum += x;
        }
        long long pre = 0;
        for (int i = 0; i < n; i++) pre += i*nums[i];
        long long post = 0;
        long long postSum = 0;
        long long ans = INT_MIN;
        for (int i = n - 1; i >= 0; i--) {
            pre += (preSum - 1.0*n*nums[i]);
            preSum -= nums[i];
            post += postSum;
            postSum += nums[i];
            ans = max(ans, pre + post);
        }
        return ans;
    }
};