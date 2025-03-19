class Solution {
    public int minOperations(int[] nums) {
        int cnt = 0;
        int ans = 0;
        int n = nums.length;
        int[] counter = new int[n];
        for (int i = 0; i < n; i++) {
            int d = nums[i];
            cnt = counter[i];
            if (cnt % 2 == 1) {
                d = 1 - d; 
            }
            if (d == 0) {
                if ((i+2) >= n) return -1;
                counter[i+1]++;
                counter[i+2]++;
                ans++;
            }
        }
        return ans;
    }
}