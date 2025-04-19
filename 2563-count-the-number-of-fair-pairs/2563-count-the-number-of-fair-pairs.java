class Solution {
    int getLessPosition(int[] nums, int val, int limit, boolean is) {
        int st = 0, ed = nums.length - 1;
        int ret = -1;
        while (st <= ed) {
            int mid = (st + ed) / 2;
            if ((val + nums[mid]) < limit) {
                ret = mid;
                st = mid + 1;
            } else if ((val + nums[mid]) == limit) {
                if (is) {
                    ret = mid;
                    ed = mid - 1;
                } else {
                    ret = mid;
                    st = mid + 1;
                }
            } else {
                ed = mid - 1;
            }
        }
        return ret;
    }
    public long countFairPairs(int[] nums, int lower, int upper) {
        Arrays.sort(nums);
        int n = nums.length;
        long ans = 0;
        for (int i = 0; i < n; i++) {
            int st = getLessPosition(nums, nums[i], lower - 1, false) + 1;
            if (st <= i) st = i + 1;

            int ed = getLessPosition(nums, nums[i], upper, false);
            ans += Math.max(0, ed - st + 1);
            // System.out.println(i + " " + st + " " + ed);
        }
        return ans;
    }
}

/**

[0,1,4,4,5,7]

 */