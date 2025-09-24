class Solution {
public:
    
    char intToChar(int d) {
        return (char)(d + '0');
    } 
    
    string fractionToDecimal(int num, int den) {
        long long numerator = num, denominator = den;
        if(num == 0) return "0";
        vector<int> decimalDigits;
        string ret = "";
        int repeatedDigit = -1;
        bool check = false;
        map <int, int> val;
        int cnt = 0;
        if(numerator < 0) cnt ^= 1;
        if(denominator < 0) cnt ^= 1;
        if(cnt) ret = "-";
        numerator = abs(numerator);
        denominator = abs(denominator);
        
        long long quotient = numerator / denominator;
        stringstream ss;
        ss << quotient;
        string tmp;
        ss>>tmp;
        ret += tmp;
        numerator %= denominator;
        cnt = 0;
        
        while(numerator > 0) {
            long long quotient = numerator / denominator;
            long long rem = numerator % denominator;
            if(check == true) {
                if(val.find(numerator) != val.end()) {
                    repeatedDigit = val[numerator];
                    break;
                } else {
                    val[numerator] = cnt;
                    decimalDigits.push_back(quotient);
                }
                numerator = rem * 10;
                cnt++;
            } else {
                    ret += ".";
                    check = true;
                    numerator = rem * 10;
            }
        }
        //cout<<repeatedDigit<<endl;
        for(int i = 0; i < decimalDigits.size(); i++) {
            int d = decimalDigits[i];
            if(i == repeatedDigit) {
                ret += "(";
            }
            ret += intToChar(d);
        }
        if(repeatedDigit != -1) {
            ret += ")";
        }
        return ret;
    }
};