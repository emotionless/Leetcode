class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> ans(nums.size(), 0);
        int negInd = 1, posInd = 0;
        for (auto num : nums) {
            if (num < 0) {
                ans[negInd] = num;
                negInd += 2;
            } else {
                ans[posInd] = num;
                posInd += 2;
            }
        }
        return ans;
    }
};