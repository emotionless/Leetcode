class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        vector<int> right(n, 0);
        int cnt = 0;
        for (int i = n - 1; i >= 0; i--) {
            right[i] = cnt;
            if (nums[i] == 0) {
                cnt = 0;
            } else {
                cnt++;
            }
        }
        cnt = 0;
        int mx = 0;
        for (int i = 0; i < n; i++) {
            mx = max(mx, right[i] + cnt);
            if (nums[i] == 0) {
                cnt = 0;
            } else {
                cnt++;
            }
        }
        return mx;
    }
};