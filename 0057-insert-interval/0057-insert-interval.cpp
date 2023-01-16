class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& tar) {
        int n = intervals.size();
        vector<vector<int>> ans;
        
        if (n == 0) {
            ans.push_back(tar);
            return ans;
        }
        int j = 0;
        bool found = false;
        for(int i = 0; i < n; i++) {
            int st = intervals[i][0];
            int ed = intervals[i][1];
            if (!found && tar[1] < st) {
                ans.push_back(tar);
                found = true;
            }
            if (found == false && ((tar[0] <= st && st <= tar[1]) || (st <= tar[0] && tar[0] <= ed))){
                found = true;
                st = min(st, tar[0]);
                ed = max(ed, tar[1]);
                while(i < n && intervals[i][0] <= ed) {
                    ed = max(ed, intervals[i][1]);
                    i++;
                }
                i--;
            }
            ans.push_back({st, ed});
        }
        if (!found) ans.push_back(tar);
        
        return ans;
    }
};