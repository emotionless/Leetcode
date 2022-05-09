class Solution {
public:
    vector<char> store[60];
    void calculate(int ind, string cur, const string &str, vector<string> &res) {
        if(ind < 0) {
            if(cur.length())
                res.push_back(cur);
            return;
        }
        char dig = str[ind];
        for(int i = 0; i < store[dig].size(); i++) {
            calculate(ind - 1, store[dig][i] + cur, str, res);
        }
        return;
    }
    
    vector<string> letterCombinations(string digits) {
        for(int i = '2'; i <= '9'; i++) {
            store[i].clear();
        }
        store['2'].push_back('a');
        store['2'].push_back('b');
        store['2'].push_back('c');
        
        
        store['3'].push_back('d');
        store['3'].push_back('e');
        store['3'].push_back('f');
        
        
        store['4'].push_back('g');
        store['4'].push_back('h');
        store['4'].push_back('i');
        
        
        store['5'].push_back('j');
        store['5'].push_back('k');
        store['5'].push_back('l');
        
        store['6'].push_back('m');
        store['6'].push_back('n');
        store['6'].push_back('o');
        
        store['7'].push_back('p');
        store['7'].push_back('q');
        store['7'].push_back('r');
        store['7'].push_back('s');
        
        
        store['8'].push_back('t');
        store['8'].push_back('u');
        store['8'].push_back('v');
        
        store['9'].push_back('w');
        store['9'].push_back('x');
        store['9'].push_back('y');
        store['9'].push_back('z');
        vector<string> res;
        calculate(digits.length() - 1, "", digits, res);
        
        return res;
    }
};