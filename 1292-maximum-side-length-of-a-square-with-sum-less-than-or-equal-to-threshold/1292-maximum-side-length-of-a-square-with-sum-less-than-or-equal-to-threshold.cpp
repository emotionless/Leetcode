class Solution {
public:
    int getSum(int i1,int j1, int  i2, int j2, vector<vector<int>> &dp) {
        return dp[i2][j2] - ((j1-1) >= 0? dp[i2][j-1] : 0) - ((i1 - 1) >= 0? dp[i1-1][j2] : 0) - 
    }
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        
    }
};