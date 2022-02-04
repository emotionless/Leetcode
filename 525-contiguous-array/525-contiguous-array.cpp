class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int sum = 0;
        unordered_map<int, int> position;
        int n = nums.size();
        position[sum] = -1;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            sum += (nums[i] == 0? -1 : 1);
            if (position.find(sum) != position.end()) {
                ans = max(ans, i - position[sum]);
            } else {
                position[sum] = i;
            }
        }
        return ans;
    }
};