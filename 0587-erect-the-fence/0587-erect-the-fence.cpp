class Solution {
public:
    double cross(vector<int> &i, vector<int> &j, vector<int> &k) {
        return ( (k[1] - i[1]) * (j[0] - i[0]) - (j[1] - i[1]) * (k[0] - i[0]) );
    }
    vector<vector<int>> outerTrees(vector<vector<int>>& point) {
        sort(point.begin(), point.end());
        int n = point.size();
        // Build lower hull
        int k=0;
        vector<vector<int>> hull(point.size() + 5);
        for(int i=0; i<n; i++)
        {
            while(k>=2 && cross(hull[k-2], hull[k-1], point[i]) < 0) k--;
            hull[k++] = point[i];
        }

        // Build upper hull
        int t = k + 1;      // t is the lowest point where it can comes
        for(int i = n-2; i >= 0; i--)
        {
            while(k>=t && cross(hull[k-2], hull[k-1], point[i]) < 0) k--;
            hull[k++] = point[i];
        }

        hull.resize(k);
        sort(hull.begin(), hull.end());
        hull.erase(unique(hull.begin(), hull.end()), hull.end());
        return hull;
    }
};