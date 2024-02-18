class Solution {
    
    public class MyPair {
        int mx, ed, ind;
        
        public MyPair(int x, int y, int z) {
            mx = x;
            ed = y;
            ind = z;
        }
        
        public int getMx() {
            return mx;
        }
        
        public int getEd() {
            return ed;
        }
        
        public int getInd() {
            return ind;
        }
    }
    
    public int[] leftmostBuildingQueries(int[] heights, int[][] queries) {
        List<MyPair> list = new ArrayList<>();
        int[] ans = new int[queries.length];
        for (int i = 0; i < queries.length; i++) {
            ans[i] = -1;
        }
        for (int i = 0; i < queries.length; i++) {
            int mn = Math.min(queries[i][0], queries[i][1]);
            int mx = Math.max(queries[i][0], queries[i][1]);
            if (heights[mx] > heights[mn] || mn == mx) {
                ans[i] = mx;
            } else {
                list.add(new MyPair(Math.max(heights[mn], heights[mx]), mx, i));
            }
        }
        list.sort((o1, o2) -> Integer.valueOf(o1.getEd()).compareTo (Integer.valueOf(o2.getEd())));
        
        PriorityQueue<Pair<Integer, Integer>> pq = new PriorityQueue<>((a, b) -> a.getKey().compareTo(b.getKey()));
        int ind = 0;
        for (int i = 0; i < heights.length; i++) {
            while (ind < list.size() && list.get(ind).getEd() < i) {
                MyPair o1 = list.get(ind);
                pq.add(new Pair(o1.getMx(), o1.getInd()));
                ind++;
            }
            while (pq.size() > 0 && pq.peek().getKey() < heights[i]) {
                ans[pq.poll().getValue()] = i;
            }
        }
        
        return ans;
    }
}