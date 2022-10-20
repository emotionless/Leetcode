class Solution {
public:
    string intToRoman(int num) {
        map<int, string> val;
        val[1] = "I";
        val[4] = "IV";
        val[5] = "V";
        val[9] = "IX";
        val[10] = "X";
        val[40] = "XL";
        val[50] = "L";
        val[90] = "XC";
        val[100] = "C";
        val[400] = "CD";
        val[500] = "D";
        val[900] = "CM";
        val[1000] = "M";
        
        string ans = "";
        while(num > 0) {
            for(auto it = val.rbegin(); it != val.rend(); it++) {
                cout << it->first << endl;
                while(it->first <= num) {
                    ans += it->second;
                    num -= it->first;
                }
            }
        }
        return ans;
    }
};