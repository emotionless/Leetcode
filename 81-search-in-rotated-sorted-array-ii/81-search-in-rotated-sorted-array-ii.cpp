class Solution {
public:
    
    bool search(vector<int> &nums, int st, int ed, int target) {
        if (st == ed) {
            return target == nums[st];
        } else if (st > ed) return false;
        
        int mid = (st + ed) / 2;
        if (nums[mid] == target) return true;
        if (nums[st] == target) return true;
        
        if (nums[st] == nums[ed]) {
            return search(nums, st + 1, ed - 1, target);
        } else if (nums[mid] <= nums[ed]) {
            if (target >= nums[mid] && target <= nums[ed]) {
                return search(nums, mid + 1, ed, target);
            } else {
                return search(nums, st, mid - 1, target);
            }
        } else {
            if (target >= nums[st] && target <= nums[mid]) {
                return search(nums, st, mid - 1, target);
            } else {
                return search(nums, mid + 1, ed, target);
            }
        }
    }
    
    bool search(vector<int>& nums, int target) {
        return search(nums, 0, nums.size() - 1, target);
    }
};