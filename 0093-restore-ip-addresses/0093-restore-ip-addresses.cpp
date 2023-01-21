class Solution {
public:
    
    void backTrack(int ind, string s, vector<string> cur, vector<string> &ans) {
        if (ind == s.length()) {
            if (cur.size() == 4) {
                ans.push_back(cur[0] + "." + cur[1] + "." + cur[2] + "." + cur[3]);
            }
            return;
        }
        if (cur.size() == 4) {
            return;
        }
        for (int i = ind; i < s.length() && (i - ind) <= 2; i++) {
            if (s[ind] == '0' && i > ind) continue;
            string str = s.substr(ind, i-ind+1);
            if (stoi(str) <= 255) {
                vector<string> tmp(cur.begin(), cur.end());
                tmp.push_back(str);
                backTrack(i+1, s, tmp, ans);
            }
        }
    }
    
    vector<string> restoreIpAddresses(string s) {
        vector<string> ans, cur;
        backTrack(0, s, cur, ans);
        return ans;
    }
};