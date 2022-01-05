class Solution {
public:
    bool isPalindrome(int st, int ed, const string &s) {
        if (st >= ed) return true;
        int &ret = dp[st][ed];
        if (ret != -1) return ret;
        ret = 0;
        isPalindrome(st, ed - 1, s);
        isPalindrome(st + 1, ed, s);
        if (s[st] == s[ed]) {
            ret = isPalindrome(st + 1, ed - 1, s);
        }
        
        return ret;
    }
    bool checkPartitioning(string s) {
        int len = s.size();
        dp.resize(len, vector<int>(len, -1));
        isPalindrome(0, len - 1, s);
        for (int i = 0; i < len; i++) {
            if (!dp[0][i]) continue;
            for (int j = len - 1; j > (i+1); j--) {
                if (dp[j][len - 1] && dp[i+1][j-1]) {
                    return true;
                }
            }
        }
        return false;
    }
private:
    vector<vector<int>> dp;
};