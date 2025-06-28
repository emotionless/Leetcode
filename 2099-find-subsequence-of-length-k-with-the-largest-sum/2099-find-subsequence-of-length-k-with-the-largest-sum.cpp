class Solution {
public:
    const int INF = 100000;

    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<pair<int, int>> container;
        const int n = nums.size();
        for (int i = 0; i < n; i++) {
            container.push_back(pair(nums[i], i));
        }
        sort(container.begin(), container.end());
        vector<int> ans;
        vector<bool> vis(n, false);
        for (int i = nums.size() - k; i < n; i++) {
            vis[container[i].second] = true;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (vis[i]) ans.push_back(nums[i]);
        }
        return ans;
    }
};