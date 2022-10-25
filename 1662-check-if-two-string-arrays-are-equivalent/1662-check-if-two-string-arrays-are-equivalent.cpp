class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        int n = word1.size() - 1, m = word2.size() - 1;
        int i = word1[n].size() - 1, j = word2[m].size() - 1;
        while (n >= 0 || m >= 0) {
            if (i < 0) {
                n--;
                if (n < 0) return false;
                i = word1[n].size() - 1;
            }
            if (j < 0) {
                m--;
                if (m < 0) return false;
                j = word2[m].size() - 1;
            }
            if (word1[n][i] != word2[m][j]) return false;
            i--;
            j--;
            if (i < 0 && j < 0 && n == 0 && m == 0) return true;
        }
        return true;
    }
};