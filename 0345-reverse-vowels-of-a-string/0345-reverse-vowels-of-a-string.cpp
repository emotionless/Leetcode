class Solution {
public:
    bool isvowel(char ch) {
        ch = tolower(ch);
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }
    string reverseVowels(string s) {
        int i = 0, j = s.size() - 1;
        while (i < j) {
            while (i < j && !isvowel(s[i])) {
                i++;
            }
            while (i < j && !isvowel(s[j])) {
                j--;
            }
            swap(s[i], s[j]);
            i++;
            j--;
        }
        return s;
    }
};