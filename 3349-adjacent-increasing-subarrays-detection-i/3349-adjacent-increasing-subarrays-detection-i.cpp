class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 0;
        int percent = 0;
        int cnt = 1;
        for (int i = 1;  i < n; i++) {
            if (nums[i] > nums[i-1]) cnt++;
            else {
                percent = cnt;
                cnt = 1;
            }
            ans = max(ans, min(cnt, percent));
            ans = max(ans, cnt / 2);
        }
        return ans >= k;
        
    }
};