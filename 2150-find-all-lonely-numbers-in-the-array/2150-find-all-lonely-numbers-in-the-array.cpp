class Solution {
public:
    vector<int> findLonely(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> counter;
        for (auto v : nums) {
            counter[v]++;
        }
        vector<int> ans;
        for (auto v : nums) {
            if (counter[v] == 1) {
                if (counter.find(v + 1) == counter.end() && counter.find(v - 1) == counter.end()) {
                    ans.push_back(v);
                }
            }
        }
        return ans;
    }
};