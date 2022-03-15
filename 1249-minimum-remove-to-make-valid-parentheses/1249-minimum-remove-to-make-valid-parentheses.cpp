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
        int len = s.size();
        for (int i = len - 1; i >= 0 && cnt > 0; i--) {
            if (s[i] == '(') {
                s[i] = '#';
                cnt--;
            }
        }
        int j = 0;
        for (int i = 0; i < len; i++) {
            if (s[i] != '#') {
                s[j++] = s[i];
            }
        }
        s.resize(j);
        return s;
    }
};