class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        int n = nums.size();
        unordered_set<int> seen;
        for (auto num :  nums) {
            seen.insert(num);
        }
        while (seen.find(original) != seen.end()) {
            original *= 2;
        }
        return original;
    }
};