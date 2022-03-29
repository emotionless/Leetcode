class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        int st = 1, ed = n - 1;
        int ans = -1;
        while (st <= ed) {
            int mid = (st + ed) / 2;
            int cnt = 0;
            for (auto &v : nums) {
                if (v <= mid) {
                    cnt++;
                }
            }
            if (cnt <= mid) st = mid + 1;
            else {
                ans = mid;
                ed = mid - 1;
            }
        }
        return ans;
    }
};