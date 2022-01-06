class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        unordered_map<int, int> counter;
        for (auto trip : trips) {
            counter[trip[1]] += trip[0];
            counter[trip[2]] -= trip[0];
        }
        int cur = 0;
        for (int i = 0; i <= 100000; i++) {
            cur += counter[i];
            if (cur > capacity) return false;
        }
        return true;
    }
};