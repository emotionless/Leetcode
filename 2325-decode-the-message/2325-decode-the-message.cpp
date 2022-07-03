class Solution {
public:
    string decodeMessage(string key, string message) {
        char cur = 'a';
        unordered_map<char, char> mp;
        for (auto &ch : key) {
            if (ch != ' ' && mp.find(ch) == mp.end()) {
                mp[ch] = cur++;
            }
        }
        for (auto &ch : message) {
            if (ch == ' ') continue;
            ch = mp[ch];
        }
        return message;
    }
};