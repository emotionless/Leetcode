class Solution {
public:
    const int MOD = (1e9) + 7;
    int numSubseq(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> p(n, 1);
        sort(nums.begin(), nums.end());
        int j = 0;
        int ans = 0;
        for (int i = 1; i < n; i++) {
            if ((nums[i] + nums[0]) <= target) {
                j = i;
            } else {
                break;
            }
            p[i] = (p[i-1] * 2) % MOD;
        }
        for (int i = 0; i < n; i++) {
            while (j >= i && (nums[i] + nums[j]) > target) j--;
            if (j >= i)
                ans = (ans + p[j - i]) % MOD;
            else
                break;
        }
        return ans;
    }
};