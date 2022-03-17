class Solution {
public:
    int countSegments(string s) {
        int prev = -1;
        s += " ";
        int len = s.size();
        int ans = 0;
        for (int i = 0; i < len; i++) {
            if (s[i] == ' ') {
                ans += ((i-prev) > 1? 1 : 0);
                prev = i;
            }
        }
        return ans;
    }
};