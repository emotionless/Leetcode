class Solution {
public:
    
    bool isPalindrome(int st, int ed, string &s) {
        while (st <= ed) {
            if (s[st] != s[ed]) return false;
            st++;
            ed--;
        }
        return true;
    }
    
    void solve(int ind, string &s, vector<string> &cur, vector<vector<string>> &ans) {
        if (ind == s.size()) {
            ans.push_back(cur);
            return;
        }
        
        for (int i = ind; i < s.size(); i++) {
            if (palindrome[ind][i]) {
                cur.push_back(s.substr(ind, i - ind + 1));
                solve(i + 1, s, cur, ans);
                cur.pop_back();
            }
        }
        return;
    }
    
    vector<vector<string>> partition(string s) {
        int len = s.size();
        palindrome.resize(len, vector<bool>(len, false));
        for (int i = 0; i < s.size(); i++) {
            for (int j = i; j < s.size(); j++) {
                palindrome[i][j] = isPalindrome(i, j, s);
            }
        }
        vector<vector<string>> ans;
        vector<string> cur;
        solve(0, s, cur, ans);
        
        return ans;
    }
private:
    vector<vector<bool>> palindrome;
};