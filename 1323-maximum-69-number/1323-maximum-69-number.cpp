class Solution {
public:
    int maximum69Number (int num) {
        stringstream ss;
        ss << num;
        string str;
        ss >> str;
        for (auto &ch : str) {
            if (ch == '6') {
                ch = '9';
                break;
            }
        }
        return stoi(str);
    }
};