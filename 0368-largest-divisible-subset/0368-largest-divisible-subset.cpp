class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<int> prev(n, -1), dp(n, 0);
        int maxSetSize = 0;
        int ansInd = 0;
        dp[0] = 1, prev[0] = -1;
        for (int i = 1; i < nums.size(); i++) {
            int mx = 0;
            int pos = -1;
            for (int j = 0; j < i; j++) {
                if (nums[i] % nums[j] == 0) {
                    if (dp[j] > mx) {
                        mx = dp[j];
                        pos = j;
                    }
                }
            }
            dp[i] = mx + 1;
            prev[i] = pos;
            if (maxSetSize < (mx + 1)) {
                maxSetSize = max(maxSetSize, mx + 1);
                ansInd = i;
            }
        }
        int ind = ansInd;
        vector<int> ans;
        while (ind >= 0) {
            ans.push_back(nums[ind]);
            ind = prev[ind];
        }
        return ans;
    }
};