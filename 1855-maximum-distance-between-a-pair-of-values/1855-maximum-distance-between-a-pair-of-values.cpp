class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();

        int  ans = 0;
        int j = 0;
        for (int i = 0; i < n;  i++) {
            while(j<m && nums1[i] <=  nums2[j]) {
                ans = max(ans, (j - i));
                j++;
            }
        }
        return  ans;
    }
};