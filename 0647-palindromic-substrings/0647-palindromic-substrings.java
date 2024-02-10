class Solution {
    
    boolean isPalindrome(int i, int j, String S, Boolean[][] dp) {
        if (i >= j) return true;
        if (dp[i][j] == null) {
            dp[i][j] = false;
            dp[i][j] = S.charAt(i) == S.charAt(j) && isPalindrome(i + 1, j - 1, S, dp);
        }
        return dp[i][j];
    }
    
    public int countSubstrings(String s) {
        int n = s.length();
        int counter = 0;
        Boolean[][] dp = new Boolean[n][n];
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                if (isPalindrome(i, j, s, dp)) {
                    counter++;
                }
            }
        }
        return counter;
    }
}