class Solution {
public:
    
    int maximumsSplicedArray(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int sum1 = accumulate(nums1.begin(), nums1.end(), 0);
        int sum2 = accumulate(nums2.begin(), nums2.end(), 0);
        int ans = max(sum1, sum2);
        int sum = 0;
        int cur = 0;
        for (int i = 0; i < n; i++) {
            int num = (nums1[i] - nums2[i]);
            sum += num;
            if (sum < 0) sum = 0;
            cur = max(cur, sum);
        }
        ans = max(ans, sum2 + cur);
        sum = 0;
        cur = 0;
        for (int i = 0; i < n; i++) {
            int num = (nums2[i] - nums1[i]);
            sum += num;
            if (sum < 0) sum = 0;
            cur = max(cur, sum);
        }
        ans = max(ans, sum1 + cur);
        
        return ans;
    }
};