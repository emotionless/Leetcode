class Solution {
public:
    
    int solve(int ind, int n) {
        if (ind >= n) return 0;
        int &ret = dp[ind];
        if (ret != -1) return ret;
        ret = -1000000000;
        if (ind != (n-1))
            ret = solve(ind + 1, n);
        ret = max(ret, csum[ind] - solve(ind + 1, n));
        // cout << ind << " " << ret << endl;
        return ret;
    }
    
    int stoneGameVIII(vector<int>& stones) {
        int n = stones.size();
        dp.resize(n, -1);
        csum.resize(n, 0);
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += stones[i];
            csum[i] = sum;
        }
        int ans = solve(1, n);
        return ans;
    }
private:
    vector<int> dp, csum;
};