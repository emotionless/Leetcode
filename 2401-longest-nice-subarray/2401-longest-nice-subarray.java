class Solution {
    int getMaxLength(int[] nums, int ind) {
        int n = nums.length;
        List<Integer> counted = new ArrayList<>();
        counted.add(nums[ind]);
        int ans = 1;
        for (int i = ind + 1; i < n; i++) {
            int sz = counted.size();
            for (int j = 0; j < sz; j++) {
                if ((counted.get(j)&nums[i]) > 0) {
                    return ans;
                }
            }
            counted.add(nums[i]);
            ans++;
        }
        return ans;
    }
    public int longestNiceSubarray(int[] nums) {
        int ans = 0;
        for (int i = 0; i < nums.length; i++) {
            ans = Math.max(ans, getMaxLength(nums, i));
        }
        return ans;
    }
}

/**
   11
  100
11000
 */