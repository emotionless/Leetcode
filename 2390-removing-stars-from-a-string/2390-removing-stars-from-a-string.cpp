class Solution {
public:
    string removeStars(string s) {
        int ind = 0;
        for (auto &ch : s) {
            if (ch == '*') {
                ind--;
            } else {
                s[ind++] = ch;
            }
        }
        
        return s.substr(0, ind);
    }
};