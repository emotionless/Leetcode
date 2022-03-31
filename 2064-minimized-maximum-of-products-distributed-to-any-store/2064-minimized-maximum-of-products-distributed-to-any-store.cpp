class Solution {
public:
    
    int getCount(vector<int> &nums, int m) {
        int sum = 0;
        for (auto v : nums) {
            sum += (v+m-1)/m;
        }
        return sum;
    }
    
    
    int minimizedMaximum(int n, vector<int>& quantities) {
        int st = 1, ed = *max_element(quantities.begin(), quantities.end()), ans = INT_MAX;
        while (st <= ed) {
            int mid = (st + ed) / 2;
            int cnt = getCount(quantities, mid);
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