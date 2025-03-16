class Solution {
    long carRepaired(long tar, int[] ranks) {
        int n = ranks.length;
        long tot = 0;
        for (int rank : ranks) {
            long div = tar / rank;
            long sq = (long)Math.sqrt(div);
            tot += sq;
        }
        return tot;
    }
    public long repairCars(int[] ranks, int cars) {
        long st = 1, ed = (long)cars*cars *101L;
        long ans = ed;
        while (st <= ed) {
            long mid = (st + ed) / 2;
            long tot = carRepaired(mid, ranks);
            // System.out.println(mid + " " + tot);
            if (tot >= cars) {
                ans = mid;
                ed = mid - 1;
            } else {
                st = mid + 1;
            }
        }
        return ans;
    }
}