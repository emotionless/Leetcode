class Solution {
public:
    
    int calculateCost(const vector<int> &a, vector<int> &b) {
        int ret = 0;
        for (int i = 0; i < a.size(); i++) {
            ret += (a[i] == b[i])? 1 : 0;
        }
        return ret;
    }
    
    int solve(int ind, int mask, int m, vector<vector<int>> &cost) {
        if (ind == m) {
            return 0;
        }
        int &ret = dp[ind][mask];
        if (ret != -1) return ret;
        ret = 0;
        for (int i = 0; i < m; i++) {
            if (!(mask&(1<<i))) {
                ret = max(ret, cost[ind][i] + solve(ind + 1, mask | (1 << i), m, cost));
            }
        }
        return ret;
    }
    
    int maxCompatibilitySum(vector<vector<int>>& students, vector<vector<int>>& mentors) {
        int m = students.size();
        int n = students[0].size();
        vector<vector<int>> cost(m, vector<int>(m, 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < m; j++) {
                cost[i][j] = calculateCost(students[i], mentors[j]);
            }
        }
        dp.resize(m, vector<int>(1<<m + 1, -1));
        return solve(0, 0, m, cost);
    }
private:
    vector<vector<int>> dp;
};