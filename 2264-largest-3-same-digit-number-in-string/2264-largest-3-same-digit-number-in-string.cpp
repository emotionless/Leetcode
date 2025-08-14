class Solution {
public:
    bool isSubString(string num, string sub) {
        for  (int i = 0; i < num.length() - 2; i++) {
            if(num[i] == sub[0] && num[i+1] == sub[1] && num[i+2] == sub[2]) return true;
        }
        return  false;
    }
    string largestGoodInteger(string num) {
        for (int i = 9; i >= 0; i--) {
            string str = "";
            char ch = (char)(i+'0');
            str += ch;
            str += ch;
            str += ch;
            if (isSubString(num, str)) return str;
        }
        return "";
    }
};