class Solution {
    int XORSum(int mask, int[] nums) {
        int sum = 0;
        for (int i = 0; i < 12; i++) {
            if ((mask&(1<<i)) > 0) {
                sum ^= nums[i];
            }
        }
        return sum;
    }
    public int subsetXORSum(int[] nums) {
        int n = nums.length;
        int total = 0;
        for (int i = 0; i < (1<<n); i++) {
            total += XORSum(i, nums);
        }
        return total;
    }
}