class Solution {
public:
    
    int binarySearch(int ind1, int ind2, const vector<int> &nums1, const vector<int> nums2, int k) {
        if (ind1 == nums1.size()) {
            return nums2[ind2 + k - 1];
        } else if (ind2 == nums2.size()) {
            return nums1[ind1 + k - 1];
        }
        if (k == 1) {
            return min(nums1[ind1], nums2[ind2]);
        }
        int half = k / 2 - 1;
        int val1 = INT_MAX;
        int val2 = INT_MAX;
        if (ind1 + half < nums1.size()) {
            val1 = nums1[ind1 + half];
        }
        if (ind2 + half < nums2.size()) {
            val2 = nums2[ind2 + half];
        }
        if (val1 < val2) {
            return binarySearch(ind1 + half + 1, ind2, nums1, nums2, k - k/2);
        } else {
            return binarySearch(ind1, ind2 + half + 1, nums1, nums2, k - k/2);
        }
    }
    
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        int mid = (n1 + n2) / 2 + 1;
        if ((n1 + n2) % 2) {
            return binarySearch(0, 0, nums1, nums2, mid);
        } else {
            return (binarySearch(0, 0, nums1, nums2, mid) + binarySearch(0, 0, nums1, nums2, mid - 1))/2.0 ;
        }
    }
};