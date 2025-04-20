class Solution {

    int decrement(HashMap<Integer, Integer> rabbits, int col) {
        if (!rabbits.containsKey(col) || rabbits.get(col) == 0) {
            rabbits.put(col, col);
            return col;
        }
        rabbits.put(col, rabbits.get(col) - 1);
        return rabbits.get(col);
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