class Solution {
public:
    int scoreOfParentheses(string s) {
        int mul = 1;
        char pre = ' ';
        int ans = 0;
        for (auto &ch : s) {
            if (ch == '(') mul *= 2;
            else {
                if (pre == '(') {
                    ans += mul / 2;
                }
                mul /= 2;
            }
            pre = ch;
        }
        return ans;
    }
};