class Solution {
    
    private void backtrack(int cur, int n, int k, List<Integer> combination, List<List<Integer>> combinations) {
        if (k == 0) {
            combinations.add(new ArrayList<>(combination));
            return;
        }
        if (cur > n) return;
        backtrack(cur + 1, n, k, combination, combinations);
        if (k > 0) {
            combination.add(cur);
            backtrack(cur + 1, n, k - 1, combination, combinations);
            combination.remove(combination.size() - 1);
        }
    }
    
    public List<List<Integer>> combine(int n, int k) {
        List<List<Integer>> combinations = new ArrayList();
        List<Integer> combination = new ArrayList();
        backtrack(1, n, k, combination, combinations);
        
        return combinations;
    }
}