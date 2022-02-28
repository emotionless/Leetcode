class Solution {
public:
    
    string getString(int st, int ed) {
        if (st == ed) return to_string(st);
        return to_string(st) + "->" + to_string(ed);
    }
    
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        if (nums.size() == 0) return {};
        int pre = 0;
        int n = nums.size();
        for (int i = 1; i < n; i++) {
            if (nums[i] != (nums[i-1] + 1)) {
                ans.push_back(getString(nums[pre], nums[i-1]));
                pre = i;
            }
        }
        ans.push_back(getString(nums[pre], nums[n - 1]));
        
        return ans;
    }
};