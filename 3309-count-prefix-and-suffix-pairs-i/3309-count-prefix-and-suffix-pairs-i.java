class Solution {

    boolean prefixAndSuffix(String str1, String str2) {
        int len1 = str1.length();
        int len2 = str2.length();
        if (str2.startsWith(str1) && str2.endsWith(str1)) {
            return true;
        } else {
            return false;
        }
    }

    public int countPrefixSuffixPairs(String[] words) {
        int n = words.length;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (i == j) continue;
                if (prefixAndSuffix(words[i], words[j])) {
                    ans++;
                }
            }
        }
        return ans;
    }
}