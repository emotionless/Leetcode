class Solution {
    int getMinPos(int[] nums, int st, int ed) {
        int ans = ed + 1;
        while (st <= ed) {
            int mid = (st + ed) / 2;
            if (nums[mid] < 0) {
                ed = mid - 1;
                ans = mid;
            } else {
                st = mid + 1;
            }
        }
        return ans;
    }

    public int countNegatives(int[][] grid) {
        int ans = 0;
        int m = grid[0].length;
        for (int[] mat : grid) {
            ans += (m - getMinPos(mat, 0, m-1));
        }
        return ans;
    }
}
/**

[4,3,2,-1],
[3,2,1,-1],
[1,1,-1,-2],
[-1,-1,-2,-3]]

 */