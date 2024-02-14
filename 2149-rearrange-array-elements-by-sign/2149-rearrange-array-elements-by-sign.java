class Solution {
    public int[] rearrangeArray(int[] nums) {
        int n = nums.length;
        int[] even = new int[n/2];
        int[] odd = new int[n/2];
        
        int o = 0, e = 0;
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] >= 0) even[e++] = nums[i];
            else odd[o++] = nums[i];
        }
        for (int i = 0; i <n; i++) {
            if (i%2 == 0) {
                nums[i] = even[i/2];
            }
            else nums[i] = odd[i/2];
            
        }
        return nums;
    }
}