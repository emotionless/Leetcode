class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        map<int, int> counter;
        for (auto trip : trips) {
            counter[trip[1]] += trip[0];
            counter[trip[2]] -= trip[0];
        }
        int cur = 0;
        for (auto it : counter) {
            cur += it.second;
            if (cur > capacity) return false;
        }
        return true;
    }
};