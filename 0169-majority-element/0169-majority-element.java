class Solution {
    public int majorityElement(int[] nums) {
        int n = nums.length;
        int cnt = 0;
        int num = -1;
        for (int i = 0; i < nums.length; i++) {
            if (cnt == 0) {
                cnt = 1;
                num = nums[i];
            } else {
                if (num == nums[i]) cnt++;
                else {
                    cnt--;
                }
            }
        }
        return num;
    }
}