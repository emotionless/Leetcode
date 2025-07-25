class Solution {
public:
    int maxSum(vector<int>& nums) {
        unordered_set<int>container;
        int mx = INT_MIN;
        for(auto &num : nums) {
            if (num >= 0) {
                container.insert(num);
            } else {
                mx = max(mx, num);
            }
        }
        if (container.size() == 0) return mx;
        int ans = 0;
        for (auto element : container) {
            ans += element;
        }
        return ans;
    }
};