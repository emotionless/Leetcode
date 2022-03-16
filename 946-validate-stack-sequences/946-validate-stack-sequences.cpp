class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> container;
        int ind = 0;
        int sz = popped.size();
        for (auto num : pushed) {
            container.push(num);
            while (container.size() && ind < sz && container.top() == popped[ind]) {
                container.pop();
                ind++;
            }
        }
        return ind == sz;
    }
};