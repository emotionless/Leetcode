class Solution {
public:
    vector<int> relocateMarbles(vector<int>& nums, vector<int>& moveFrom, vector<int>& moveTo) {
        unordered_map<int, bool> pos;
        for (auto &num : nums) {
            pos[num] = true;
        }
        for (int i = 0; i < moveFrom.size(); i++) {
            if (pos.find(moveFrom[i]) != pos.end()) {
                pos.erase(moveFrom[i]);
                pos[moveTo[i]] = true;
            }
        }
        vector<int> ans;
        for (auto it : pos) {
            ans.push_back(it.first);
        }
        sort(ans.begin(), ans.end());
        
        return ans;
    }
};