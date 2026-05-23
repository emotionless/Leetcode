class Solution {
    public boolean check(int[] nums) {
        int n = nums.length;
        int count = 0;
        for (int i = 1; i < n; i++) {
            if (nums[i] < nums[i-1]) {
                count++;
            }
        }
        if (nums[n - 1] > nums[0]) {
            count++;
        }
        return count <= 1;
    }
}