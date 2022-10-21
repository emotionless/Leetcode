class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> lastPos;
        const int INF = k + 1;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            int prePos = -INF;
            if (lastPos.find(nums[i]) != lastPos.end()) {
                prePos = lastPos[nums[i]];
            }
            if ((i - prePos) <= k) {
                return true;
            }
            lastPos[nums[i]] = i;
        }
        return false;
    }
};