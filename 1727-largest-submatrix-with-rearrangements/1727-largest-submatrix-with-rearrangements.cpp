class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int n = matrix.size();
        if (n == 0) return 0;
        int m = matrix[0].size();
        if (m == 0) return 0;
        vector<int> colSum(m, 0);
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == 1) {
                    colSum[j] += 1;
                } else {
                    colSum[j] = 0;
                }
            }
            vector<int> curCol = colSum;
            sort(curCol.begin(), curCol.end());
            for (int j = 0; j < m; j++) {
                ans = max(ans, (m - j) * curCol[j]);
            }
        }
        return ans;
    }
};