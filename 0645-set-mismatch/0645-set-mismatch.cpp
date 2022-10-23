class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int ind = 1, duplicate = n, missing = n;
        for (int i = 0; i < n; i++) {
            if (nums[i] > ind) {
                missing = ind;
                ind++;
            } else if (nums[i] < ind) {
                duplicate = nums[i];
                ind--;
            }
            ind++;
        }
        return {duplicate, missing};
    }
};