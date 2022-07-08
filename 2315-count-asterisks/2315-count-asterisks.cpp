class Solution {
public:
    int countAsterisks(string s) {
        bool check = true;
        int cnt = 0;
        for (auto &ch : s) {
            if (ch == '|') {
                check ^= 1;
            } else if (ch == '*') {
                cnt += check;
            }
        }
        return cnt;
    }
};