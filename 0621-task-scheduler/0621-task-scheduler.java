class Solution {
    public int leastInterval(char[] tasks, int n) {
        HashMap<Character, Integer> count = new HashMap<>();
        int mx = 0;
        for (int i = 0; i < tasks.length; i++) {
            count.put(tasks[i], count.getOrDefault(tasks[i], 0) + 1);
            mx = Math.max(mx, count.get(tasks[i]));
        }
        int tot = 0;
        for (char ch = 'A'; ch <= 'Z'; ch++) {
            if (count.getOrDefault(ch, 0) == mx) {
                tot++;
            }
        }
        return Math.max(tasks.length, tot + (mx - 1) * (n + 1));
    }
}