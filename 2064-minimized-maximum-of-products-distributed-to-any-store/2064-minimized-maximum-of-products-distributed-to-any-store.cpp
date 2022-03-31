class Solution {
public:
    
    long long getCount(vector<int> &nums, int m) {
        long long sum = 0;
        for (auto v : nums) {
            sum += (v+m-1ll)/m;
        }
        return sum;
    }
    
    
    int minimizedMaximum(int n, vector<int>& quantities) {
        int st = 1, ed = 1e9, ans = INT_MAX;
        while (st <= ed) {
            int mid = (st + ed) / 2;
            long long cnt = getCount(quantities, mid);
            if (cnt <= n) {
                ans = mid;
                ed = mid - 1;
            } else {
                st = mid + 1;
            }
        }
        return ans;
    }
};