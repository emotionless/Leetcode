class Solution {
public:
    
    long long getSum(vector<int> &nums, int divisor) {
        long long ret = 0;
        for (auto &v : nums) {
            ret += (v+divisor-1ll)/divisor;
        }
        return ret;
    }
    
    int smallestDivisor(vector<int>& nums, int threshold) {
        int st = 1, ed = *max_element(nums.begin(), nums.end());
        int ans = -1;
        while (st <= ed) {
            int mid = (st + ed) / 2;
            if (getSum(nums, mid) <= threshold) {
                ans = mid;
                ed = mid - 1;
            } else {
                st = mid + 1;
            }
        }
        return ans;
    }
};