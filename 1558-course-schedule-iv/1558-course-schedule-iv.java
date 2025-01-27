class Solution {

    void dfs(int u, int v, ArrayList<Integer>[] adj, boolean[][] mat) {
        if (adj[u].size() == 0) {
            return;
        }
        for (int child : adj[u]) {
            if (mat[v][child] == false) {
                mat[v][child] = true;
                dfs(child, v, adj, mat);
            }
        }
    }

    public List<Boolean> checkIfPrerequisite(int numCourses, int[][] prerequisites, int[][] queries) {
        ArrayList<Integer>[]  pre = new ArrayList[numCourses];
        for (int i = 0; i < numCourses; i++) {
            pre[i] = new ArrayList<>();
        }
        for (int i = 0; i < prerequisites.length; i++) {
            pre[prerequisites[i][0]].add(prerequisites[i][1]);
        }
        boolean[][] mat = new boolean[numCourses][numCourses];
        for (int i = 0; i < numCourses; i++) {
            dfs(i, i, pre, mat);
        }
        List<Boolean> ans = new ArrayList<>();
        for (int[] child : queries) {
            if (mat[child[0]][child[1]] == true) {
                ans.add(true);
            } else {
                ans.add(false);
            }
        }
        return ans;
    }
}