class Solution {
public:
    const int INF = 100000;
    int minDeletion(int ind, const vector<string> &strs) {
        if(ind == (m - 1)) {
            return 0;
        }
        int &ret = dp[ind];
        if (ret != -1) return ret;
        ret = strs[0].size() - ind - 1;
        for (int i = ind + 1; i < m; i++) {
            bool isGreater = true;
            for (int j = 0; j < n; j++) {
                if (strs[j][i] < strs[j][ind]) {
                    isGreater = false;
                    break;
                }
            }
            if (isGreater) {
                ret = min(ret, i - ind - 1 + minDeletion(i, strs));
            }
        }
        return ret;
    }
    
    int minDeletionSize(vector<string>& strs) {
        if (strs[0].size() <= 1) return 0;
        n = strs.size();
        m = strs[0].size();
        dp.resize(m, -1);
        int ans = m;
        for (int i = 0; i < m; i++) {
            ans = min(ans, i + minDeletion(i, strs));
        }
        return ans;
    }
private:
    vector<int> dp;
    int m, n;
};