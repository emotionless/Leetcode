class Solution {
    public int countCompleteSubarrays(int[] nums) {
        HashSet<Integer> total = new HashSet<>();
        HashSet<Integer> seen = new HashSet<>();
        int n = nums.length;
        int ans = 0;
        for (int num : nums) {
            total.add(num);
        }
        for (int i = 0; i < n; i++) {
            // clean up
            seen.clear();
            for (int j = i; j < n; j++) {
                seen.add(nums[j]);
                if (seen.size() == total.size()) {
                    ans += n - j;
                    // System.out.println(i + " " + j);
                    break;
                }
            }
        }
        return ans;
    }
}