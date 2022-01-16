class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> ans;
        int len = s.size();
        for (int i = 0; i < len; i += k) {
            ans.push_back(s.substr(i, k));
        }
        if (len%k) {
            int mod = len % k;
            string last = ans[ans.size() - 1];
            for (int i = mod; i < k; i++) {
                last += fill;
            }
            ans[ans.size() - 1] = last;
        }
        return ans;
    }
};