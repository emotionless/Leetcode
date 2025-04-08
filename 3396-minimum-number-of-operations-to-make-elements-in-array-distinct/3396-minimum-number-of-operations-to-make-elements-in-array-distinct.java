class Solution {
    public int minimumOperations(int[] nums) {
        HashSet<Integer> seen = new HashSet<>();
        for (int i = nums.length - 1; i >= 0; i--) {
            if (seen.contains(nums[i])) {
                return (i+3)/3;
            }
            seen.add(nums[i]);
        }
        return 0;
    }
}