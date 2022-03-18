class Solution {
public:
    string removeDuplicateLetters(string s) {
        int len = s.size();
        unordered_map<char, int> pos, vis;
        for (int i = 0; i < len; i++) pos[s[i]] = i;
        stack<char> container;
        for (int i = 0; i < len; i++) {
            while(container.size() && container.top() > s[i] && !vis[s[i]]) {
                if (pos[container.top()] > i) {
                    vis[container.top()] = false;
                    container.pop();
                }
                else break;
            }
            if (!vis[s[i]]) {
                container.push(s[i]);
                vis[s[i]] = true;
            }
        }

        string ret = "";
        while (!container.empty()) {
            ret = container.top() + ret;
            container.pop();
        }
        return ret;
    }
};