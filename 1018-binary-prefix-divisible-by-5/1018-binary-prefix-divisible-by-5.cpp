class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        vector<bool> ans;
        int sum = 0;
        for (auto num : nums) {
            sum = (sum * 2 + num) % 5;
            if (sum == 0) ans.push_back(true);
            else ans.push_back(false);
        }
        return ans;
    }
};