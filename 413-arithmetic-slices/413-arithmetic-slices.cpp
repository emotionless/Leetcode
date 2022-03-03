class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) return 0;
        int pre = nums[1] - nums[0];
        int cnt = 1;
        int ans = 0;
        for (int i = 2; i < n; i++) {
            if ((nums[i] - nums[i-1]) == pre) {
                cnt++;
            } else {
                cnt = 1;
            }
            pre = (nums[i] - nums[i-1]);
            ans += cnt - 1;
        }
        return ans;
    }
};