class Solution {
public:
    
    struct comparator {
        bool operator()(const vector<int> &a, const vector<int> &b) {
            return -a[1] < -b[1];
        }
    };
    
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(), comparator());
        
        int ans = 0;
        int n = boxTypes.size();
        for (int i = 0; i < n && truckSize > 0; i++) {
            int mn = min(boxTypes[i][0], truckSize);
            ans += boxTypes[i][1]*mn;
            truckSize -= mn;
        }
        return ans;
    }
};