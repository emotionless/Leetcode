class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        int i, j = 0, k = 0;
        for(auto &s : word1) {
            const int len = s.length();
            for(i = 0; i < len; i++) {
                if (j == word2.size()) return false;
                if (s[i] != word2[j][k]) {
                    return false;
                }
                k++;
                if (k == word2[j].length()) {
                    j++;
                    k = 0;
                }
            }
        }
        if (j != word2.size()) return false;
        return true;
    }
};