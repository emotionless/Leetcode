class Solution {
public:
    long long minimumRemoval(vector<int>& beans) {
        int n = beans.size();
        long long tot = 0;
        for (auto v : beans) {
            tot = tot + v;
        }
        sort(beans.begin(), beans.end());
        long long ans = LLONG_MAX;
        long long sum = 0;
        for (int i = 0; i < n; i++) {
            ans = min(ans, tot - (n-i)*1ll*beans[i]);
        }
        return ans;
    }
};