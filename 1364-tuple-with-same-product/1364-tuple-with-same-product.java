class Solution {
    public int tupleSameProduct(int[] nums) {
        HashMap<Integer, Integer> counter = new HashMap<>();
        int n = nums.length;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int mul = nums[i] * nums[j];
                ans += counter.getOrDefault(mul, 0) * 8;
                counter.put(mul, counter.getOrDefault(mul, 0) + 1);
            }
        }
        return ans;
    }
}