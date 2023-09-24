class Solution {
    public int countPairs(List<List<Integer>> coordinates, int k) {
        Map<Integer, Map<Integer, Integer>> count = new HashMap<>();
        int ans = 0;
        for (List<Integer> coordinate : coordinates) {
            int x = coordinate.get(0);
            int y = coordinate.get(1);
            for (int i = 0; i <= k; i++) {
                int x1 = x^i;
                int y1 = y^(k - i);
                if (count.containsKey(x1) && count.get(x1).containsKey(y1)) {
                    ans += count.get(x1).get(y1);
                }
            }
            count.computeIfAbsent(x, x1 -> new HashMap<>()).put(y, count.get(x).getOrDefault(y, 0) + 1);
        }
        return ans;
    }
}