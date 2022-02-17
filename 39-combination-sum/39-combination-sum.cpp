class Solution {
public:
    
    void solve(int ind, int remaining, vector<int> &cur, vector<int> &candidates, vector<vector<int>> &ans) {
        if (remaining == 0) {
            ans.push_back(cur);
            return;
        }
        if (ind == candidates.size()) return;
        solve(ind + 1, remaining, cur, candidates, ans);
        if (candidates[ind] <= remaining) {
            cur.push_back(candidates[ind]);
            solve(ind, remaining - candidates[ind], cur, candidates, ans);
            cur.pop_back();
        }
        return;
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> cur;
        solve(0, target, cur, candidates, ans);
        return ans;
    }
};