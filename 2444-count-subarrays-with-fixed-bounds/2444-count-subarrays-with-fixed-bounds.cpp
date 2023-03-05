class Solution {
public:
    
    bool outOfRange(int k) {
        if (k < mn || k > mx) return true;
        return false;
    }
    
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int n = nums.size();
        mn = minK;
        mx = maxK;
        int start = n, last = n, first = n;
        long long ans = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (outOfRange(nums[i])) {
                start = i;
                last = i;
                first = i;
                continue;
            }
            if (maxK == nums[i]) {
                last = i;
            }
            if (minK == nums[i]) {
                first = i;
            }
            ans += (start - max(first, last));
        }
        return ans;
    }
private:
    int mn, mx;
};