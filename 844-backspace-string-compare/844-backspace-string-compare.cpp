class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int i = s.size() - 1, j = t.size() - 1;
        int cnt1 = 0, cnt2 = 0;
        while (i >= 0 || j >= 0) {
            while (i >= 0 && (s[i] == '#' || cnt1 > 0)) {
                if (s[i] == '#') cnt1++;
                else cnt1--;
                i--;
            }
            while (j >= 0 && (t[j] == '#' || cnt2 > 0)) {
                if (t[j] == '#') cnt2++;
                else cnt2--;
                j--;
            }
            if (i < 0 && j < 0) break;
            if (i < 0 || j < 0) return false;
            if (s[i] != t[j]) return false;
            i--;
            j--;
        }
        return true;
    }
};