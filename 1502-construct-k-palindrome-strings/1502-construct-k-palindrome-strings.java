class Solution {
    public boolean canConstruct(String s, int k) {
        int len = s.length();
        if (k > len) return false;
        int[] counter = new int[26];
        for (int i = 0; i < len; i++) {
            char ch = s.charAt(i);
            counter[ch - 'a']++;
        }
        int odd = 0;
        for (int i = 0; i < 26; i++) {
            if (counter[i] % 2 == 1) {
                odd++;
            }
        }
        return odd <= k;
    }
}