class Solution {
    public long gridGame(int[][] grid) {
        long sum1 = 0;
        int n = grid[0].length;
        for (int i = 0; i < n; i++) {
            sum1 += grid[0][i];
        }
        long sum2 = 0;
        long ans = sum1;
        for (int i = 0; i < n; i++) {
            sum1 -= grid[0][i];
            ans = Math.min(ans, Math.max(sum1, sum2));
            sum2 += grid[1][i];
        }
        return ans;
    }
}