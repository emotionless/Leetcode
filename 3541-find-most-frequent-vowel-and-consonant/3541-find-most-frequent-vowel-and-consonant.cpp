class Solution {
public:
    bool isVowel(char ch) {
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }
    int maxFreqSum(string s) {
        unordered_map<char, int> counter;
        int mxv = 0, mxc = 0;
        for (auto &ch : s) {
            counter[ch]++;
            if (isVowel(ch)) {
                mxv = max(mxv, counter[ch]);
            } else {
                mxc = max(mxc, counter[ch]);
            }
        }
        return mxv + mxc;
    }
};