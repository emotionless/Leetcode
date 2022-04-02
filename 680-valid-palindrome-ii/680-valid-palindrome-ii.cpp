class Solution {
public:
    
    bool isPalindrome(string &str, int st, int ed, int cnt) {
        if (cnt > 1) return false;
        while (st <= ed && str[st] == str[ed]) {
            st++;
            ed--;
        }
        if (st > ed) return true;
        return isPalindrome(str, st + 1, ed, cnt + 1) || isPalindrome(str, st, ed - 1, cnt + 1);
    }
    
    bool validPalindrome(string s) {
        return isPalindrome(s, 0, s.size() - 1, 0);
    }
};