class Solution {
public:
    
    void solve(const string str, const int rem, int cnt, vector<string> &ans) {
        if (rem == 0) {
            if (cnt == 0) {
                ans.push_back(str);
            }
            return;
        }
        solve(str + "(", rem-1, cnt + 1, ans);
        if (cnt) {
            solve(str + ")", rem - 1, cnt - 1, ans);
        }
        return;
    }
    
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        solve("", n*2, 0, ans);
        return ans;
    }
};