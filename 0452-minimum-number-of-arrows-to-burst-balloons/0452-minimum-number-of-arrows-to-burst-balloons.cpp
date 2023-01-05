class Solution {
public:
    
    int findMinArrowShots(vector<vector<int>>& points) {
        int n = points.size();
        sort(points.begin(), points.end());
        int ans = 0;
        if (n == 0) return 0;
        ans = 1;
        int mx = points[0][1];
        for (int i = 1; i < n; i++) {
            if (points[i][0] > mx) {
                ans++;
                mx = points[i][1];
            } else {
                mx = min(mx, points[i][1]);
            }
        }
        return ans;
    }
};