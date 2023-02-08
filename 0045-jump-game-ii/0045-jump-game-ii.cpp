class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return 0;
        int mx = nums[0];
        int cnt = 1;
        int last = mx;
        for (int i = 1; i < n; i++) {
            if (i > last) {
                last = mx;
                cnt++;
            }
            mx = max(mx, i + nums[i]);
        }
        return cnt;
    }
};