class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        if (k == 1) return true;
        vector<int> right(n, 1);
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] < nums[i+1]) right[i] = right[i+1] + 1;
            else
                right[i] = 1;
        }
        int cnt = 1;
        for (int i = 1;  i < n-1; i++) {
            if (nums[i] > nums[i-1]) cnt++;
            else cnt = 1;
            if (cnt >= k && right[i+1] >= k) return true;
        }
        return false;
        
    }
};