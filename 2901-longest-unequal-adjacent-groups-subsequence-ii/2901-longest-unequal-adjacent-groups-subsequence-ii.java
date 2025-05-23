class Solution {
    int hDistance(String str1, String str2) {
        int cnt = 0;
        if (str2.length() != str1.length()) return 0;
        for (int i = 0; i < str1.length(); i++) {
            if (str1.charAt(i) != str2.charAt(i)) {
                cnt++;
            }
        }
        return cnt;
    }

    int solve(int ind, String[] words, int[] groups, int[] dp, int[] map) {
        int ret = 0;
        if (dp[ind] != -1) return dp[ind];
        dp[ind] = 0;
        for (int i = ind + 1; i < words.length; i++) {
            if (groups[ind] != groups[i] && hDistance(words[i], words[ind]) == 1) {
                int nxt = 1 + solve(i, words, groups, dp, map);
                if (nxt > ret) {
                    ret = nxt;
                    map[ind] = i;
                }
            }
        }
        return dp[ind] = ret;
    }
    public List<String> getWordsInLongestSubsequence(String[] words, int[] groups) {
        int wn = words.length;
        int[] dp = new int[wn];
        int[] map = new int[wn];
        Arrays.fill(dp, -1);
        Arrays.fill(map, -1);
        int mx = -1;
        int start = 0;
        for (int i = 0; i < wn; i++) {
            int now = solve(i, words, groups, dp, map);
            if (now > mx) {
                mx = now;
                start = i;
            }
        }
        List<String> ans = new ArrayList<>();
        ans.add(words[start]);
        
        while (map[start] != -1) {
            start = map[start];
            ans.add(words[start]);
        }
        return ans;
    }
}