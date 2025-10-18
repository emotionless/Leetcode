class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int lowest = INT_MIN;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int mx = max(lowest, nums[i] - k);
            if (mx <= (nums[i] + k)) {
                lowest = mx;
                lowest++;
                ans++;
            }
        }
        return ans;
    }
};