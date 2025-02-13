class Solution {
    public int minOperations(int[] nums, int k) {
        PriorityQueue<Long> pq = new PriorityQueue<>();
        for (int num : nums) {
            pq.add(Long.valueOf(num));
        }
        int counter = 0;
        while (pq.size() > 1 && pq.peek() < k) {
            Long top1 = pq.poll();
            Long top2 = pq.poll();
            pq.add(Math.min(top1, top2)*2L + Math.max(top1, top2));
            counter++;
        }
        return counter;
    }
}