class Solution {
    public long maximumHappinessSum(int[] happiness, int k) {
        PriorityQueue<Integer> pq = new PriorityQueue<>(Collections.reverseOrder());
        for (int num : happiness) {
            pq.add(num);
        }
        int cnt = 0;
        long ans = 0;
        while (k > 0) {
            k--;
            ans += pq.poll() - cnt;
            cnt++;
        }
        return ans;
    }
}