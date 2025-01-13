class Solution {
    public int minimumLength(String s) {
        int[] counter = new int[26];
        int len = s.length();
        for (int i = 0; i < len; i++) {
            int id = s.charAt(i) - 'a';
            counter[id]++;
            if (counter[id] == 3) {
                counter[id] = 1;
            }
        }
        int ans = 0;
        for (int i = 0; i < 26; i++) ans += counter[i];

        return ans;
    }
}