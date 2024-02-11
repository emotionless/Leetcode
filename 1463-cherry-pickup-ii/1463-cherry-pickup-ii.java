class Solution {
    int n, m;
    public int cherryPickup(int[][] grid) {
        n = grid.length;
        m = grid[0].length;
        Integer[][][] dp = new Integer[n][m][m];
        
        return grid[0][0] + grid[0][m-1] + solve(0, 0, m - 1, dp, grid);
    }
    
    public int solve(int row, int col1, int col2, Integer[][][] dp, int[][] grid) {
        if (row == (n - 1)) return 0;
        if (dp[row][col1][col2] == null) {
            int ret = 0;
            for (int i = -1; i < 2; i++) {
                for (int j = -1; j < 2; j++) {
                    int f1 = col1 + i;
                    int f2 = col2 + j;
                    if (f1 < 0 || f1 >= m || f2 < 0 || f2 >= m) continue;
                    if (f1 == f2) {
                        ret = Math.max(ret, grid[row + 1][f1] + solve(row + 1, f1, f2, dp, grid));
                    } else {
                        ret = Math.max(ret, grid[row + 1][f1] + grid[row + 1][f2] + solve(row + 1, f1, f2, dp, grid));
                    }
                }
            }
            dp[row][col1][col2] = ret;
        }
        return dp[row][col1][col2];
    }
}