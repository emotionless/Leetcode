class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> container;
        for (auto ch : num) {
            while (!container.empty() && container.top() > ch && k > 0) {
                k--;
                container.pop();
            }
            container.push(ch);
        }
        string str = "";
        while (container.size() && k > 0) {
            container.pop();
            k--;
        }
        while (!container.empty()) {
            str = container.top() + str;
            container.pop();
        }
        int ind = 0;
        while (ind < str.size() && str[ind] == '0') ind++;
        if (str.size() == ind) return "0";
        return str.substr(ind);
    }
};