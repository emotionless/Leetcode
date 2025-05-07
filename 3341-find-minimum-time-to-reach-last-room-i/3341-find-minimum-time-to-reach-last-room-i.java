class Solution {
    static class Node implements Comparable<Node> {
        int x, y, cost;
        public Node(int a, int b, int c) {
            x = a;
            y = b;
            cost = c;
        }

        public int compareTo(Node other) {
            return Integer.compare(this.cost, other.cost);
        }
    }
    int[] dr = new int[] {-1, 0, 1, 0};
    int[] dc = new int[] {0, 1, 0, -1};

    public int minTimeToReach(int[][] moveTime) {
        int n = moveTime.length;
        int m = moveTime[0].length;
        boolean[][] visited = new boolean[n][m];
        PriorityQueue<Node> pq = new PriorityQueue<>();
        pq.offer(new Node(0, 0, moveTime[0][0]));

        while (!pq.isEmpty()) {
            Node top = pq.poll();
            int x = top.x;
            int y = top.y;
            int cost = top.cost;
            if (visited[x][y]) continue;
            else if (x == (n-1) && y == (m-1)) return cost;
            visited[x][y] = true;
            for (int i = 0; i < 4; i++) {
                int ax = x + dr[i];
                int ay = y + dc[i];
                if (ax < 0 || ax >= n || ay < 0 || ay >= m || visited[ax][ay] == true) continue;
                pq.offer(new Node(ax, ay, Math.max(cost + 1, 1 + moveTime[ax][ay])));
            }
        }
        return -1;
    }
}