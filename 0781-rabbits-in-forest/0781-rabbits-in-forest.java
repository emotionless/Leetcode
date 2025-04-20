class Solution {

    boolean decrement(HashMap<Integer, Integer> rabbits, int col) {
        if (!rabbits.containsKey(col) || rabbits.get(col) == 0) {
            rabbits.put(col, col);
            return true;
        }
        rabbits.put(col, rabbits.get(col) - 1);
        return false;
    }

    public int numRabbits(int[] answers) {
        HashMap<Integer, Integer> rabbits = new HashMap<>();
        int ans = 0;
        for (int rab : answers) {
            if (decrement(rabbits, rab)) {
                ans += rab + 1;
            }
        }
        return ans;
    }
}