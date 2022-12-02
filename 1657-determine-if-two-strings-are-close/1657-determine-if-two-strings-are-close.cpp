class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if (word1.length() != word2.length()) return false;
        if (word1.length() == 0) return true;
        int cnter1[26] = {0};
        int cnter2[26] = {0};
        for(auto v : word1) {
            cnter1[v-'a']++;
        }
        for(auto v : word2) {
            cnter2[v-'a']++;
        }
        for(int i = 0; i < 26; i++) {
            if (cnter1[i] <= 0) continue;
            // cout << i << " " << cnter1[i] << endl;
            int pos = -1;
            for(int j = 0; j < 26; j++) {
                if (cnter2[j] == cnter1[i] && cnter1[j] != 0) {
                    pos = j;
                    cnter2[j] = -1;
                    break;
                }
            }
            if (pos == -1) {
                return false;
            }
        }
        return true;
    }
};