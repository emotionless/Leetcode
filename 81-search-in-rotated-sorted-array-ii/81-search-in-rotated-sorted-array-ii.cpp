class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int st = 0, ed = nums.size() - 1;
        while (st <= ed) {
            int mid = (st + ed) / 2;
            if (nums[st] == target || nums[mid] == target || nums[ed] == target) return true;
            
            if (nums[st] < nums[mid]) {
                if (target >= nums[st] && target <= nums[mid]) {
                    ed = mid - 1;
                } else {
                    st = mid + 1;
                }
            } else if (nums[mid] < nums[ed]) {
                if (target >= nums[mid] && target <= nums[ed]) {
                    st = mid + 1;
                } else {
                    ed = mid - 1;
                }
            } else {
                st++;
                ed--;
            }
        }
        return false;
    }
};