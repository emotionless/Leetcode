class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int i = 0, j = 1;
        int res = 0;
        int n = nums.size();
        int cnt = 0;
        int pre = INT_MIN;
        while (i < n) {
            if (nums[i] == pre) {
                i++;
                continue;
            }
            j = max(j, i + 1);
            while (j < n && (nums[j] - nums[i]) < k) {
                j++;
            }
            if (j < n && (nums[j] - nums[i]) == k) {
                cnt++;
                j++;
            }
            while (j < n && nums[j-1] == nums[j]) j++;
            pre = nums[i];
        }
        return cnt;
    }
};