class Solution {
public:
    const int MOD = 1e9 + 7;
    int specialTriplets(vector<int>& nums) {
        unordered_map<int, long long> left, right;
        for (int num : nums) {
            right[num]++;
        }
        int ans = 0;
        for (auto num : nums) {
            right[num]--;
            ans = (ans + left[num*2] * right[num*2]) % MOD;
            left[num]++;
        }
        return ans;
    }
};