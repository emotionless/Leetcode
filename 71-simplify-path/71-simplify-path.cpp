class Solution {
public:
    string simplifyPath(string path) {
        string str = path;
        for (auto &ch : str) {
            if (ch == '/') ch = ' ';
        }
        stringstream ss(str);
        string tmp;
        stack<string> container;
        while (ss >> tmp) {
            if (tmp == ".") {
                continue;
            } else if (tmp == "..") {
                if (container.size()) {
                    container.pop();
                }
            } else {
                container.push(tmp);
            }
        }
        string ans = "";
        if (container.size() == 0) return "/";
        while (!container.empty()) {
            ans = "/" + container.top() + ans;
            container.pop();
        }
        return ans;
    }
};