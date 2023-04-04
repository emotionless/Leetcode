class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long sum = 0;
        int n = nums.size();
        vector<int> last(100001, -1);
        long long ans = 0;
        int mxPos = -1;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            if ((i-k) >= 0) {
                sum -= nums[i-k];
            }
            mxPos = max(mxPos, last[nums[i]]);
            if ((i - mxPos) >= k) {
                ans = max(ans, sum);
            }
            last[nums[i]] = i;
        }
        return ans;
    }
};