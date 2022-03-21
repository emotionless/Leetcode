class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char, int> lastPos;
        int len = s.size();
        for (int i = 0; i < len; i++) {
            lastPos[s[i]] = i;
        }
        int mx = 0;
        vector<int> ans;
        int cnt = 0;
        for (int i = 0; i < len; i++) {
            cnt++;
            mx = max(mx, lastPos[s[i]]);
            if (mx == i) {
                ans.push_back(cnt);
                cnt = 0;
            }
        }
        return ans;
    }
};