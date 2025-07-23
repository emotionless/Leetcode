class Solution {
public:
    pair<string, int> removeAndGetScore(string s, int cost, string pat) {
        stack<char> container;
        int ans = 0;
        for (auto ch : s) {
            if (container.size() >= 1 && pat[0] == container.top() && ch == pat[1]) {
                ans += cost;
                container.pop();
            } else {
                container.push(ch);
            }
        }
        int sz = container.size();
        string str(sz, ' ');
        while (!container.empty()) {
            str[--sz] = container.top();
            container.pop();
        }
        return make_pair(str, ans);
    }
    int maximumGain(string s, int x, int y) {
        if (x > y) {
            pair<string, int> ans1 = removeAndGetScore(s, x, "ab");
            pair<string, int> ans2 = removeAndGetScore(ans1.first, y, "ba");
            return ans1.second + ans2.second;
        } else {
            pair<string, int> ans2 = removeAndGetScore(s, y, "ba");
            pair<string, int> ans1 = removeAndGetScore(ans2.first, x, "ab");
            return ans1.second + ans2.second;
        }
    }
};