class Solution {
    static class Node implements Comparable<Node> {
        int x, y, cost, sec;
        public Node(int a, int b, int c, int d) {
            x = a;
            y = b;
            cost = c;
            sec = d;
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
        boolean[][][] visited = new boolean[n][m][3];
        PriorityQueue<Node> pq = new PriorityQueue<>();
        pq.offer(new Node(0, 0, 0, 0));

        while (!pq.isEmpty()) {
            Node top = pq.poll();
            int x = top.x;
            int y = top.y;
            int cost = top.cost;
            int sec = top.sec;
            if (visited[x][y][sec]) continue;
            else if (x == (n-1) && y == (m-1)) return cost;
            visited[x][y][sec] = true;
            for (int i = 0; i < 4; i++) {
                int ax = x + dr[i];
                int ay = y + dc[i];
                int as = sec%2 + 1;
                if (ax < 0 || ax >= n || ay < 0 || ay >= m || visited[ax][ay][as] == true) continue;
                pq.offer(new Node(ax, ay, Math.max(cost + as, as + moveTime[ax][ay]), as));
            }
        }
        return -1;
    }
}