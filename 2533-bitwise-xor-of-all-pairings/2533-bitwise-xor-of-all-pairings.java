class Solution {
    int xorOfArray(int[] num) {
        int n = num.length;
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum ^= num[i];
        }
        return sum;
    }
    public int xorAllNums(int[] nums1, int[] nums2) {
        int ans = 0;
        if (nums1.length%2==1) ans ^= xorOfArray(nums2);
        if (nums2.length%2==1) ans ^= xorOfArray(nums1);
        return ans;
    }
}