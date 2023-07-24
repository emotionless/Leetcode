class Solution {
public:
    long long maxArrayValue(vector<int>& nums) {
        int n = nums.size();
        long long ans = nums[n-1];
        for (int i = nums.size() - 2; i >= 0; i--) {
            if (nums[i] <= ans) {
                ans += nums[i];
            } else {
                ans = nums[i];
            }
        }
        return ans;
    }
};