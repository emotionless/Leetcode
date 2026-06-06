class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int sum = 0, left = 0;
        vector<int> ans;
        for (auto num  : nums) sum += num;
        for (auto num :  nums) {
            sum -= num;
            ans.push_back(abs(left - sum));
            left += num;
        }
        return ans;
    }
};