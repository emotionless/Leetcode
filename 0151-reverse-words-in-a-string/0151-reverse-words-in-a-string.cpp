class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        s = "";
        string str;
        bool isFirst = true;
        while (ss >> str) {
            s = str + (isFirst? "" : " ") + s;
            isFirst = false;
        }
        return s;
    }
};