class Solution {
    int getMinPos(int[] nums, int st, int ed, int target) {
        int ans = -1;
        while (st <= ed) {
            int mid = (st + ed) / 2;
            if (nums[mid] == target) return mid;
            else if (nums[mid] < target) {
                st = mid + 1;
            } else {
                ed = mid - 1;
            }
        }
        return ans;
    }
    public int search(int[] nums, int target) {
        return getMinPos(nums, 0, nums.length - 1, target);
    }
}