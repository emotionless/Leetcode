class Solution {
    int[] dr = new int[]{0, 1, 0, -1};
    int[] dc = new int[]{1, 0, -1, 0};
    
    int dfs(int r, int c, int[][] grid) {
        if (grid[r][c] == 0) return 0;
        int ret = 0;
        ret += grid[r][c];
        grid[r][c] = 0;
        for (int i = 0; i < 4; i++) {
            int ar = r + dr[i];
            int ac = c + dc[i];
            if (ar < 0 || ar >= n || ac < 0 || ac >= m) continue;
            ret += dfs(ar, ac, grid);
        }
        return ret;
    }

    public int findMaxFish(int[][] grid) {
        int ans = 0;
        n = grid.length;
        m = grid[0].length;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                ans = Math.max(ans, dfs(i, j, grid));
            }
        }
        return ans;
    }
    private int n, m;
}