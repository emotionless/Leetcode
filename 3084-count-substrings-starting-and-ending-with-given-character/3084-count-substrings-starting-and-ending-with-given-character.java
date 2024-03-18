class Solution {
    public long countSubstrings(String s, char c) {
        long cnt = 0;
        for (char ch : s.toCharArray()) {
            if (c == ch) {
                cnt++;
            }
        }
        return (cnt * (cnt + 1) ) / 2;
    }
}