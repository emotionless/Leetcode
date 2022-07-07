class Solution {
public:
    
    bool isPossible(int ind, int i, int j, string &s1, string &s2, string &s3) {
        if (ind == s3.length()) {
            return i == s1.length() && j == s2.length();
        }
        if (i >= s1.length() && j >= s2.length()) return false;
        int &ret = dp[i][j];
        if (ret != -1) return ret;
        ret = 0;
        if (i < s1.length() && s3[ind] == s1[i]) {
            ret += isPossible(ind + 1, i + 1, j, s1, s2, s3);
        }
        if (j < s2.length() && s3[ind] == s2[j]) {
            ret += isPossible(ind + 1, i, j + 1, s1, s2, s3);
        }
        return ret;
    }
    
    bool isInterleave(string s1, string s2, string s3) {
        dp.resize(s1.length() + 1, vector<int>(s2.length() + 1, -1));
        return isPossible(0, 0, 0, s1, s2, s3);
    }
private:
    vector<vector<int>> dp;
};