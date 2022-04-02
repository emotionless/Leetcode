class Solution {
public:
    
    int solve(int numArrows, int ind, int mask, vector<int> &aliceArrows) {
        if (ind >= 12) {
            return 0;
        }
        int &ret = dp[mask][ind];
        if (ret != -1) return ret;
        ret = 0;
        ret = solve(numArrows, ind + 1, mask, aliceArrows);
        path[mask][ind] = 0;
        if (aliceArrows[ind] < numArrows) {
            int now = ind + solve(numArrows - aliceArrows[ind] - 1, ind + 1, mask | (1<<ind), aliceArrows);
            if (now > ret) {
                ret = now;
                path[mask][ind] = aliceArrows[ind] + 1;
            }
        }
        
        return ret;
    }
    
    void dfs(int numArrows, int ind, int mask, vector<int> &ans) {
        if (ind >= 12) {
            return;
        }
        ans.push_back(path[mask][ind]);
        dfs(numArrows - path[mask][ind], ind + 1, (path[mask][ind]?mask|(1<<ind) : mask), ans);
        
        return;
    }
    
    vector<int> maximumBobPoints(int numArrows, vector<int>& aliceArrows) {
        dp.resize(1<<12, vector<int>(12, -1));
        path.resize(1<<12 + 1, vector<int>(12, -1));
        
        int res = solve(numArrows, 0, 0, aliceArrows);
        vector<int> ans;
        dfs(numArrows, 0, 0, ans);
        int sum = 0;
        for (auto v : ans) {
            sum += v;
        }
        if (sum != numArrows) {
            ans[11] += numArrows - sum;
        }
        return ans;
    }
private:
    vector<vector<int>> dp, path;
};