class Solution {
public:
    int solve(int st, int ed, const vector<int> &nums) {
        if (st == ed) {
            return nums[st];
        }
        int &ret = dp[st][ed];
        if (ret != -1) return ret;
        ret = 0;
        int a = nums[st] - solve(st + 1, ed, nums);
        int b = nums[ed] - solve(st, ed - 1, nums);
        ret = max(a, b);
        return ret;
    }
    
    bool stoneGame(vector<int>& nums) {
        int n = nums.size();
        dp.resize(n, vector<int>(n, -1));
        
        int ans = solve(0, n-1, nums);
        return ans > 0;
    }
private:
    vector<vector<int>> dp;
};