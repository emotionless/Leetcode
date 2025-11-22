class Solution {
    public int minimumOperations(int[] nums) {
        int sum = 0;
        for (int i = 0; i < nums.length; i++) {
            sum += Math.min(1, nums[i]%3);
        }
        return sum;
    }
}