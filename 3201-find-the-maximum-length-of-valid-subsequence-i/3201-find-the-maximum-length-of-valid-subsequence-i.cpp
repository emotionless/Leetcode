class Solution {
public:
    int getMaxLen(vector<int> &nums, int pre) {
        int cnt = 0;
        for (auto num : nums) {
            if (num%2 != pre) {
                cnt++;
                pre =  num%2;
            }
        }
        return cnt;
    }
    int maximumLength(vector<int>& nums) {
        return max(2, max(getMaxLen(nums, 0), getMaxLen(nums, 1)));
    }
};