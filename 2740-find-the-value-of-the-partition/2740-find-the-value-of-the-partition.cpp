class Solution {
public:
    int findValueOfPartition(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int mn = INT_MAX;
        for (int i = 1; i < nums.size(); i++) {
            mn = min(mn, nums[i] - nums[i - 1]);
        }
        return mn;
    }
};