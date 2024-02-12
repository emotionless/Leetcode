class Solution {
    public int longestSubsequence(String s, int k) {
        int len = s.length();
        int cnt = 0;
        int sum = 0;
        for (int i = len - 1; i >= 0; i--) {
            if (s.charAt(i) == '0') {
                cnt++;
                continue;
            }
            if ((len - i - 1) <= 30) {
                if ((sum + (1<<(len-i-1))) <= k) {
                    cnt++;
                    sum += (1<<(len-i-1));
                }
            }
        }
        return cnt;
    }
}

/*
001010101011010100010101101010010
93951055

*/