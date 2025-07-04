class Solution {
public:
    bool is_vowel(char ch) {
        ch = tolower(ch);
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }
    string sortVowels(string s) {
        vector<char> vowels;
        for (auto ch : s) {
            if (is_vowel(ch)) {
                vowels.push_back(ch);
            }
        }
        sort(vowels.begin(), vowels.end());
        int ind = 0;
        for (auto &ch : s) {
            if (is_vowel(ch)) {
                ch = vowels[ind++];
            }
        }
        return s;
    }
};