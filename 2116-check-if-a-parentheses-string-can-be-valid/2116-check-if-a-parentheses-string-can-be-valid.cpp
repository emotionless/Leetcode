class Solution {
public:
    bool canBeValid(string s, string locked) {
        stack<int> left, cnt;
        int len = s.size();
        for (int i = 0; i < len; i++) {
            if (locked[i] == '0') {
                cnt.push(i);
            } else {
                if (s[i] == '(') {
                    left.push(i);
                } else {
                    if (left.size() > 0) left.pop();
                    else if (cnt.size() > 0) cnt.pop();
                    else return false;
                }
            }
        }
        if (left.size() > cnt.size()) return false;
        while (!left.empty()) {
            int leftInd = left.top();
            left.pop();
            int ind = cnt.top();
            cnt.pop();
            if (ind <= leftInd) return false;
        }
        
        return cnt.size()%2==0;
    }
};