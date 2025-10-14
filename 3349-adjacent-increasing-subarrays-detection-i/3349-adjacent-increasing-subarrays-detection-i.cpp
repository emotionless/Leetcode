class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> right(n, 0);
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] < nums[i+1]) right[i] = right[i+1] + 1;
            else
                right[i] = 1;
        }
        int cnt = 0;
        for (int i = 1;  i < n-1; i++) {
            if (nums[i] > nums[i-1]) cnt++;
            else cnt = 1;
            if (cnt >= k && right[i+1] >= k) return true;
        }
        return false;
        
    }
};