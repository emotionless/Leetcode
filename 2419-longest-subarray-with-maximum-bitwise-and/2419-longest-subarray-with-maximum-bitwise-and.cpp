class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int mx = 0;
        for (auto num : nums) {
            mx = max(num, mx);
        }
        int ans = 0;
        int cnt = 0;
        for (int num : nums) {
            if (mx == num) {
                cnt++;
            } else {
                cnt =  0;
            }
            ans = max(ans, cnt);
        }
        return ans;
    }
};