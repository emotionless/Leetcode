class Solution {
public:
    int solve(int ind, int remaining, vector<vector<int>> &piles) {
        if (ind == n || remaining == 0) {
            return 0;
        }
        int &ret = dp[ind][remaining];
        if (ret != -1) return ret;
        ret = 0;
        ret = solve(ind + 1, remaining, piles);
        int sum = 0;
        for (int i = 0; i < piles[ind].size() && i < remaining; i++) {
            sum += piles[ind][i];
            ret = max(ret, sum + solve(ind + 1, remaining - i - 1, piles));
        }
        return ret;
    }
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        n = piles.size();
        dp.resize(n, vector<int>(k + 1, -1));
        return solve(0, k, piles);
    }
private:
    int n;
    vector<vector<int>> dp;
};