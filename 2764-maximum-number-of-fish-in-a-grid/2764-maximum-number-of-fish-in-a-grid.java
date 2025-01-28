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
            if (ar < 0 || ar >= grid.length || ac < 0 || ac >= grid[0].length) continue;
            ret += dfs(ar, ac, grid);
        }
        return ret;
    }

    public int findMaxFish(int[][] grid) {
        int ans = 0;
        for (int i = 0; i < grid.length; i++) {
            for (int j = 0; j < grid[i].length; j++) {
                ans = Math.max(ans, dfs(i, j, grid));
            }
        }
        return ans;
    }
}