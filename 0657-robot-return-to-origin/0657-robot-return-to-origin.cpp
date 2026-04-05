class Solution {
public:
    bool judgeCircle(string moves) {
        int l = 0, u = 0;
        for  (auto ch : moves) {
            if (ch == 'L') l++;
            else if (ch == 'R') l--;
            else if (ch == 'U') u++;
            else u--;
        }
        return l == 0 && u == 0;
    }
};