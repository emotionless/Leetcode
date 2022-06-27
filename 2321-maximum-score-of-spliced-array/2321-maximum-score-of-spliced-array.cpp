class Solution {
public:
    
    int maximumsSplicedArray(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int num1Sum = 0;
        int num2Sum = 0;
        int ans = max(num1Sum, num2Sum);
        int sum1 = 0, sum2 = 0;
        int cur1 = 0, cur2 = 0;
        for (int i = 0; i < n; i++) {
            num1Sum += nums1[i];
            num2Sum += nums2[i];
            sum1 += (nums1[i] - nums2[i]);
            sum2 += (nums2[i] - nums1[i]);
            if (sum1 < 0) sum1 = 0;
            if (sum2 < 0) sum2 = 0;
            cur1 = max(cur1, sum1);
            cur2 = max(cur2, sum2);
        }
        ans = max(ans, max(num1Sum + cur2, num2Sum + cur1));
        return ans;
    }
};