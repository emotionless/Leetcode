class Solution {
    public int maxAscendingSum(int[] nums) {
        int sum = 0;
        int ans = 0;
        int pre = 0;
        for (int num : nums) {
            if (num > pre) {
                sum += num;
            } else {
                sum = num;
            }
            ans = Math.max(ans, sum);
            pre = num;
        }
        return ans;
    }
}