class Solution {
public:
    double getArea(vector<int> &point1, vector<int> &point2, vector<int> &point3) {
        return 0.5f * (point1[0]*(point2[1] - point3[1]) + point2[0]*(point3[1] - point1[1]) + point3[0]*(point1[1] - point2[1]));
    }
    double largestTriangleArea(vector<vector<int>>& points) {
        int n = points.size();
        double ans = 0.0f;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < n; k++) {
                    if (i == j || j == k || i == k) continue;
                    ans = max(ans, getArea(points[i], points[j], points[k]));
                }
            }
        }
        return ans;
    }
};