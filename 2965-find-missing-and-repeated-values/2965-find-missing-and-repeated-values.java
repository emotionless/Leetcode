class Solution {
    public int[] findMissingAndRepeatedValues(int[][] grid) {
        HashMap<Integer, Integer> counter = new HashMap<>();
        int n = grid.length;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                counter.put(grid[i][j], counter.getOrDefault(grid[i][j], 0) + 1);
            }
        }
        int[] ans = new int[2];
        for (int i = 1; i <= n*n; i++) {
            if (counter.getOrDefault(i, 0) == 2) {
                ans[0] = i;
            } else if (counter.getOrDefault(i, 0) == 0) {
                ans[1] = i;
            }
        }
        return ans;
    }
}