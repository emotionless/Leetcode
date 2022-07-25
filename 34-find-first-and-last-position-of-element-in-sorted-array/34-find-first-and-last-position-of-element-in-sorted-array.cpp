class Solution {
public:
    
    
    vector<int> searchRange(vector<int>& nums, int target) {
        auto it_st = lower_bound(nums.begin(), nums.end(), target);
        
        vector<int> ans;
        if(it_st == nums.end() || *it_st != target) {
            ans.push_back(-1);
            ans.push_back(-1);
            return ans;
        }
        auto it_ed = upper_bound(nums.begin(), nums.end(), target);
        ans.push_back(it_st - nums.begin());
        ans.push_back(it_ed - nums.begin() - 1);
        
        return ans;
    }
};