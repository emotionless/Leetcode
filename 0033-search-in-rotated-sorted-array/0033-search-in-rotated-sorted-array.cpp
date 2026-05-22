class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int st = 0, ed = n - 1, ans = -1;
        while(st <= ed) {
            int mid = (st + ed) / 2;
            if (nums[mid] == target) return mid;
            if (nums[st] <= target && nums[mid] >= target && nums[st] < nums[mid]) {
                ed = mid - 1;
            } else if(nums[st] <= target && nums[mid] <= target && nums[st] > nums[mid]) {
                ed = mid - 1;
            } else if(nums[st] >= target && nums[mid] >= target && nums[st] > nums[mid]) {
                ed = mid - 1;
            } else {
                st = mid + 1;
            }
        }
        return -1;
    }
};