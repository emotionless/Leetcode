class Solution {
    void swap(int[] nums, int f, int s) {
        int num = nums[f];
        nums[f] = nums[s];
        nums[s] = num;
    }
    public void sortColors(int[] nums) {
        int zeroInd = 0;
        int ind = 0;
        int twoInd = nums.length - 1;
        while (ind <= twoInd) {
            if (nums[ind] == 0) {
                swap(nums, zeroInd, ind);
                ind++;
                zeroInd++;
            } else if (nums[ind] == 2) {
                swap(nums, ind, twoInd);
                twoInd--;
            } else {
                ind++;
            }
        }
    }
}