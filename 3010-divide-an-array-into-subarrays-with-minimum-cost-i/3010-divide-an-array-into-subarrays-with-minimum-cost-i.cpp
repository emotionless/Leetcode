class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int n = nums.size();
        int num1 = INT_MAX;
        int num2 = INT_MAX;
        for (int i = 1; i < n; i++) {
            int num = nums[i];
            if  (num < num1) {
                num2 = num1;
                num1 = num;
            } else if (num < num2) {
                num2 = num;
            }
        }
        return nums[0] + num1 + num2;
    }
};