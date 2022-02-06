class Solution {
public:
    
    long long getMinimum(vector<int> &digits) {
        int sz = digits.size();
        int ind = 0;
        while (ind < sz) {
            if (digits[ind] != 0) {
                swap(digits[0], digits[ind]);
                break;
            }
            ind++;
        }
        return getNumber(digits);
    }
    
    long long getNumber(vector<int> &digits) {
        long long ret = 0;
        for (auto &d : digits) {
            ret = ret * 10ll + d;
        }
        return ret;
    }
    
    long long getMaximum(vector<int> &digits) {
        reverse(digits.begin(), digits.end());
        return getNumber(digits);
    }
    
    
    long long smallestNumber(long long num) {
        bool neg = false;
        if (num < 0) neg = true;
        vector<int> digits;
        num = abs(num);
        while (num) {
            int d = num % 10;
            digits.push_back(d);
            num /= 10;
        }
        sort(digits.begin(), digits.end());
        if (neg == false) return getMinimum(digits);
        else return -getMaximum(digits);
    }
};