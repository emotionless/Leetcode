class Solution {
public:
    string makeFancyString(string &s) {
        string ret = "";
        char prev = ' ';
        int cnt = 0;
        for (auto &ch : s) {
            if (ch == prev) {
                cnt++;
            } else {
                cnt = 1;
            }
            if (cnt <= 2) {
                ret += ch;
            }
            prev = ch;
        }
        return ret;
    }
};