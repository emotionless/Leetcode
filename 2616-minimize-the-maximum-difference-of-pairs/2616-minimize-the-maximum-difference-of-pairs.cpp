class Solution {
public:
    bool possible(vector<int> &nums, int p, int diff) {
        int n = nums.size();
        for (int i = 1; i < n; i++) {
            if (nums[i] - nums[i-1] <= diff) {
                p--;
                i++;
            }
        }
        return p <= 0;
    }

    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(), nums.end());
        int st = 0, ed = nums[nums.size() - 1] - nums[0];
        int ans = -1;
        while (st <= ed) {
            int mid = (st + ed) / 2;
            if (possible(nums, p, mid)) {
                ans = mid;
                ed = mid - 1;
            }  else {
                st = mid + 1;
            }
        }
        return ans;
    }
};