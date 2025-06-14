class Solution {
public:
    int minMaxDifference(int num) {
        string str = to_string(num);
        string mx = str;
        string mn = str;
        for (int i = 0; i < str.length(); i++) {
            if (str[0] == mn[i]) {
                mn[i] = '0';
            }
        }
        char tar = '0';
        for (int i = 0; i < str.length(); i++) {
            if (str[i] < '9') {
                tar = str[i];
                break;
            }
        }
        for (int i = 0; i < str.length(); i++) {
            if (mx[i] == tar) {
                mx[i] = '9';
            }
        }
        return stoi(mx) - stoi(mn);
    }
};