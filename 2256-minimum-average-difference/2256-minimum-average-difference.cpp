class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        int n = nums.size();
        long long sum = 0;
        for (auto &num : nums) {
            sum += num;
        }
        long long cur = 0;
        long long ans = sum;
        int pos = 0;
        for (int i = 0; i < n; i++) {
            cur += nums[i];
            sum -= nums[i];
            int now = abs(cur/(i+1) - (i < (n-1)?sum/(n - i - 1):0));
            if (now < ans) {
                ans = now;
                pos = i;
            }
        }
        return pos;
    }
};