class Solution {

    void increament (HashMap<Integer, Integer> map, int val) {
        int next = map.getOrDefault(val, 0) + 1;
        map.put(val, next);
    }
    void decreament (HashMap<Integer, Integer> map, int val) {
        int next = map.getOrDefault(val, 0) - 1;
        map.put(val, next);
    }

    long calculate (HashMap<Integer, Integer> map, int val) {
        int count = map.getOrDefault(val, 0);
        return (long) (count * (count - 1L)) / 2L;
    }

    public long countGood(int[] nums, int k) {
        int n = nums.length;
        int j = 0;
        long sum = 0, ans = 0;
        HashMap<Integer, Integer> map = new HashMap<>();
        for (int i = 0; i < n; i++) {
            while (j < n && sum < k) {
                sum -= calculate(map, nums[j]);
                increament(map, nums[j]);
                sum += calculate(map, nums[j]);
                // System.out.println(i + " " + j + " " + sum);
                j++;
                if (sum >= k) break;
            }
            // System.out.println(i + " " + j + " " + sum);
            if (sum < k) break;
            ans += (n - j + 1);
            sum -= calculate(map, nums[i]);
            decreament(map, nums[i]);
            sum += calculate(map, nums[i]);
        }
        return ans;
    }
}