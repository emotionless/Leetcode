class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int, int> counter;
        for (int num : nums) {
            counter[num]++;
        }
        int ans = 0;
        for (int num : nums) {
            int left = counter[num-1];
            if (left) {
                ans = max(ans, left + counter[num]);
            }
            int right = counter[num+1];
            if (right) {
                ans = max(ans, right + counter[num]);
            }
            
        }
        return ans;
    }
};