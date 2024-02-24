class Solution {
    public List<Integer> findAllPeople(int n, int[][] meetings, int firstPerson) {
        HashMap<Integer, ArrayList<Pair<Integer, Integer>>> adj = new HashMap<>();
        for (int i = 0; i < meetings.length; i++) {
            ArrayList<Pair<Integer, Integer>> list = adj.getOrDefault(meetings[i][0], new ArrayList<>());
            list.add(new Pair(meetings[i][1], meetings[i][2]));
            adj.put(meetings[i][0], list);
            ArrayList<Pair<Integer, Integer>> list1 = adj.getOrDefault(meetings[i][1], new ArrayList<>());
            list1.add(new Pair(meetings[i][0], meetings[i][2]));
            adj.put(meetings[i][1], list1);
        }
        
        PriorityQueue<Pair<Integer, Integer>> pq = new PriorityQueue<>((a, b) -> a.getValue() - b.getValue());
        pq.add(new Pair<>(0, 0));
        pq.add(new Pair<>(firstPerson, 0));
        Set<Integer> ans = new HashSet<>();
        while (pq.size() > 0) {
            Pair<Integer, Integer> top = pq.poll();
            if (ans.contains(top.getKey())) {
                continue;
            }
            ans.add(top.getKey());
            
            for (Pair<Integer, Integer> v : adj.getOrDefault(top.getKey(), new ArrayList<>())) {
                // System.out.println(v.getKey() + " " + v.getValue());
                if (v.getValue() >= top.getValue()) {
                    pq.add(new Pair<>(v.getKey(), v.getValue()));
                }
            }
        }
        
        ans.add(0);
        
        return List.copyOf(ans);
    }
}