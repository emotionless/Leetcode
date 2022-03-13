class Solution {
public:
    bool isValid(string s) {
        stack<char> stak;
        for (auto &ch : s) {
            if (ch == '(' || ch == '{' || ch == '[') stak.push(ch);
            else {
                if (stak.empty()) return false;
                char now = stak.top();
                stak.pop();
                if (ch == ')') {
                    if (now != '(') return false;
                } else if (ch == '}') {
                    if (now != '{') return false;
                } else {
                    if (now != '[') return false;
                }
            }
        }
        if (stak.size()) return false;
        return true;
    }
};