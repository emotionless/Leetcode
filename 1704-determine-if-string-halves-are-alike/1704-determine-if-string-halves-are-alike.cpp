class Solution {
public:
    
    bool isVowel(char ch) {
        ch = tolower(ch);
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }
    
    bool halvesAreAlike(string s) {
        int len = s.size();
        int sum = 0;
        for (int i = 0; i < len; i++) {
            if (isVowel(s[i])) {
                if (i < len/2) sum += 1;
                else sum -= 1;
            }
        }
        return sum == 0;
    }
};