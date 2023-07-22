class Solution {
public:
    bool checkArray(vector<int>& nums, int k) {
        unordered_map<int, int> counter;
        int cnt = 0;
        for (int i = 0; i < nums.size(); i++) {
            cnt += counter[i];
            if (nums[i] < cnt) return false;
            int diff = nums[i] - cnt;
            if (diff > 0) {
                if ((i+k) > nums.size()) return false;
                counter[i+k] -= diff;
                cnt = nums[i];
            }
        }
        return true;
    }
};