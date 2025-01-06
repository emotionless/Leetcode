class Solution {
    public int[] minOperations(String boxes) {
        int n = boxes.length();
        int rightSum = 0;
        int right = 0;
        for (int i = n - 1; i >= 0; i--) {
            rightSum += right;
            if (boxes.charAt(i) == '1') right++;
        }
        int left = 0;
        int leftSum = 0;
        int[] ans = new int[n];
        for (int i = 0; i < n; i++) {
            ans[i] = leftSum + rightSum;
            if (boxes.charAt(i) == '1') {
                left++;
                right--;
            }
            leftSum += left;
            rightSum -= right;
        }
        return ans;
    }
}