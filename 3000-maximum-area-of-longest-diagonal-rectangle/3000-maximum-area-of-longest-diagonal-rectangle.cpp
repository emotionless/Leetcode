class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int mx = 0;
        for (auto dim : dimensions) {
            mx = max(mx, dim[0]*dim[1]);
        }
        return mx;
    }
};