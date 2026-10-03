class Solution {
public:
    int longestValidParentheses(string s) {
        int len = s.length();
        if(!len) return 0;
        stack<int>ST;
        ST.push(-1);
        int ans = 0;
        for(int i = 0; i < len; i++)
        {
            if(s[i] == '(')
            {
                ST.push(i);
            }
            else
            {
                if(ST.size() > 1)
                {
                    int top = ST.top();
                    ST.pop();
                    ans = max(ans, i-ST.top());
                }
                else
                {
                    while(!ST.empty()) ST.pop();
                    ST.push(i);
                }
            }
        }
        return ans;
    }
};