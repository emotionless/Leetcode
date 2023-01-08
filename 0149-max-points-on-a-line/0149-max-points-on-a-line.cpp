class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            unordered_map<double, int> counter;
            for (int j = i + 1; j < n; j++) {
                if (points[j][0] == points[i][0]) {
                    counter[INT_MAX]++;
                    continue;
                }
                double m = (points[j][1] - points[i][1] + 0.0) / (points[j][0] - points[i][0] + 0.0);
                counter[m]++;
            }
            for (auto it : counter) {
                ans = max(ans, it.second);
            }
        }
        return ans + 1;
    }
};