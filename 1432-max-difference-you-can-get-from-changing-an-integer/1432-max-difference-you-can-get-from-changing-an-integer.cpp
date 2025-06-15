class Solution {
public:
    
    int makeMin(int num) {
        if (num == 1) return num;
        string str = to_string(num);
        int l = str.length();
        bool ck = false;
        for (int i = 0; i < l; i++) {
            if (str[i] != '1') ck = true;
        }
        if (!ck) return num; 
        if (str[0] == '1') {
            for(int j = 1; j < l; j++) {
                if (str[j] > '1') { 
                    for(int i = j+1; i < l; i++) {
                        if (str[i] == str[j]) str[i] = '0';
                    }
                    str[j] = '0';
                    break;
                }
            }
            return stoi(str);
        }
        for(int i = 1; i < l; i++) {
            if (str[i] == str[0]) str[i] = '1';
        }
        str[0] = '1';
        return stoi(str);
    }
    
    int makeMax(int num) {
        if (num == 9) return num;
        string str = to_string(num);
        int l = str.length();
        bool ck = false;
        for (int i = 0; i < l; i++) {
            if (str[i] != '9') ck = true;
        }
        if (!ck) return num;
        if (str[0] == '9') {
            for(int j = 1; j < l; j++) {
                if (str[j] < '9') { 
                    for(int i = j+1; i < l; i++) {
                        if (str[i] == str[j]) str[i] = '9';
                    }
                    str[j] = '9';
                    break;
                }
            }
            return stoi(str);
        }
        for(int i = 1; i < l; i++) {
            if (str[i] == str[0]) str[i] = '9';
        }
        str[0] = '9';
        return stoi(str);
    }
    int maxDiff(int num) {
        return makeMax(num) - makeMin(num);
    }
};