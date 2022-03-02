class Solution {
public:
    bool isSubsequence(string t, string s) {
        int i = 0, j = 0;
        while (i < s.size() && j < t.size()) {
            if (s[i] == t[j]) {
                j++;
            }
            i++;
        }
        return j == t.size();
    }
};