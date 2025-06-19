class Solution {
public:
    int numTriplets(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        unordered_map<long long, int> cnt1, cnt2;
        for (int i = 0; i < n1; i++) {
            long long sq = (long long)nums1[i]* nums1[i];
            cnt1[sq]++;
        }
        for (int i = 0; i < n2; i++) {
            long long sq = (long long)nums2[i]* nums2[i];
            cnt2[sq]++;
        }
        int res = 0;
        for (int i = 0; i < n1; i++) {
            for (int j = i + 1; j < n1; j++) {
                long long mul = (long long)nums1[i] * nums1[j];
                res += cnt2[mul];
            }
        }
        for (int i = 0; i < n2; i++) {
            for (int j = i + 1; j < n2; j++) {
                long long mul = (long long)nums2[i] * nums2[j];
                res += cnt1[mul];
            }
        }
        return res;
    }
};