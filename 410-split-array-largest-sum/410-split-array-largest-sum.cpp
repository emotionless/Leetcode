class Solution {
public:
    
    int getCount(vector<int> &nums, int m) {
        int counter = 0;
        int sum = 0;
        for (auto v : nums) {
            sum += v;
            if (v > m) return INT_MAX;
            if (sum > m) {
                counter++;
                sum = v;
            }
        }
        if (sum) counter++;
        return counter;
    }
    
    int splitArray(vector<int>& nums, int m) {
        int st = 0, ed = 1e9, ans = INT_MAX;
        while (st <= ed) {
            int mid = (st + ed) / 2;
            int cnt = getCount(nums, mid);
            if (cnt <= m) {
                ans = mid;
                ed = mid - 1;
            } else {
                st = mid + 1;
            }
        }
        return ans;
    }
};