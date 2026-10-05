class Solution {
public:
    int scoreOfParentheses(string s) {
        int mul = 1;
        char pre = ' ';
        int ans = 0;
        for (auto &ch : s) {
            if (ch == '(') mul *= 2;
            else {
                mul /= 2;
                if (pre == '(') {
                    ans += mul;
                }
            }
            pre = ch;
        }
        return ans;
    }
};