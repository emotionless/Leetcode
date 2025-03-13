import java.util.*;
class Solution {

    boolean doesApplyZero(int[] nums, int[][] queries, int k) {
        int n = nums.length;
        int[] sum = new int[n + 1];
        for (int i = 0; i <= k; i++) {
            int l = queries[i][0];
            int r = queries[i][1];
            sum[l] -= queries[i][2];
            sum[r + 1] += queries[i][2];
        }
        long csum = 0;
        for (int i = 0; i < n; i++) {
            csum += sum[i];
            if (csum + nums[i] > 0) return false; 
        }
        return true;
    }

    public int minZeroArray(int[] nums, int[][] queries) {
        boolean ck = false;
        for (int num : nums) {
            if (num > 0) {
                ck = true;
                break;
            }
        }
        if (ck == false) return 0;
        int st = 0, ed = queries.length - 1;
        int ans = -2;
        while (st <= ed) {
            int mid = (st + ed) / 2;
            if (doesApplyZero(nums, queries, mid)) {
                ans = mid;
                ed = mid - 1;
            } else {
                st = mid + 1;
            }
        }
        return ans + 1;
    }
}