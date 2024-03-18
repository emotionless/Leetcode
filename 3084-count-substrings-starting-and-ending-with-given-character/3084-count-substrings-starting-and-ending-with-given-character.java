class Solution {
    public long countSubstrings(String s, char c) {
        long cnt = 0;
        for (int i = 0; i < s.length(); i++) {
            char ch = s.charAt(i);
            if (c == ch) {
                cnt++;
            }
        }
        return (cnt * (cnt + 1) ) / 2;
    }
}