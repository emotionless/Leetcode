class Solution {
public:
    int countWays(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int ans = 0;
        if (nums[0]) ans++;
        for (int i = 1; i <= n; i++) {
            if (i && i <= nums[i-1]) continue;
            if (i < n && i >= nums[i]) continue;
            // cout << i << endl;
            ans++;
        }
        return ans;
    }
};