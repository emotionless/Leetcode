class Solution {
public:
    const  int MOD =  1e9 + 7;
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<long long> mul(n, 1ll);
        for (auto query : queries) {
            for (int i = query[0];  i  <= query[1]; i += query[2]) {
                long long now = query[3];
                now = (now *  nums[i]) % MOD;
                nums[i] = now;
            }
        }
        int ans = 0;
        for (auto num : nums) {
            ans = ans ^ num;
        }
        return ans;
    }
};