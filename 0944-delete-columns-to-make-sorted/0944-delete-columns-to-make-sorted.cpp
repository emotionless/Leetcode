class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs.size();
        int m = strs[0].size();
        int ans = 0;
        for (int i = 0; i < m; i++) {
            char pre = '0';
            bool ck = false;
            for (int j = 0; j < n; j++) {
                if (strs[j][i] < pre) {
                    ans++;
                    break;
                }
                pre = strs[j][i];
            }
        }
        return ans;
    }
};