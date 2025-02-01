class Solution {
    int countParity(int a, int b) {
        if (a%2 == b%2) return 0;
        return 1;
    }
    public boolean[] isArraySpecial(int[] nums, int[][] queries) {
        int n = nums.length;
        int[] sum = new int[n];
        sum[0] = 0;
        for (int i = 1; i < n; i++) {
            sum[i] = sum[i - 1] + countParity(nums[i - 1], nums[i]);
        }
        boolean[] ans = new boolean[queries.length];
        int i = 0;
        for (int[] query : queries) {
            int l = query[0];
            int r = query[1];
            if (l == r) {
                ans[i] = true;
            } else {
                ans[i] = (sum[r] - sum[l]) == (r - l)? true : false;
            }
            i++;
        }
        return ans;
    }
}