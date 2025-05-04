class Solution {
    public int numEquivDominoPairs(int[][] dominoes) {
        HashMap<Pair<Integer, Integer>, Integer> count = new HashMap<>();
        int ans = 0;
        for (int[] domino : dominoes) {
            int a = Math.min(domino[0], domino[1]);
            int b = Math.max(domino[0], domino[1]);
            Pair<Integer, Integer> p = new Pair(a, b);
            int cnt = count.getOrDefault(p, 0);
            ans += cnt;
            count.put(p, cnt + 1);
        }
        return ans;
    }
}