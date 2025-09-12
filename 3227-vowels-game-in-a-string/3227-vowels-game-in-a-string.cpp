class Solution {
public:
    bool isVowel(char ch) {
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }
    bool doesAliceWin(string s) {
        int vowelCount = 0;
        for (auto &ch : s) {
            vowelCount += isVowel(ch);
        }
        return vowelCount > 0;
    }
};