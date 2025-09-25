class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        if(n == 0) return 0;
        vector<vector<int>> dp(2, vector<int>(n+1, 0));
        dp[0][0] = triangle[0][0];
        const int MAX = 100000000;
        for(int i = 1; i < n; i++) {
           // cout<<endl;
            for(int j = 0; j <= i; j++) {
                dp[i%2][j] = triangle[i][j] + min((j > 0?dp[(i&1)^1][j-1]:MAX), (j < i?dp[(i&1)^1][j]:MAX));
               //cout<<dp[i%2][j]<<" ";
            }
        }
        int ans = MAX;
        for(int i = 0; i < n; i++) {
            ans = min(ans, dp[(n-1)%2][i]);
        }
        return ans;
    }
};