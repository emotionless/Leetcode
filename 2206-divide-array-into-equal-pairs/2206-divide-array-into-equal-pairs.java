class Solution {
    public boolean divideArray(int[] nums) {
        boolean[] visited = new boolean[501];
        for (int num : nums) {
            visited[num] = !visited[num];
        }
        for (int num : nums) {
            if (visited[num]) {
                return false;
            }
        }
        return true;
    }
}

/**
2 4 5 3
 10
100
101
011

 */