class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int st = 0, ed = n - 1;
        int ans = 0;
        if (n == 1) return nums[0];
        while (st <= ed) {
            int mid = (st + ed) / 2;
            int cnt = 0;
            if (nums[mid] == nums[mid^1]) {
                st = mid + 1;
            } else {
                ed = mid - 1;
                ans = mid;
            }
        }
        return nums[ans];
    }
};