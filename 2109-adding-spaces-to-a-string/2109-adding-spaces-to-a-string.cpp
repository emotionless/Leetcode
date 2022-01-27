class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        int len = s.size();
        string str = "";
        int ind = 0;
        for (int i = 0; i < len; i++) {
            if (ind < spaces.size() && spaces[ind] == i) {
                str += ' ';
                ind++;
            }
            str += s[i];
        }
        return str;
    }
};