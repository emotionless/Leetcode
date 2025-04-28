class Solution {
    public long countSubarrays(int[] nums, long k) {
        int n = nums.length;
        int j = 0;
        long sum = 0;
        long ans = 0;
        for (int i = 0; i < n; i++){
            while (j < n && (sum + nums[j])*(j-i+1L) < k) {
                sum += nums[j];
                j++;
            }
            ans += j - i;
            sum -= nums[i];
        }
        return ans;
    }
}