class Solution {
public:
    bool isvowel(char ch) {
        ch = tolower(ch);
        return ch == 'a'|| ch == 'e'|| ch == 'o'|| ch == 'i'|| ch == 'u';
    }
    
    bool isValid(string word) {
        int d = 0, c = 0, v = 0;
        for (auto ch : word) {
            if ((ch >= '0' && ch <= '9') || (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')) {
                if (isvowel(ch)) v++;
                else if (isdigit(ch)) d++;
                else c++;
            } else {
                return false;
            }
        }
        return word.length() >= 3 && v >= 1 && c >= 1;
    }
};