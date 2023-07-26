class Solution {
public:
    int maxNonDecreasingLength(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int a0 = 1, b0 = 1;
        int ans = 1;
        for (int i = n - 2; i >= 0; i--) {
            int a1 = 1, b1 = 1;
            if (nums2[i + 1] >= nums1[i]) a1 = max(a1, 1 + b0);
            if (nums1[i + 1] >= nums1[i]) a1 = max(a1, 1 + a0);
            
            if (nums2[i + 1] >= nums2[i]) b1 = max(b1, 1 + b0);
            if (nums1[i + 1] >= nums2[i]) b1 = max(b1, 1 + a0);
            
            ans = max(a1, ans);
            ans = max(b1, ans);
            a0 = a1, b0 = b1;
        }
        return ans;
    }
};