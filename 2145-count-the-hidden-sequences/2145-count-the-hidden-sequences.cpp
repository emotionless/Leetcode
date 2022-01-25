class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        int n = differences.size();
        long long pre = 0;
        long long mn = 0, mx = 0;
        for (auto v : differences) {
            pre += v;
            mn = min(mn, pre);
            mx = max(mx, pre);
        }
        long long need = mx - mn;
        long long total = upper - lower + 1;
        return max(0ll, total - need);
    }
};