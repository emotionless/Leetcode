class Solution {
public:
    
    void solve(int ind, int inc, int ed, const string &s, string &ans) {
        if (ind == ed) {
            if (isalpha(s[ind])) ans += s[ind];
            return;
        }
        if (s[ind] == '(') {
            if ((match[ind] - 1) >= (ind + 1))
                solve(match[ind] - 1, -1, ind + 1, s, ans);
            if ((match[ind] + 1) <= ed)
               solve(match[ind] + 1, inc, ed, s, ans);
        } else if (s[ind] == ')') {
            if ((match[ind] + 1) <= (ind - 1))
                solve(match[ind] + 1, 1, ind - 1, s, ans);
            if ((match[ind] - 1) >= ed)
                solve(match[ind] - 1, inc, ed, s, ans);
        } else {
            ans += s[ind];
            solve(ind + inc, inc, ed, s, ans);
        }
    }
    
    string reverseParentheses(const string &s) {
        string ans = "";
        stack<int> stck;
        int l = s.length();
        match.resize(l, -1);
        for(int i = 0; i < l; i++) {
            if (s[i] == ')') {
                int p = stck.top();
                stck.pop();
                match[p] = i;
                match[i] = p;
            } else if (s[i] == '(') {
                stck.push(i);
            }
        }
        solve(0, 1, l-1, s, ans);
        
        return ans;
    }
private:
    vector<int> match;
};