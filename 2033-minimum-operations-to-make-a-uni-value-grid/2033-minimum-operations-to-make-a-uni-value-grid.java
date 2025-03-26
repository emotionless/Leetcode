class Solution {
    public int minOperations(int[][] grid, int x) {
        int n = grid.length;
        int m = grid[0].length;
        int[] nums = new int[n*m];
        int ind = 0;
        for (int[] array : grid) {
            for (int i = 0; i < m; i++) {
                nums[ind++] = array[i];
            }
        }
        Arrays.sort(nums);
        int mid = (ind/2);
        int ans = 0;
        for (int num : nums) {
            int diff = Math.abs(num - nums[mid]);
            ans += diff/x;
            if (diff%x != 0) return -1;
        }
        return ans;
    }
}