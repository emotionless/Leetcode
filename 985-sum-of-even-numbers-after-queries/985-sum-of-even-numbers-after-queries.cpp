class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int sum = 0;
        for (auto &num : nums) {
            sum += num&1?0:num;
        }
        int n = nums.size();
        int cur = 0;
        vector<int> ans(n);
        for (auto &q : queries) {
            int val = q[0];
            int ind = q[1];
            if (nums[ind]%2==0) sum -= nums[ind];
            nums[ind] += val;
            if (nums[ind]%2==0) sum += nums[ind];
            ans[cur++] = sum;
        }
        return ans;
    }
};