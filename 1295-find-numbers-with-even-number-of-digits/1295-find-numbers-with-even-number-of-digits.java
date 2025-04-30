class Solution {
    public int findNumbers(int[] nums) {
        int ans = 0;
        for (int num : nums) {
            if (num >= 1000 && num < 10000) {
                ans++;
            } else if (num < 100 && num >= 10) {
                ans++;
            } else if (num == 100000) {
                ans++;
            }
        }
        return ans;
    }
}