class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return n;
        int pre = nums[0];
        bool small = false;
        int cnt = 1;
        for(int i = 1; i < n; i++) {
            if (nums[i] < pre && small) {
                small ^= 1;
                cnt++;
            } else if(nums[i] > pre && !small) {
                small ^= 1;
                cnt++;
            }
            pre = nums[i];
        }
        int cnt1 = 1;
        small = true;
        pre = nums[0];
        for(int i = 1; i < n; i++) {
            if (nums[i] < pre && small) {
                small ^= 1;
                cnt1++;
            } else if(nums[i] > pre && !small) {
                small ^= 1;
                cnt1++;
            }
            pre = nums[i];
        }
        return max(cnt, cnt1);
    }
};