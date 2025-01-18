class Solution {
    int[] dx = new int[]{0, 0, 1, -1};
    int[] dy = new int[]{1, -1, 0, 0};
    public int minCost(int[][] grid) {
        int n = grid.length;
        int m = grid[0].length;
        boolean[][] visited = new boolean[n][m];
        Comparator<node> customComparator = new Comparator<node>() {
            public int compare(node a, node b) {
                return Integer.compare(a.getC(), b.getC()); // Reverse order for max-heap behavior
            }
        };
        PriorityQueue<node> pq = new PriorityQueue<node>(customComparator);

        pq.add(new node(0, 0, 0));

        while (pq.size() > 0) {
            node cur = pq.poll();
            int x = cur.getX();
            int y = cur.getY();
            int c = cur.getC();
            if (x == (n-1) && y == (m - 1)) return c;
            if (visited[x][y] == true) continue;
            visited[x][y] = true;

            for (int i = 0; i < 4; i++) {
                int ax = x + dx[i];
                int ay = y + dy[i];
                int ac = c + (i != (grid[x][y] - 1)? 1 : 0);
                if (ax < 0 || ax >= n || ay < 0 || ay >= m) continue;
                if (!visited[ax][ay]) { 
                    pq.add(new node(ax, ay, ac));
                }
            }
        }
        return 0;
    }

    class node {
        int x, y, cost;
        public node (int a, int b, int c) {
            x = a;
            y = b;
            cost = c;
        }
        public int getX() { return x; }
        public int getY() { return y; }
        public int getC() { return cost; }
         
    }
}