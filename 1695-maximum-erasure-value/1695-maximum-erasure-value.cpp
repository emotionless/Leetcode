class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        vector<int> csum, pre;
        auto mx = *max_element(nums.begin(), nums.end());
        int n = nums.size();
        int totalSum = 0;
        pre.resize(mx + 1, 0);
        csum.resize(n + 1, 0);
        int ans = 0;
        int ind = 0;
        for (int i = 0; i < n; i++) {
            totalSum += nums[i];
            ind = max(ind, pre[nums[i]]);
            csum[i + 1] = totalSum;
            pre[nums[i]] = i + 1;
            ans = max(ans, totalSum - csum[ind]);
        }
        return ans;
    }
};