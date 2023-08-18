class Solution {
    public int maximalNetworkRank(int n, int[][] roads) {
        int[][] isConnected = new int[n][n];
        int[] cnt = new int[n];
        for (int i = 0; i < n; i++) {
            cnt[i] = 0;
            for (int j = 0; j < n; j++) {
                isConnected[i][j] = 0;
            }
        }
        
        for (int i = 0; i < roads.length; i++) {
            isConnected[roads[i][0]][roads[i][1]] = 1;
            isConnected[roads[i][1]][roads[i][0]] = 1;
            cnt[roads[i][0]]++;
            cnt[roads[i][1]]++;
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                ans = Math.max(ans, cnt[i] + cnt[j] - isConnected[i][j]);
            }
        }
        return ans;
    }
}