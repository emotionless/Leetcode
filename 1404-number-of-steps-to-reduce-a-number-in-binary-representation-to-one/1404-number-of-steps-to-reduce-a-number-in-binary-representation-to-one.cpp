class Solution {
public:
    int numSteps(string s) {
        int ans = 0;
        int len = s.length();
        int carry = 0;
        for(int i = len - 1; i >= 0; i--) {
            int cur = s[i] - '0';
            int now = (cur + carry) % 2;
            if (now == 0) {
                ans++;
                carry = (cur + carry) / 2;
            }
            else if (i != 0) {
                ans += 2;
                carry = 1;
            }
        }
        return ans;
    }
};