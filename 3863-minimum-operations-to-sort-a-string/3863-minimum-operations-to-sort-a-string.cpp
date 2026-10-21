class Solution {
public:
    int minOperations(string s) {
        string str = s;
        sort(str.begin(), str.end());
        int len = s.length();
        if (s == str) return 0;
        else if (s[0] == str[0] || s[len-1] == str[len - 1]) return 1;
        else {
            if (len < 3) return -1;
            for (int i = 0; i < len - 1; i++) {
                if (str[0] == s[i]) return 2;
            }
            for (int i = 1; i < len - 1; i++) {
                if (str[len-1] == s[i]) return 2;
            }
            return 3;
        }
    }
};