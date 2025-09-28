class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for (int i = n - 2; i > 0; i--) {
            if ((nums[i] + nums[i-1]) > nums[i+1]) {
                return nums[i-1] + nums[i] + nums[i+1];
            }
        }
        return 0;
    }
};