class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        unordered_map<int, vector<int>> container;
        int n = nums.size();
        int ans = INT_MAX;
        for (int  i  = 0; i < n; i++) {
            auto &cur = container[nums[i]];
            cur.push_back(i);
            if (cur.size()  > 2) {
                int sz = cur.size();
                ans = min(ans, cur[sz - 1] - cur[sz - 2]  + cur[sz - 2] - cur[sz - 3]  + cur[sz - 1] - cur[sz - 3]);
            }
        }
        if (ans == INT_MAX) return -1;
        return ans;
    }
};