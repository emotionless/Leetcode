class Solution {

    int decrement(HashMap<Integer, Integer> rabbits, int col) {
        if (!rabbits.containsKey(col) || rabbits.get(col) == 0) {
            rabbits.put(col, col);
            return col;
        }
        int cur = rabbits.get(col);
        cur--;
        rabbits.put(col, cur);
        return cur;
    }

    public int numRabbits(int[] answers) {
        HashMap<Integer, Integer> rabbits = new HashMap<>();
        int ans = 0;
        for (int rab : answers) {
            if (decrement(rabbits, rab) == rab) {
                ans += rab + 1;
            }
        }
        return ans;
    }
}