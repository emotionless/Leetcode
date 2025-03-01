class Solution {

    void retrieve(int i, int j, String str1, String str2, StringBuilder sb, int[][] dp) {
        if (i <= 0 || j <= 0) return;
        if (str1.charAt(i - 1) == str2.charAt(j-1)) {
            sb.append(str1.charAt(i-1));
            retrieve(i - 1, j - 1, str1, str2, sb, dp);
        } else if (dp[i][j] == dp[i-1][j]) {
            retrieve(i-1, j, str1, str2, sb, dp);
        } else {
            retrieve(i, j - 1, str1, str2, sb, dp);
        }
    }

    public String shortestCommonSupersequence(String str1, String str2) {
        int len1 = str1.length();
        int len2 = str2.length();
        int[][] dp = new int[len1 + 1][len2 + 1];

        for (int i = 1; i <= len1; i++) {
            for (int j = 1; j <= len2; j++) {
                if (str1.charAt(i - 1) == str2.charAt(j - 1)) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                else {
                    dp[i][j] = Math.max(dp[i - 1][j],
                                        dp[i][j - 1]);
                }
            }
        }

        // System.out.println(dp[len1][len2]);
        StringBuilder sb = new StringBuilder();
        retrieve(len1, len2, str1, str2, sb, dp);
        String cur = sb.reverse().toString();
        int i = 0, j = 0;
        int k = 0;
        // System.out.println(cur);
        StringBuilder ans = new StringBuilder();
        while (i < len1 || j < len2) {
            if (i >= len1) {
                ans.append(str2.charAt(j));
                j++;
            } else if (j >= len2) {
                ans.append(str1.charAt(i));
                i++;
            } else {
                while (k < cur.length() && cur.charAt(k) != str1.charAt(i)) {
                    ans.append(str1.charAt(i));
                    i++;
                }
                while (k < cur.length() && cur.charAt(k) != str2.charAt(j)) {
                    ans.append(str2.charAt(j));
                    j++;
                }
                if (k < cur.length()) {
                    ans.append(cur.charAt(k));
                    k++;
                    i++;
                    j++;
                } else {
                    ans.append(str1.charAt(i));
                    ans.append(str2.charAt(j));
                    i++;
                    j++;
                }
            }
            // System.out.println(i + ", " + j);
        }
        return ans.toString();
    }
}

/**
b
bbabaaaba

 */