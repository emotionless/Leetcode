class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 0);
        vector<vector<int>> mat(n + 1, vector<int>(32, -1));
        for (int i = n-1; i >= 0; i--) {
            int num = nums[i];
            for (int j = 0; j < 31; j++) {
                mat[i][j] = mat[i+1][j];
            }
            for (int j = 0; j < 31; j++) {
                if (num&(1<<j)) {
                    mat[i][j] = i;
                }
            }
        }

        for (int i = 0; i < n; i++) {
            int mx = 0;
            for (int j = 0; j < 31; j++) {
                mx = max(mx, mat[i][j]);
            }
            ans[i] = (mx - i + 1);
        }
        return ans;
    }
};