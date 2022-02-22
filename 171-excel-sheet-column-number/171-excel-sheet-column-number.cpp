class Solution {
public:
    
    int getNumber(char ch) {
        return ch - 'A' + 1;
    }
    
    int titleToNumber(string columnTitle) {
        int sum = 0;
        for (auto ch : columnTitle) {
            sum = sum * 26 + getNumber(ch);
        }
        return sum;
    }
};