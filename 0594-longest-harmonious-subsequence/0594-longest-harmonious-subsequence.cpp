class Solution {
public:
    int findLHS(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (i && nums[i] == nums[i-1]) continue;
            int j = i;
            while (j < n && (nums[j] - nums[i]) <= 1) {
                j++;
            }
            if (nums[j-1] != nums[i])
                ans = max(ans, j - i);
        }
        return ans;
    }
};