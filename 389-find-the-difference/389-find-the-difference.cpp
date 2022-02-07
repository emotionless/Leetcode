class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_map<char, int> counter;
        for (auto &ch : s) {
            counter[ch]--;
        }
        for (auto &ch : t) {
            counter[ch]++;
        }
        for (auto mp : counter) {
            if (mp.second > 0) {
                return mp.first;
            }
        }
        assert(0);
    }
};