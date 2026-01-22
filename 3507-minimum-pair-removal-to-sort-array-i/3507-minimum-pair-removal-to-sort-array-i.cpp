class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        int n = nums.size();
        while (nums.size() > 1) {
            int mx = INT_MAX;
            bool ck = true;
            int ind = -1;
            for (int i = 0; i < nums.size() - 1; i++) {
                int sum = nums[i] + nums[i+1];
                if (nums[i] > nums[i+1]) {
                    ck = false;
                }
                if (sum < mx) {
                    mx = sum;
                    ind = i;
                }
            }
            if (ck) {
                break;
            }
            nums[ind] = mx;
            nums.erase(nums.begin() + ind + 1);
        }
        return n - nums.size();
    }
};