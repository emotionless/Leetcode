class Solution {
    public int removeElement(int[] nums, int val) {
        int len = nums.length;
        int i = 0;
        int j = len - 1;
        while (i <= j) {
            if (nums[i] != val) {
                i++;
                continue;
            }
            while (j >= i && nums[j] == val) j--;
            if (i > j) break;
            if (nums[i] == val) {
                int tmp = nums[i];
                nums[i] = nums[j];
                nums[j] = tmp;
            }
        }
        return i;
    }
}