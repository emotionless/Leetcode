class Solution {

    boolean isSorted(int st, int ed, int[] nums) {
        st++;
        while (st < ed) {
            if (nums[st] < nums[st - 1]) return false;
            st++;
        }
        return true;
    }

    public boolean check(int[] nums) {
        int pos = 0;
        int n = nums.length;
        for (int i = 1; i < n; i++) {
            if (nums[i] < nums[i-1]) {
                pos = i;
                break;
            }
        }
        if (pos == 0) return true;
        if (isSorted(0, pos, nums) && isSorted(pos, n, nums) && nums[0] >= nums[n-1]) {
            return true;
        } else {
            return false;
        }
    }
}