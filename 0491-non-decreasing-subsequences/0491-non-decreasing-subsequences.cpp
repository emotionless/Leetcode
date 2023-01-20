class Solution {
public:
    
    void backTrack(int ind, vector<int> &cur, vector<int> &nums, vector<vector<int>> &ans) {
        cur.push_back(nums[ind]);
        if (cur.size() > 1) {
            ans.push_back(cur);
        }
        for (int i = ind + 1; i < nums.size(); i++) {
            if (nums[i] >= nums[ind]) {
                backTrack(i, cur, nums, ans);
            }
        }
        cur.pop_back();
        
        return;
    }
    
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> cur;
        for (int i = 0; i < nums.size(); i++) {
            backTrack(i, cur, nums, ans);
        }
        sort(ans.begin(), ans.end());
        ans.erase(unique(ans.begin(), ans.end()), ans.end());
        return ans;
    }
};