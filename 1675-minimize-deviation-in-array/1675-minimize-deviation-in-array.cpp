class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        set<int> container;
        for (auto v : nums) {
            int num = (v&1? v*2 : v);
            container.insert(num);
        }
        int ans = *container.rbegin() - *container.rend();
        while (*container.rbegin() % 2 == 0) {
            int top = *container.rbegin();
            container.insert(top/2);
            container.erase(*container.rbegin());
            ans = min(ans, *container.rbegin() - *container.begin());
        }
        return ans;
    }
};