class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int n = nums.size();
        int j = 0;
        int ans = 0;
        for (int i = 1; i < n - 1; i++){
            j = max(j, i + 1);
            while (j < n && nums[j] == nums[i]) {
                j++;
            }
            if (nums[i] != nums[i-1] && j < n) {
                if (min(nums[i-1] , nums[j]) > nums[i] || max(nums[i-1] , nums[j]) < nums[i]) {
                    ans += 1;
                }
            }
        }
        return ans;
    }
};