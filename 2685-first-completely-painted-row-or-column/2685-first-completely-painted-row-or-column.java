class Solution {
    public int firstCompleteIndex(int[] arr, int[][] mat) {
        HashMap<Integer, Pair<Integer, Integer>> hashmap = new HashMap<>();
        int n = mat.length;
        int m = mat[0].length;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                hashmap.put(mat[i][j], new Pair(i, j));
            }
        }
        int[] rowCounter = new int[n];
        int[] colCounter = new int[m];
        for (int i = 0; i < n*m; i++) {
            Pair<Integer, Integer> p = hashmap.get(arr[i]);
            int r = p.getKey();
            int c = p.getValue();
            rowCounter[r]++;
            colCounter[c]++;
            if (rowCounter[r] == m || colCounter[c] == n) return i;
        }
        return -1;
    }
}