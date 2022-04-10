class Solution {
public:
    int calPoints(vector<string>& ops) {
        stack<int> container;
        for (auto &str : ops) {
            if (str == "+") {
                int a = container.top(); container.pop();
                int b = container.top();
                container.push(a);
                container.push(a + b);
            } else if (str == "C") {
                container.pop();
            } else if (str == "D") {
                container.push(container.top() * 2);
            } else {
                container.push(stoi(str));
            }
        }
        int ans = 0;
        while (container.size()) {
            ans += container.top();
            container.pop();
        }
        return ans;
    }
};