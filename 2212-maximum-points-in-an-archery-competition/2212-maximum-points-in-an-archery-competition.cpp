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
        int n = aliceArrows.size();
        int ans = 0;
        int number = -1;
        for (int i = 0; i < (1<<n); i++) {
            int sum = 0;
            int score = 0;
            for (int j = 0; j < n; j++) {
                if (i&(1<<j)) {
                    sum += aliceArrows[j] + 1;
                    score += j;
                }
            }
            if (sum <= numArrows) {
                if (score > ans) {
                    ans = score;
                    number = i;
                }
            }
        }
        vector<int> ret(n, 0);
        for (int i = 0; i < n; i++) {
            if (number&(1<<i)) {
                ret[i] = aliceArrows[i] + 1;
                numArrows -= (aliceArrows[i] + 1);
            }
        }
        ret[11] += numArrows;
        
        return ret;
    }
private:
    vector<vector<int>> dp, path;
};