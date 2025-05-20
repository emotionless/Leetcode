class Solution {
    public boolean isZeroArray(int[] nums, int[][] queries) {
        int n = nums.length;
        int[] counter = new int[n];
        Arrays.fill(counter, 0);
        for (int[] query :  queries) {
            int  l = query[0];
            int r = query[1];
            counter[l] += 1;
            if (r < (n-1)) {
                counter[r+1] -= 1;
            }
        }
        int sum = 0;
        for (int i = 0; i < n; i++) {

            // System.out.println(counter[i]);
            sum  += counter[i];
            // System.out.println(sum);
            if (sum < nums[i]) return false;
        }
        return  true;
    }
}