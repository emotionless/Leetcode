class Solution {
public:
    vector<int> goodDaysToRobBank(vector<int>& security, int time) {
        int n = security.size();
        vector<int> right(n, 0);
        right[n-1] = 1;
        for (int i = n - 2; i >= 0; i--) {
            if (security[i] <= security[i+1]) {
                right[i] = right[i+1] + 1;
            } else {
                right[i] = 1;
            }
        }
        int cnt = 0;
        vector<int> ans;
        int pre = INT_MAX;
        for (int i = 0; i < n; i++) {
            if (security[i] <= pre) {
                cnt++;
            } else {
                cnt = 1;
            }
            pre = security[i];
            if (cnt > time && right[i] > time) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};