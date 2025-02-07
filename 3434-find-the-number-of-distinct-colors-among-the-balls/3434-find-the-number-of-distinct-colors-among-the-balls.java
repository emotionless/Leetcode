class Solution {
    public int[] queryResults(int limit, int[][] queries) {
        HashMap<Integer, Integer> color = new HashMap<>();
        HashMap<Integer, Integer> counter = new HashMap<>();
        int ans = 0;
        int[] result = new int[queries.length];
        int ind = 0;
        for (int[] query : queries) {
            int num = query[0];
            int col = query[1];
            int cur = color.getOrDefault(num, 0);
            // System.out.println(ind + " " + cur);
            color.put(num, col);
            counter.put(col, counter.getOrDefault(col, 0) + 1);
            if (counter.get(col) == 1) {
                ans++;
            }
            if (cur != 0) {
                counter.put(cur, counter.getOrDefault(cur, 0) - 1);
                if (counter.get(cur) == 0) {
                    ans--;
                }
            }
            result[ind++] = ans;
        }
        return result;
    }
}