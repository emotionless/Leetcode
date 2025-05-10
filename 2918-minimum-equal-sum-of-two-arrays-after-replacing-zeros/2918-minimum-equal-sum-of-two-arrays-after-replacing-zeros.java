class Solution {
    public long minSum(int[] nums1, int[] nums2) {
        int n1 = nums1.length;
        int n2 = nums2.length;
        boolean isZero1 = false, isZero2 = false;
        long sum1 = 0;
        for (int num : nums1) {
            if (num == 0) {
                isZero1 = true;
                sum1 ++;
            }
            sum1 += num;
        }
        long sum2 = 0;
        for (int num : nums2) {
            if (num == 0) {
                isZero2 = true;
                sum2 ++;
            }
            sum2 += num;
        }
        if (sum1 == sum2) return sum1;
        else if (sum1 < sum2 && isZero1 == true) return sum2;
        else if (sum1 > sum2 && isZero2 == true) return sum1;
        else return -1;
    }
}