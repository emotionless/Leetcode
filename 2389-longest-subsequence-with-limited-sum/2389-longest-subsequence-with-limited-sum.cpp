class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int> ans;
        int sum = 0;
        for (auto &tar : queries) {
            int sum = 0;
            int pos = -1;
            for (int i = 0; i < n; i++) {
                sum += nums[i];
                if (sum > tar) break;
                pos = i;
            }
            ans.push_back(pos + 1);
        }
        return ans;
    }
};