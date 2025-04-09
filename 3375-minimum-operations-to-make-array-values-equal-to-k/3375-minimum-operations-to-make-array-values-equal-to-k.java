class Solution {
    public int minOperations(int[] nums, int k) {
        boolean[] vis = new boolean[101];
        int  ans = 0;
        for (int num : nums) {
            if (num < k) return -1;
            else if (num == k) continue;
            if (vis[num] == false) {
                ans++;
            }
            vis[num] = true;
        }
        return ans;
    }
}