class Solution {
public:
    string minWindow(string s, string t) {
        int sSize = s.size();
        int tSize = t.size();
        unordered_map<char, int> sCounter, tCounter;
        for (auto ch : t) {
            tCounter[ch]++;
        }
        int totalTSize = tCounter.size();
        int j = 0;
        int total = 0;
        int ans = sSize + 1;
        int pos = -1;
        for (int i = 0; i < sSize; i++) {
            while (total < totalTSize && j < sSize) {
                sCounter[s[j]]++;
                if (sCounter[s[j]] == tCounter[s[j]]) {
                    total++;
                }
                j++;
            }
            //cout << i << " " << j << " " << total << endl;
            if (total == totalTSize && (j-i) < ans) {
                ans = j - i;
                pos = i;
            }
            sCounter[s[i]]--;
            if (sCounter[s[i]] == (tCounter[s[i]] - 1)) {
                total--;
            }
        }
        if (pos == -1) return "";
        return s.substr(pos, ans);
    }
};