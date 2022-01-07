class Solution {
public:
    
    int getMaxSum(vector<int> nums, int firstLen, int secondLen) {
        int n = nums.size();
        vector<int> right(n, 0);
        int sum = 0;
        for (int i = n-1; i >= 0; i--) {
            sum += nums[i];
            if ((i+secondLen) < n) {
                sum -= nums[i+secondLen];
            }
            right[i] = max(right[i], sum);
        }
        sum = 0;
        int ans = 0;
        int lft = 0;
        for (int i = 0; i < (n-1); i++) {
            sum += nums[i];
            if (i >= firstLen) {
                sum -= nums[i-firstLen];
            }
            lft = max(lft, sum);
            ans = max(lft + right[i + 1], ans);
        }
        return ans;
    }
    
    int maxSumTwoNoOverlap(vector<int>& nums, int firstLen, int secondLen) {
        return max(getMaxSum(nums, firstLen, secondLen), getMaxSum(nums, secondLen, firstLen));
    }
};