class Solution {
public:
    const int INF = 100000;
    int getMaxSubsets(int ind, int n, int m) {
        if (ind < 0) {
            return 0;
        }
        int &ret = dp[ind][n][m];
        if (ret != -1) return ret;
        ret = 0;
        ret = getMaxSubsets(ind - 1, n, m);
        if (n >= arr[ind].first && m >= arr[ind].second) {
            ret = max(ret, 1 + getMaxSubsets(ind - 1, n - arr[ind].first, m - arr[ind].second));
        }
        return ret;
    }
    
    int findMaxForm(vector<string>& strs, int m, int n) {
        int sz = strs.size();
        dp.resize(sz, vector<vector<int>>(n + 1, vector<int>(m + 1, -1)));
        for (auto str : strs) {
            int one = 0;
            for (auto ch : str) {
                one += (ch - '0');
            }
            arr.push_back({one, str.length() - one});
        }
        return getMaxSubsets(sz - 1, n, m);
    }
private:
    vector<pair<int, int>> arr;
    vector<vector<vector<int>>> dp;
};