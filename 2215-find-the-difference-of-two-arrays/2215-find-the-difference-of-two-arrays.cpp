class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        
        int j = 0;
        int i = 0;
        int len1 = nums1.size();
        int len2 = nums2.size();
        vector<int> first, second;
        while (i < len1 || j < len2) {
            if (i && i < len1 && nums1[i] == nums1[i-1]) {
                i++;
                continue;
            }
            if (j && j < len2 && nums2[j] == nums2[j-1]) {
                j++;
                continue;
            }
            if (j == len2) {
                first.push_back(nums1[i++]);
            } else if (i == len1) {
                second.push_back(nums2[j++]);
            } else {
                if (nums1[i] == nums2[j]) {
                    i++;
                    j++;
                } else if (nums1[i] < nums2[j]) {
                    first.push_back(nums1[i++]);
                } else {
                    second.push_back(nums2[j++]);
                }
            }
        }
        return {first, second};
    }
};