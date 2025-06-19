class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int last = nums[0];
        int cnt = 1;
        for (int num : nums) {
            if (num - last > k) {
                cnt++;
                last = num;
            }
        }
        return cnt;
    }
};