class Solution {
public:
    bool isPalindrome(string &str) {
        int i = 0,  j = str.size() - 1;
        while (i <= j) {
            if (str[i] != str[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    int longestPalindrome(string s, string t) {
        int len1= s.size();
        int len2 = t.size();
        int ans = 1;
        for (int i = 0; i <= len1; i++) {
            for (int j = i; j <= len1; j++) {
                for (int p = 0; p <= len2; p++) {
                    for (int q = p; q <= len2; q++) {
                        string str = s.substr(i, j - i + 1) + t.substr(p, q - p + 1);
                        // cout << str << endl;
                        if (isPalindrome(str)) {
                            ans = max(ans, (int)str.size());
                        }
                        // str = t.substr(p, q - p + 1) + s.substr(i, j - i + 1) ;
                        // // cout << str << endl;
                        // if (isPalindrome(str)) {
                        //     ans = max(ans, (int)str.size());
                        // }
                    }
                }
            }
        }
        return ans;
    }
};