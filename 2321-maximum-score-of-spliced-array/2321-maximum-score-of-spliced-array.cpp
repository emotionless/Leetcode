class Solution {
public:
    
    int getMaxSum(const vector<int> &arr) {
        int n = arr.size();
        int sum = 0;
        int mx = 0;
        for (auto &num : arr) {
            sum += num;
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
        vector<int> arr;
        for (int i = 0; i < n; i++) {
            arr.push_back(nums1[i] - nums2[i]);
        }
        ans = max(ans, sum2 + getMaxSum(arr));
        arr.clear();
        for (int i = 0; i < n; i++) {
            arr.push_back(nums2[i] - nums1[i]);
        }
        ans = max(ans, sum1 + getMaxSum(arr));
        
        return ans;
    }
};