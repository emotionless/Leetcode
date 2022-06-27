class Solution {
public:
    
    int getMaxSum(const vector<int> &arr1, const vector<int> &arr2) {
        int n = arr1.size();
        int sum = 0;
        int mx = 0;
        for (int i = 0; i < n; i++) {
            sum += arr1[i] - arr2[i];
            if (sum < 0) sum = 0;
            mx = max(mx, sum);
        }
        return mx;
    }
    
    int maximumsSplicedArray(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int sum1 = accumulate(nums1.begin(), nums1.end(), 0);
        int sum2 = accumulate(nums2.begin(), nums2.end(), 0);
        int ans = max(sum1, sum2);
        ans = max(ans, sum2 + getMaxSum(nums1, nums2));
        ans = max(ans, sum1 + getMaxSum(nums2, nums1));
        
        return ans;
    }
};