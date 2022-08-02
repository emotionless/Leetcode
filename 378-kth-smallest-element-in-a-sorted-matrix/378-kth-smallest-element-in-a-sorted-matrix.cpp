class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int m = matrix[0].size();
        int st = matrix[0][0], ed = matrix[n-1][m-1], ans = -1;
        while (st <= ed) {
            int mid = (st + ed) / 2;
            int total = 0;
            for (auto row : matrix) {
                auto pos = upper_bound(row.begin(), row.end(), mid) - row.begin();
                total += pos;
            }
            if (total >= k) {
                ans = mid;
                ed = mid - 1;
            } else {
                st = mid + 1;
            }
        }
        return ans;
    }
};