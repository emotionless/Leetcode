class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int mn = INT_MAX;
        int ans = 0;
        for(int i = 0; i < n; i++) {
            int j = i + 1, k = n - 1;
            while (j < k) {
                int sum = nums[j] + nums[k] + nums[i];
                if (sum <= target) {
                    if (abs(target - sum) < mn) {
                        mn = abs(target - sum);
                        ans = sum;
                    }
                    j++;
                } else {
                    if (abs(target - sum) < mn) {
                        mn = abs(target - sum);
                        ans = sum;
                    }
                    k--;
                }
            }
        }
        return ans;
    }
};