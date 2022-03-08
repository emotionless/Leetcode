class Solution {
public:
    int minOperations(vector<int>& target, vector<int>& arr) {
        unordered_map<int, int> hashVal;
        for (int i = 0; i < target.size(); i++) {
            hashVal[target[i]] = i;
        }
        
        vector<int> nums;
        for (auto v : arr) {
            if (hashVal.find(v) != hashVal.end()) {
                nums.push_back(hashVal[v]);
            }
        }
        int n = nums.size();
        vector<int> ans;
        for (auto v : nums) {
            // cout << v << endl;
            if (ans.size() == 0 || ans.back() < v) {
                ans.push_back(v);
            } else {
                auto it = lower_bound(ans.begin(), ans.end(), v);
                *it = v;
            }
        }
        
        return target.size() - ans.size();
    }
};