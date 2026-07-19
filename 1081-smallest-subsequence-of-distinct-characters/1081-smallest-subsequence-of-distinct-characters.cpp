class Solution {
public:
    string smallestSubsequence(string s) {
        int len = s.length();
        int last[130] = {-1};
        for(int i = 0; i < len; i++) {
            last[s[i]] = i;
        }
        // cout << last['d'] << endl;
        stack<char> stck;
        map<char, bool> vis;
        for(int i = 0; i < len; i++) {
            // cout << s[i] << " kore: \n";if)
            if(vis[s[i]] == true) continue;
            
            while(!stck.empty()) {
                char top = stck.top();
                if (top >= s[i] && last[top] >=  i) {
                    vis[top] = false;
                    // cout << top << " " << last[top] << " " << i << endl;
                    stck.pop();
                } else {
                    break;
                }
            }
            if (!vis[s[i]]) {
                stck.push(s[i]);
                vis[s[i]] = true;
            }
        }
        string ans = "";
        while(!stck.empty()) {
            ans = stck.top() + ans;
            stck.pop();
        }
        return ans;
    }
};