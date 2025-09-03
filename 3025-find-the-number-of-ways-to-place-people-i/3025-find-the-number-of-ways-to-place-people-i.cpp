class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), [](const auto &lft, const auto &rgt) {
            if (lft[0] == rgt[0]) return lft[1] > rgt[1];
            return lft[0] < rgt[0];
        });
        int n = points.size();
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            int mx = INT_MIN;
            for (int j = i + 1; j < n; j++) {
                if (points[j][1] <= points[i][1] && points[j][1] > mx) {
                    mx = points[j][1];
                    cnt++;
                }
            }
        }
        return cnt;
    }
};