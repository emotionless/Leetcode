class Solution {
public:
    int maximum69Number (int num) {
        string strNum;
        strNum = to_string(num);
        for (auto &ch : strNum) {
            if  (ch == '6') {
                ch = '9';
                break;
            }
        }
        return stoi(strNum);
    }
};