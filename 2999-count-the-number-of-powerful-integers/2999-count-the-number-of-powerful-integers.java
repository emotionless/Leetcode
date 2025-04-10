class Solution {

    long solve(int ind, int rem, boolean is, String tar, String s) {
        if (rem <= 0) {
            if (is == true) return 1L;
            else {
                return last;
            }
        }
        long ret = 0;
        int value = 0;
        if (is == true) value = 1;
        if (dp[ind][value] != -1L) return dp[ind][value];
        dp[ind][value] = 0L;

        for (int i = 0; i <= mx; i++) {
            // System.out.println(tar + " " + ind);
            if (i < (int)(tar.charAt(ind) - '0') || is == true) {
                ret += solve(ind + 1, rem - 1, true, tar, s);
            } else if (i == (int)(tar.charAt(ind) - '0')) {
                ret += solve(ind + 1, rem - 1, false, tar, s);
            }
        }
        return dp[ind][value] = ret;
    }

    long getLast(String a, String b) {
        if (a.length() < b.length()) return 0L;
        String last = a.substring(a.length() - b.length());

        return Long.valueOf(b) <= Long.valueOf(last)? 1L : 0L;
    }

    public long numberOfPowerfulInt(long start, long finish, int limit, String s) {
        mx  = limit;
        last = getLast(String.valueOf(finish), s);
        for (int i = 0; i < dp.length; i++) {
            for (int j = 0; j < dp[i].length; j++) {
                dp[i][j] = -1L;
            }
        }

        long first = solve(0, String.valueOf(finish).length() - s.length(), false, String.valueOf(finish), s);
        last = getLast(String.valueOf(start - 1), s);
        for (int i = 0; i < dp.length; i++) {
            for (int j = 0; j < dp[i].length; j++) {
                dp[i][j] = -1L;
            }
        }
        long second = solve(0, String.valueOf(start - 1).length() - s.length(), false, String.valueOf(start - 1), s);
        return first - second;
    }

    long last = 0;
    int mx = 0;
    long[][] dp = new long[16][2];
}