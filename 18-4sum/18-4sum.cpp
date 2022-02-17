class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        set<vector<int>> ans;
        for (int i = 0; i < n; i++) {
            if (i && nums[i] == nums[i-1]) continue;
            for (int j = i + 1; j < n; j++) {
                if (j > (i+1) &&  nums[j] == nums[j-1]) continue;
                int k = j + 1, l = n - 1;
                while (k < l) {
                    long long sum = 0ll + nums[k] + nums[l] + nums[i] + nums[j];
                    if (sum == target) {
                        ans.insert({nums[i], nums[j], nums[k], nums[l]});
                        k++;
                    } else if (sum > target) {
                        l--;
                    } else {
                        k++;
                    }
                }
            }
        }
        vector<vector<int>> res(ans.begin(), ans.end());
        return res;
    }
};