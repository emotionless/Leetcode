class Solution {
public:
    
    int isPalindrome(int st, int ed, string &s) {
        if (st >= ed) return true;
        int &ret = dp[st][ed];
        if (ret != -1) return ret;
        ret = false;
        return ret = (s[st] == s[ed]) && isPalindrome(st + 1, ed - 1, s);
    }
    
    int countSubstrings(string s) {
        int n = s.size();
        int counter = 0;
        dp.resize(n, vector<int>(n, -1));
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                if (isPalindrome(i, j, s)) {
                    counter++;
                }
            }
        }
        return counter;
    }
private:
    vector<vector<int>> dp;
};