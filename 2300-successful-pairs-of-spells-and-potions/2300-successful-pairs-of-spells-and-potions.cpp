class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(), potions.end());
        vector<int> ans;
        for (auto &spell : spells) {
            auto lb = lower_bound(potions.begin(), potions.end(), (double)success / (double)spell);
            ans.push_back(potions.end() - lb);
        }
        return ans;
    }
};