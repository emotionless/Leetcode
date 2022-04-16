class Solution {
public:
    
    int getSize(int u, vector<vector<int>> &mat) {
        int &ret = dp[u];
        ret = 1;
        for (auto &v : mat[u]) {
            ret += getSize(v, mat);
        }
        return ret;
    }
    
    
    int countHighestScoreNodes(vector<int>& parents) {
        vector<vector<int>> mat;
        int n = parents.size();
        mat.resize(n);
        dp.resize(n, 0);
        for (int i = 1; i < n; i++) {
            mat[parents[i]].push_back(i);
        }
        int sz = getSize(0, mat);
        
        long long mx = 0;
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            long long mul = 1;
            int sum = 1;
            for (auto &v : mat[i]) {
                sum += dp[v];
                mul *= 1ll*dp[v];
            }
            long long total = max(1ll, 0ll +(n - sum)) * 1ll*mul;
            if (total == mx) {
                cnt++;
            } else if (total > mx) {
                mx = total;
                cnt = 1;
            }
        }
        
        return cnt;
    }
private:
    vector<int> dp;
};