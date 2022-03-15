class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int cnt = 0;
        for (auto &ch : s) {
            if (ch == '(') {
                cnt++;
            } else if (ch == ')') {
                if (cnt == 0) {
                    ch = '#';
                } else {
                    cnt--;
                }
            }
        }
        for (int i = s.size() - 1; i >= 0 && cnt > 0; i--) {
            if (s[i] == '(') {
                s[i] = '#';
                cnt--;
            }
        }
        string ans;
        for (auto ch : s) {
            if (ch != '#')
                ans += ch;
        }
        return ans;
    }
};