class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int mn = INT_MAX;
        int mx = 0;
        for (auto num : nums) {
            mn = min(mn, num);
            mx = max(mx, num);
        }
        return 1ll * (mx - mn) * k;
    }
};