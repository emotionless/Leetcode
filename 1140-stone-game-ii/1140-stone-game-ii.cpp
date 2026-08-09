class Solution {
public:
    
    int solve(int cur, const int m, bool is, const vector<int> &piles) {
        if ((cur + 2*m) > piles.size()) {
            if (!is) return 0;
            int sum = 0;
            for(int i = cur; i < piles.size(); i++) {
                sum += piles[i];
            }
            return sum;
        }
        int &ret = dp[cur][m][is];
        if (ret != -1) return ret;
        ret = 0;
        int sum = 0;
        if (is) {
            ret = INT_MIN;
            for(int i = cur; i < (cur + 2*m) && i < piles.size(); i++) {
                sum += piles[i];
                ret = max(ret, sum + solve(i + 1, max(m, i-cur+1), 1 - is, piles));
            }
        } else {
            ret = INT_MAX;
            for(int i = cur; i < (cur + 2*m) && i < piles.size(); i++) {
                sum += piles[i];
                ret = min(ret, solve(i + 1, max(m, i-cur+1), 1 - is, piles));
            }
        }
        // cout << cur << " " << m << " " << is << " " << ret << endl;
        return ret;
    }
    
    
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        dp.resize(n, vector<vector<int>>(n, vector<int>(2, -1)));
        
        return solve(0, 1, 1, piles);
    }
private:
    vector<vector<vector<int>>> dp;
};