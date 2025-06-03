class Solution {
    public int maxCandies(int[] status, int[] candies, int[][] keys, int[][] containedBoxes, int[] initialBoxes) {
        int n = status.length;
        Queue<Integer> pq = new LinkedList<>();
        int[] copy = status.clone();
        boolean[] seen = new boolean[n];
        boolean[] visited = new boolean[n];
        for (int box : initialBoxes) {
            if (status[box] == 1) {
                pq.add(box);
            } else {
                seen[box] = true;
            }
        }
        while (!pq.isEmpty()) {
            Integer top = pq.poll();
            int cur = top;
            // System.out.println(top);
            if (visited[cur] == true) continue;
            visited[cur] = true;
            for (int key : keys[cur]) {
                copy[key] = 1;
                if (seen[key]) {
                    pq.offer(key);
                }
            }
            for (int box : containedBoxes[cur]) {
                if (copy[box] == 1) {
                    pq.offer(box);
                } else {
                    seen[box] = true;
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (visited[i]) {
                ans += candies[i];
            }
        }
        return ans;
    }
}