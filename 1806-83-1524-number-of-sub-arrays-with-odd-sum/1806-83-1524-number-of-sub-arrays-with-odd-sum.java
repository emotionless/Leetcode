class Solution {
    public int numOfSubarrays(int[] arr) {
        int odd = 0, even = 1;
        int sum = 0;
        int ans = 0;
        int MOD = 1000000007;
        for (int num : arr) {
            sum += num;
            sum %= 2;
            if (sum == 0) {
                even++;
                ans += odd;
                ans %= MOD;
            }
            else {
                odd++;
                ans += even;
                ans %= MOD;
            }
        }
        return ans;
    }
}