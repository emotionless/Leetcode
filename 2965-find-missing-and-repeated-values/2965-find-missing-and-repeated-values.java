class Solution {
    public int[] findMissingAndRepeatedValues(int[][] grid) {
        int n = grid.length;
        int[] counter = new int[n*n + 1];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                counter[grid[i][j]]++;
            }
        }
        int[] ans = new int[2];
        for (int i = 1; i <= n*n; i++) {
            if (counter[i] == 2) {
                ans[0] = i;
            } else if (counter[i] == 0) {
                ans[1] = i;
            }
        }
        return ans;
    }
}