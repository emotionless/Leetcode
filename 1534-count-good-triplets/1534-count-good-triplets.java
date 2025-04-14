class Solution {
    public int countGoodTriplets(int[] arr, int a, int b, int c) {
        int n = arr.length;
        int ans = 0;
        for (int i = 0; i < n; i++){
            int num = arr[i];
            for (int j = 0; j < i; j++) {
                for (int k = i + 1; k < n; k++) {
                    if (Math.abs(arr[i] - arr[j]) <= a && Math.abs(arr[i] - arr[k]) <= b && Math.abs(arr[k] - arr[j]) <= c) {
                        ans++;
                    }
                }
            }
        }
        return ans;
    }
}