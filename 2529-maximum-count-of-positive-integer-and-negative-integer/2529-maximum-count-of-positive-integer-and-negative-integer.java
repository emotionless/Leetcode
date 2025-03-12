class Solution {
    int getMinPos(int[] nums, int st, int ed) {
        int ans = ed + 1;
        while (st <= ed) {
            int mid = (st + ed) / 2;
            if (nums[mid] <= 0) {
                st = mid + 1;
            } else {
                ans = mid;
                ed = mid - 1;
            }
        }
        return ans;
    }
    int getMaxNeg(int[] nums, int st, int ed) {
        int ans = -1;
        while (st <= ed) {
            int mid = (st + ed) / 2;
            if (nums[mid] >= 0) {
                ed = mid - 1;
            } else {
                ans = mid;
                st = mid + 1;
            }
        }
        return ans;
    }


    public int maximumCount(int[] nums) {
        int n = nums.length;
        int mx = getMinPos(nums, 0, n - 1);
        int mn = getMaxNeg(nums, 0, n - 1);
        return Math.max(mn + 1, n - mx);
    }
}