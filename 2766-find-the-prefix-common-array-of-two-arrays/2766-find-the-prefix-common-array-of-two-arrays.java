class Solution {
    public int[] findThePrefixCommonArray(int[] A, int[] B) {
        int n = A.length;
        int[] count = new int[n + 1];
        int ans = 0;
        int[] res = new int[n];
        for (int i = 0; i < n; i++) {
            count[A[i]]++;
            count[B[i]]++;
            if (A[i] == B[i]) {
                ans++;
            } else {
                if (count[A[i]] == 2) {
                    ans++;
                } 
                if (count[B[i]] == 2) {
                    ans++;
                }
            }
            res[i] = ans;
        }
        return res;
    }
}