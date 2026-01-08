class Solution {
public:
    int solve(int ind1,  int ind2, vector<int>& nums1, vector<int>& nums2) {
        if (ind1 >=  n1 || ind2 >= n2) {
            return 0;
        }
        int &ret = dp[ind1][ind2];
        if (ret != -1) return ret;
        ret = 0;
        ret = solve(ind1 + 1, ind2, nums1, nums2);
        ret = max(ret, solve(ind1, ind2 + 1, nums1, nums2));
        ret = max(ret, nums1[ind1] * nums2[ind2] + solve(ind1 + 1, ind2 + 1, nums1, nums2));
        
        return ret;
    }
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        n1 = nums1.size();
        n2 = nums2.size();
        dp.clear();
        dp.resize(n1, vector<int>(n2, -1));
        int ret = solve(0, 0, nums1, nums2);
        if (ret != 0) return ret;
        int mn = INT_MAX, mx = INT_MIN;
        for (auto &num : nums1) {
            mn = min(mn, num);
            mx = max(mx, num);
        }
        int mn1 = INT_MAX, mx1 = INT_MIN;
        for (auto &num : nums2) {
            mn1 = min(mn1, num);
            mx1 = max(mx1, num);
        }
        return max(mn*mx1, mn1*mx);
        
    }
private:
    int n1, n2;
    vector<vector<int>> dp;
};