class Solution {
public:
    char getCh(char ch) {
        if (mp.find(ch) == mp.end() || mp[ch] == ch) return ch;
        return getCh(mp[ch]);
    }
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        int len = s1.size();
        for (int i = 0; i < len; i++) {
            char a = getCh(s1[i]);
            char b = getCh(s2[i]);
            if (a > b) {
                mp[a] = b;
            } else if (a < b) {
                mp[b] = a;
            }
        }
        for (auto &ch : baseStr) {
            ch = getCh(ch);
        }
        return baseStr;
    }
private:
    unordered_map<char, char> mp;
};