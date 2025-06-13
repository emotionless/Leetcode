class Solution {
public:
    int minDifference(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        if (n <= 4) return 0;
        int ans = INT_MAX;
        for (int i = 0; i < 4; i++) {
            ans = min(ans, nums[n-4+i] - nums[i]);
        }
        return ans;
    }
};