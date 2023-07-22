class Solution {
public:
    
    int getDominant(vector<int> &nums) {
        int cur = -1;
        int cnt = 0;
        for (auto &num : nums) {
            if (cnt == 0) {
                cur = num;
                cnt++;
            } else {
                if (cur == num) {
                    cnt++;
                } else {
                    cnt--;
                }
            }
        }
        return cur;
    }
    
    int minimumIndex(vector<int>& nums) {
        int n = nums.size();
        int dominant = getDominant(nums);
        int total = 0;
        for (auto &num : nums) {
            if (dominant == num) total++;
        }
        int ind = -1;
        int cnt = 0;
        for (int i = n - 1; i > 0; i--) {
            int left = i;
            int right = n - i;
            if (dominant == nums[i]) cnt++;
            if (cnt*2 > right && (total - cnt)*2 > left) {
                ind = i - 1;
            }
        }
        return ind;
    }
};