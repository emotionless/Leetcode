class Solution {
    int dfs(int cur, int[] visited, int[][] graph) {
        if (visited[cur] != 0) return visited[cur];
        if (graph[cur].length == 0) return visited[cur] = 1;
        boolean allOkay = true;
        visited[cur] = -1;
        for (int i = 0; i < graph[cur].length; i++) {
            if (dfs(graph[cur][i], visited, graph) == -1) {
                allOkay = false;
                break;
            }
        }
        if (allOkay) visited[cur] = 1;
        else visited[cur] = -1;
        return visited[cur];
    }
    public List<Integer> eventualSafeNodes(int[][] graph) {
        int n = graph.length;
        int[] visited = new int[n];
        List<Integer> ans = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            if (dfs(i, visited, graph) == 1) {
                ans.add(i);
            }
        }
        return ans;
    }
}