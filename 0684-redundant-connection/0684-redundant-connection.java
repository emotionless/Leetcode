class Solution {
    int find(int u, int[] par) {
        if (par[u] == u) return u;
        return par[u] = find(par[u], par);
    }
    public int[] findRedundantConnection(int[][] edges) {
        int n = edges.length;
        int[] par = new int[n + 1];
        for (int i = 0; i <= n; i++) {
            par[i] = i;
        }
        int ans = 0;
        for (int i = 0; i < edges.length; i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            int pu = find(u, par);
            int pv = find(v, par);
            if (pu == pv) {
                ans = i;
            } else {
                par[pu] = pv;
            }
        }
        return edges[ans];
    }
}