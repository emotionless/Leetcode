class Solution {
    
    final int INF = 10000000;
    
    int solve(int cur, int tar, int n, int k, HashMap<Integer, ArrayList<Integer>> adj, int[][] dp, int[][] cost) {
        if (cur == tar) return 0;
        if (k < 0) return INF;
        int ret = dp[cur][k];
        if (ret != -1) return ret;
        ret = INF;
        if (adj.get(cur) == null) return ret;
        // System.out.println(cur);
        for (int v : adj.get(cur)) {
            ret = Math.min(ret, cost[cur][v] + solve(v, tar, n, k - 1, adj, dp, cost));
        }
        return dp[cur][k] = ret;
    }
    
    public int findCheapestPrice(int n, int[][] flights, int src, int dst, int k) {
        int[][] dp = new int[n][k+1];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= k; j++) {
                dp[i][j] = -1;
            }
        }
        int[][] cost = new int[n][n];
        HashMap<Integer, ArrayList<Integer>> adj = new HashMap<>();
        for (int i = 0; i < flights.length; i++) {
            for (int j = 0; j < 3; j++) {
                ArrayList<Integer> cur = adj.getOrDefault(flights[i][0], new ArrayList<>());
                cur.add(flights[i][1]);
                adj.put(flights[i][0], cur);
                cost [flights[i][0]] [flights[i][1]] = flights[i][2];
            }
        }
        int ans = solve(src, dst, n, k, adj, dp, cost);
        if (ans >= INF) return -1;
        return ans;
    }
}