class Solution {
public:
    bool possible(int ind, int pre, vector<int> &stones) {
        if (ind == stones.size() - 1) {
            return true;
        }
        int &ret = dp[ind][pre];
        if (ret != -1) return ret;
        ret = 0;
        int dist = stones[ind] - stones[pre];
        for (int i = ind + 1; i < n && (stones[i] - stones[ind]) <= (dist + 1); i++) {
            if ((stones[i] - stones[ind]) >= (dist - 1)) {
                ret = ret + possible(i, ind, stones);
            }
        }
        return ret;
    }
    bool canCross(vector<int>& stones) {
        n = stones.size();
        if (stones[1] - stones[0] != 1) return false;
        dp.resize(n, vector<int>(n, -1));
        return possible(1, 0, stones);
    }
private:
    int n;
    vector<vector<int>> dp;
};