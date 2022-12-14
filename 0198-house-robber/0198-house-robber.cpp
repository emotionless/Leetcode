class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        int pre1 = 0, pre2 = 0, cur;
        for (int i = n - 1; i >= 0; i--) {
            cur = nums[i] + pre2;
            cur = max(cur, pre1);
            pre2 = pre1;
            pre1 = cur;
        }
        return pre1;
    }
};