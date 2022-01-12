class Solution {
public:
    
    string smallestGreater(string num) {
        int len = num.size();
        int i = len / 2;
        int j = len - i - 1;
        if (i > j) swap(i, j);
        while (i >= 0) {
            if (num[i] < '9') {
                num[i] = num[j] = num[i] + 1;
                break;
            } else {
                num[i] = num[j] = '0';
            }
            i--;
            j++;
        }
        if (i >= 0) {
            string last = num.substr(0, i);
            reverse(last.begin(), last.end());
            return num.substr(0, j + 1) + last;
        } else {
            num[len - 1] = '1';
            return "1" + num;
        }
    }
    
    string maximumSmaller(string num) {
        int len = num.size();
        if (len == 1) {
            return to_string(stoll(num) - 1);
        }
        int i = len / 2;
        int j = len - i - 1;
        if (i > j) swap(i, j);
        while (i >= 0) {
            if (num[i] > '1' || (num[i] == '1' && i > 0)) {
                num[i] = num[j] = num[i] - 1;
                // cout << i << " " << num[i] << endl;
                break;
            } else {
                num[i] = num[j] = '9';
            }
            i--;
            j++;
        }
        if (i >= 0) {
            for (int k = i + 1; k < j; k++) {
                num[k] = '9';
            }
            while (i >= 0) {
                num[j] = num[i];
                i--;
                j++;
            }
            return num;
        } else {
            return num.substr(0, len - 1);
        }
    }
    
    string getMirror(string &num) {
        int len = num.size();
        int i = len / 2;
        int j = len - i - 1;
        if (i > j) swap(i, j);
        string first = num.substr(0, i);
        char extra = num[i];
        if (i != j) {
            string rev = first;
            reverse(rev.begin(), rev.end());
            return first + extra + extra + rev;
        } else {
            
            string rev = first;
            reverse(rev.begin(), rev.end());
            return first + extra + rev;
        }
    }
    
    
    string nearestPalindromic(string n) {
        string greater = smallestGreater(n);
        string lesser = maximumSmaller(n);
        string mid = getMirror(n);
        if (mid == n) mid = "0";
        cout << greater << endl;
        cout << lesser << endl;
        if ((stoll(greater) - stoll(n)) < (stoll(n) - stoll(lesser)) && (stoll(greater) - stoll(n)) < llabs(stoll(n) - stoll(mid))) {
            return greater;
        } else if (llabs(stoll(lesser) - stoll(n)) <= llabs(stoll(n) - stoll(mid))) {
            return lesser;
        }
        return mid;
    }
};