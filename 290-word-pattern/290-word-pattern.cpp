class Solution {
public:
    bool wordPattern(string pattern, string s) {
        int ind = 0;
        stringstream ss(s);
        string str;
        unordered_map<char, string> vis;
        unordered_map<string, char> visited;
        while (ss >> str) {
            if (visited.find(str) != visited.end()) {
                char ch = visited[str];
                if (pattern[ind] != ch) return false;
            } else {
                if (vis.find(pattern[ind]) != vis.end()) {
                    string tmp = vis[pattern[ind]];
                    if (str != tmp) return false;
                } else {
                    visited[str] = pattern[ind];
                    vis[pattern[ind]] = str;
                }
            }
            //cout << pattern[ind] << endl;
            ind++;
        }
        return ind == pattern.size();
    }
};