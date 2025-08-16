class Solution {
public:
    int maximum69Number (int num) {
        stringstream ss;
        ss << num;
        string strNum;
        ss >> strNum;
        for (auto &ch : strNum) {
            if  (ch == '6') {
                ch = '9';
                break;
            }
        }
        return stoi(strNum);
    }
};