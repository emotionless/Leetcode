class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        long long postSum = accumulate(nums.begin(), nums.end(), 0);
        long long preSum = 0;
        long long ans = LLONG_MAX;
        for (int i = 0; i < n; i++) {
            postSum -= nums[i];
            ans = min(ans, 1ll*i*nums[i] - preSum + postSum - 1ll*nums[i]*(n - i - 1));
            preSum += nums[i];
        }
        return ans;
    }
};