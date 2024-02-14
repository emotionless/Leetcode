class Solution {
    public int[] rearrangeArray(int[] nums) {
        int n = nums.length;
        int[] ans = new int[n];
        
        int posInd = 0, negInd = 1;
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] >= 0) {
                ans[posInd] = nums[i];
                posInd += 2;
            }
            else {
                ans[negInd] = nums[i];
                negInd += 2;
            }
        }
        return ans;
    }
}