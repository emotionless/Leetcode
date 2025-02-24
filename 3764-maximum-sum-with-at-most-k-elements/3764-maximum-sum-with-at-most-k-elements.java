class Solution {
    public long maxSum(int[][] grid, int[] limits, int k) {
        int n = grid.length;
        int m = grid[0].length;
        PriorityQueue<Integer> pq = new PriorityQueue<>(Comparator.comparingInt(t -> -t));
        for (int i = 0; i < n; i++) {
            Arrays.sort(grid[i]);
            for (int j = m - 1; j >= (m - limits[i]); j--) {
                pq.add(grid[i][j]);
            }
        }
        long ans = 0;
        while (k > 0) {
            k--;
            ans += pq.poll();
        }
        return ans;
    }
}