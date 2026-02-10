class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            unordered_set<int> vis;
            int cnt = 0;
            for (int j = i; j < n; j++) {
                if (vis.find(nums[j]) == vis.end()) {
                    vis.insert(nums[j]);
                    cnt += (nums[j]%2==0?1:-1);
                }
                if (cnt == 0) {
                    ans = max(ans, j - i + 1);
                }
            }
        }
        return ans;
    }
};