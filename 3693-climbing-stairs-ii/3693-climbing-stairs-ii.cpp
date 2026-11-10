class Solution {
public:
    const int INF = INT_MAX;
    int climbStairs(int n, vector<int>& costs) {
        vector<int> dp(4, INF);
        dp[(n-1)%4] = costs[n-1];
        for (int i = n-2; i >= 0; i--) {
            dp[i%4] = INF;
            for (int j = i+1; j < n && (j-i) < 4; j++) {
                dp[i%4] = min(dp[i%4], dp[j%4] + costs[i] + (j-i)*(j-i));
            }
        }
        int ans = INT_MAX;
        for (int i =  0; i < n && i < 3; i++) {
            ans = min(ans, (i+1)*(i+1) + dp[i]);
        }
        return ans;
    }
};