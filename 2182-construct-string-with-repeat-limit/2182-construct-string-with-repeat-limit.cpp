class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        unordered_map<char, int> counter;
        for (auto ch : s) {
            counter[ch]++;
        }
        string ans = "";
        for (char ch = 'z'; ch >= 'a'; ch--) {
            int cnt = counter[ch];
            int tot = repeatLimit;
            for (int i = 0; i < cnt; i++) {
                ans += ch;
                tot--;
                char nxt = ch;
                if (tot == 0 && i < (cnt - 1)) {
                    for (char j = ch - 1; j >= 'a'; j--) {
                        if (counter[j] > 0) {
                            nxt = j;
                            break;
                        }
                    }
                    if (nxt == ch) break;
                    counter[nxt]--;
                    ans += nxt;
                    tot = repeatLimit;
                }
            }
        }
        return ans;
    }
};