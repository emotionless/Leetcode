class Solution {
public:
    int myAtoi(string s) {
        long long num = 0;
        bool neg = false;
        int ind = 0;
        while (ind < s.size() && s[ind] == ' ') ind++;
        s = s.substr(ind);
        ind = 0;
        int len = s.size();
        if ((s[0] == '+' || s[0] == '-')) {
            if (s[0] == '-') neg = true;
            ind = 1;
        }
        while (ind < len && s[ind] == '0') {
            ind++;
        }
        s = s.substr(ind);
        for (int i = 0; i < s.size(); i++) {
            if (!isdigit(s[i])) break;
            num = num * 10ll + (s[i] - '0');
            if (num > 1e15) num = 1e15;
        }
        if (neg) {
            num *= -1;
            return max((long long)INT_MIN, num);
        }
        return min((long long) INT_MAX, num);
    }
};