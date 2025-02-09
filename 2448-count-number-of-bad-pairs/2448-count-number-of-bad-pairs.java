import java.util.Collection;
class Solution {
    public long countBadPairs(int[] nums) {
       int n = nums.length;
       HashMap<Integer, Integer> counter = new HashMap<>();
       for (int i = 0; i < n; i++) {
        int diff = i - nums[i];
        counter.put(diff, counter.getOrDefault(diff, 0) + 1);
       }
       long sum = n;
       long ans = 0;
       Collection<Integer> values = counter.values();
       for (Integer value : values) {
        sum -= value;
        ans += sum * value;
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