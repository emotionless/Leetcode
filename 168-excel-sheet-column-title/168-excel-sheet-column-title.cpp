class Solution {
public:
    char getChar(int d) {
        return (char)(d + 'A');
    }
    string convertToTitle(int columnNumber) {
        string str = "";
        while (columnNumber > 0) {
            columnNumber--;
            int d = columnNumber % 26;
            // cout << d << endl;
            str = getChar(d) + str;
            columnNumber /= 26;
        }
        return str;
    }
};