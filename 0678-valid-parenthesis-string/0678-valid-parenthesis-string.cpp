class Solution {
public:
    int dp[101][51];
    bool isPossible(int ind, const string str, int left) {
        if (ind == str.length()) {
            return !left;
        }
        if (left < 0 || left > 50) return false;
        int &ret = dp[ind][left];
        if (ret != -1) return ret;
        ret = 0;
        if (str[ind] == '*') {
            ret = isPossible(ind + 1, str, left + 1);
            if (!ret) ret = isPossible(ind + 1, str, left - 1) ;
            if (!ret) ret = isPossible(ind + 1, str, left);
        } else {
            ret = isPossible(ind + 1, str, left + (str[ind] == ')'? -1 : 1));
        }
        return ret;
    }
    
    bool checkValidString(string s) {
        memset(dp, -1, sizeof dp);
        return isPossible(0, s, 0);
    }
};