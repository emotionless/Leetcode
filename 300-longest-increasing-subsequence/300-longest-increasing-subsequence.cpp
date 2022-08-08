class Solution {
public:
    int len = 0;
    int getPos(const vector<int> &arr, int tar, const vector<int> &nums) {
        int st = 0, ed = len;
        int ret = ed + 1;
        while(st <= ed) {
            int mid = (st + ed) / 2;
            if(nums[arr[mid]] >= tar) {
                ed = mid - 1;
                ret = mid;
            } else {
                st = mid + 1;
            }
        }
        return ret;
    }
    
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        vector<int> dp(n, -1);
        // vector<int> seq(n, -1);
        dp[0] = 0;
        len = 0;
        for(int i = 1; i < n; i++) {
            int pos = getPos(dp, nums[i], nums);
            dp[pos] = i;
            if(pos > len) len = pos;
            // if(pos == 0)
            //     seq[i] = -1;
            // else 
            //     seq[i] = dp[pos-1];
        }
        return len+1;
    }
};