class Solution {
    
    public HashSet<Integer> factorize(int num) {
        HashSet<Integer> factorList = new HashSet<>();
        for (int i = 2; i <= Math.sqrt(num); i++) {
            if ((num % i) == 0) {
                factorList.add(i);
                while (num%i == 0) {
                    num /= i;
                }
            }
        }
        if (num > 1) {
            factorList.add(num);
        }
        return factorList;
    }
    
    public void dfs(int num, HashMap<Integer, HashSet<Integer>> adj, boolean[] visited) {
        if (visited[num]) return;
        visited[num] = true;
        for (int v : adj.get(num)) {
            dfs(v, adj, visited);
        }
    }
    
    public boolean canTraverseAllPairs(int[] nums) {
        if (nums.length <= 1) return true;
        HashMap<Integer, HashSet<Integer>> adj = new HashMap<>();
        HashSet<Integer> map = new HashSet<>();
        for (int i = 0; i < nums.length; i++) {
            int num = nums[i];
            if (num == 1) return false;
            HashSet<Integer> factors = factorize(num);
            Integer pre = null;
            for (Integer cur : factors) {
                map.add(cur);
                if (pre == null) {
                    pre = cur;
                    HashSet<Integer> list = adj.getOrDefault(pre, new HashSet<>());
                    list.add(cur);
                    adj.put(pre, list);
                    continue;
                }
                HashSet<Integer> list = adj.getOrDefault(pre, new HashSet<>());
                list.add(cur);
                adj.put(pre, list);
                
                HashSet<Integer> list1 = adj.getOrDefault(cur, new HashSet<>());
                list1.add(pre);
                adj.put(cur, list1);
                
                pre = cur;
            }
        }
        
        boolean done = false;
        boolean[] visited = new boolean[100001];
        for (int i : map) {
            if (adj.get(i) != null) {
                dfs(i, adj, visited);
                break;
            }
        }
        for (int i : map) {
            if (!visited[i]) return false;
        }
        return true;
    }
}