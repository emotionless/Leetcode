class Solution {
    public long countBadPairs(int[] nums) {
       int n = nums.length;
       HashMap<Integer, Integer> counter = new HashMap<>();
       for (int i = 0; i < n; i++) {
        int diff = i - nums[i];
        counter.put(diff, counter.getOrDefault(diff, 0) + 1);
       }
       long sum = 0;
       for (Map.Entry<Integer, Integer> entry : counter.entrySet()) {
        sum += entry.getValue();
       }
       long ans = 0;
       for (Map.Entry<Integer, Integer> entry : counter.entrySet()) {
        sum -= entry.getValue();
        ans += sum * entry.getValue();
       }
       return ans;
    }

/**
-4
0
1
0

3 + 1*2
 */
}