class Solution {
    public int[][] mergeArrays(int[][] nums1, int[][] nums2) {
        int n1 = nums1.length;
        int n2 = nums2.length;
        int i = 0, j = 0;
        int[][] ans = new int[n1+n2][2];
        int ind = 0;
        while (i < n1 && j < n2) {
            if (nums1[i][0] == nums2[j][0]) {
                ans[ind][0] = nums1[i][0];
                ans[ind][1] = nums1[i][1] + nums2[j][1];
                ind++;
                i++;
                j++;
            } else if (nums1[i][0] < nums2[j][0]) {
                ans[ind++] = nums1[i++];
            } else {
                ans[ind++] = nums2[j++];
            }
        }
        while (i < n1) {
            ans[ind++] = nums1[i++];
        }
        while (j < n2) {
            ans[ind++] = nums2[j++];
        }

        return Arrays.copyOf(ans, ind);
    }
}