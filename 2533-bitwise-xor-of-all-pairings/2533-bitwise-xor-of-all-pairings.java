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
        int n1 = nums1.length;
        int n2 = nums2.length;
        int ans = 0;
        if (n1%2==1) ans ^= xorOfArray(nums2);
        if (n2%2==1) ans ^= xorOfArray(nums1);
        return ans;
    }
}