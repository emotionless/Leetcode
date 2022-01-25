class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;
        for (auto v : nums) {
            cnt += v;
        }
        if (cnt == 0) return 0;
        int sum = 0;
        for (int i = 0; i < cnt - 1; i++) {
            sum += nums[i];
        }
        int ans = n;
        for (int i = 0; i < n; i++) {
            int j = i + cnt - 1;
            j %= n;
            sum += nums[j];
            ans = min(ans, cnt - sum);
            sum -= nums[i];
        }
        return ans;
    }
};