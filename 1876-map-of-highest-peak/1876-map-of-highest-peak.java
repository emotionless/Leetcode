class Solution {
    int[] dr = new int[]{0, 1, 0, -1};
    int[] dc = new int[]{1, 0, -1, 0};
    
    public int[][] highestPeak(int[][] isWater) {
        Queue<Node> queue = new LinkedList<>();
        int n = isWater.length;
        int m = isWater[0].length;
        boolean[][] visited = new boolean[n][m];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (isWater[i][j] == 1) {
                    queue.add(new Node(i, j, 0));
                    visited[i][j] = true;
                }
            }
        }
        int[][] ans = new int[n][m];
        while (queue.size() > 0) {
            Node node = queue.remove();
            ans[node.getR()][node.getC()] = node.getCost();
            for (int i = 0; i < 4; i++) {
                int ar = node.getR() + dr[i];
                int ac = node.getC() + dc[i];
                if (ar < 0 || ar >= n || ac < 0 || ac >= m) continue;
                if (visited[ar][ac]) continue;
                queue.add(new Node(ar, ac, node.getCost() + 1));
                visited[ar][ac] = true;
            }
        }
        return ans;
    }

    class Node {
        int r, c, cost;
        public Node(int a, int b, int x) {
            r = a;
            c = b;
            cost = x;
        }
        int getR() {
            return r;
        }
        int getC() {
            return c;
        }
        int getCost() {
            return cost;
        }
    }
}