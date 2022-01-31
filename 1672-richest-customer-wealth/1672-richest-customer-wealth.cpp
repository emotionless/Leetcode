class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int mx = 0;
        for (auto account : accounts) {
            int sum = 0;
            for (auto money : account) {
                sum += money;
            }
            mx = max(mx, sum);
        }
        return mx;
    }
};