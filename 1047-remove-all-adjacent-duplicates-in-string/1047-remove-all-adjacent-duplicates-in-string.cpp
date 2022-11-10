class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> stak;
        for (auto &ch : s) {
            if (stak.size() && stak.top() == ch) {
                stak.pop();
            } else {
                stak.push(ch);
            }
        }
        string ans = "";
        while (stak.size()) {
            ans = stak.top() + ans;
            stak.pop();
        }
        return ans;
    }
};