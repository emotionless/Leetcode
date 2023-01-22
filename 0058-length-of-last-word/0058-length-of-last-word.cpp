class Solution {
public:
    int lengthOfLastWord(string s) {
        int len = s.size();
        len--;
        while (len >= 0 && isspace(s[len])) {
            len--;
        }
        s.resize(len + 1);
        int ind = len;
        while (ind >= 0 && !isspace(s[ind])) {
            ind--;
        }
        return len - ind;
    }
};