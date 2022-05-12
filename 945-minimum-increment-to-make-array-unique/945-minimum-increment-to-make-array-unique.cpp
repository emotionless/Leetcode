class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int pre = -1;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] > pre) {
                pre = nums[i];
                continue;
            }
            ans += pre - nums[i] + 1;
            pre = pre + 1;
        }
        return ans;
    }
};