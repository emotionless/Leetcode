class Solution {
    public long distributeCandies(int n, int limit) {
       long ans = 0;
        for (int i = 0; i <= Math.min(limit, n); i++) {
            int remaining = n - i;
            if (remaining > limit*2) {
                continue;
            }
            int mn = Math.max(0, remaining - limit);
            ans += Math.max(0, Math.min(limit, remaining) - mn) + 1;
        }
        return ans;
    }
}