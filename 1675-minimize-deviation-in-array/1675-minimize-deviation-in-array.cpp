class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        set<int> container;
        int mn = INT_MAX, mx = INT_MIN;
        for (auto v : nums) {
            int num = (v&1? v*2 : v);
            container.insert(num);
            mx = max(mx, num);
            mn = min(mn, num);
        }
        int ans = *container.rbegin() - *container.rend();
        while (*container.rbegin() % 2 == 0) {
            int top = *container.rbegin();
            container.erase(top);
            container.insert(top/2);
            ans = min(ans, *container.rbegin() - *container.begin());
        }
        return ans;
    }
};