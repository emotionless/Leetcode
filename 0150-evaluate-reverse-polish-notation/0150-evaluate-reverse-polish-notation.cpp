class Solution {
public:
    long long stringToInt(string str) {
        stringstream ss;
        ss<<str;
        long long num;
        ss>>num;
        return num;
        // int len = str.length();
        // long long ret = 0;
        // for(int i = 0; i < len; i++) {
        //     ret = ret * 10 + (str[i] - '0');
        // }
        // return ret;
    }
    int evalRPN(vector<string>& tokens) {
        int n = tokens.size();
        stack<long long> S;
        for(int i = 0; i < n; i++) {
            if(tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/") {
                long long top1 = S.top();
                S.pop();
                long long top2 = S.top();
                S.pop();
                if(tokens[i] == "+")
                    S.push(top1 + top2);
                else if(tokens[i] == "-")
                    S.push(top2 - top1);
                else if(tokens[i] == "*")
                    S.push(top1 * top2);
                else
                    S.push(top2 / top1);
            } else {
                S.push(stringToInt(tokens[i]));
            }
        }
        return S.top();
    }
};