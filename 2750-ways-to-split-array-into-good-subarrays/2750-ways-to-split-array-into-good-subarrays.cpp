class Solution {
public:
    const int MOD = 1e9 + 7;
    int numberOfGoodSubarraySplits(vector<int>& nums) {
        int n = nums.size();
        bool ck = false;
        long long ans = 1;
        long long cnt = 0;
        for (int i = 0; i < n; i++) {
            if (!ck && nums[i] == 1) {
                ck = true;
                cnt = 0;
                continue;
            }
            if (nums[i] == 0) cnt++;
            else {
                ans = (ans * (cnt + 1)) % MOD;
                cnt = 0;
            }
        }
        if (ck == false) return 0;
        return ans;
    }
};