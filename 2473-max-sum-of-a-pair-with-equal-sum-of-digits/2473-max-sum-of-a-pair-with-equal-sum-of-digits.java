class Solution {
    int sod(int num) {
        int sum = 0;
        int cur = num;
        while (cur > 0) {
            sum += cur % 10;
            cur /= 10;
        }
        return sum;
    }
    public int maximumSum(int[] nums) {
        int n = nums.length;
        int[] visited = new int[100];
        int ans = -1;
        for (int i = n - 1; i >= 0; i--) {
            int sum = sod(nums[i]);
            if (visited[sum] != 0) {
                ans = Math.max(ans, visited[sum] + nums[i]);
            }
            visited[sum] = Math.max(visited[sum], nums[i]);
        }
        return ans;
    }
}