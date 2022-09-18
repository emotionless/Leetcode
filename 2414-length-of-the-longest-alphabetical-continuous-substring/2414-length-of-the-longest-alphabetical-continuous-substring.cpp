class Solution {
public:
    int longestContinuousSubstring(string s) {
        int cnt = 1, mx = 1;
        for (int i = 1; i < s.size(); i++) {
            if (s[i] == (s[i-1] + 1)) {
                cnt++;
            } else {
                cnt = 1;
            }
            mx = max(mx, cnt);
        }
        return mx;
    }
};