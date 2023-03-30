class Solution {
public:
    bool isScramble(string s1, string s2) {
        int len = s1.size();
        if (s1 == s2) return true;
        int counter[26] = {0};
        for (auto &ch : s1) {
            counter[ch - 'a']++;
        }
        for (auto &ch : s2) {
            counter[ch - 'a']--;
        }
        for (int i = 0; i< 26; i++) {
            if (counter[i]) return false;
        }
        if (dp.find(s1+s2) != dp.end()) return dp[s1+s2];
        bool &ret = dp[s1+s2];
        ret = false;
        for (int i = 1; i < len; i++) {
            if (isScramble(s1.substr(0, i), s2.substr(0, i)) && isScramble(s1.substr(i), s2.substr(i))) {
                return ret = true;
            }
            if (isScramble(s1.substr(0, i), s2.substr(len - i)) && isScramble(s1.substr(i), s2.substr(0, len - i))) {
                return ret = true;
            }
        }
        return ret = false;
    }
private:
    unordered_map<string, bool> dp;
};