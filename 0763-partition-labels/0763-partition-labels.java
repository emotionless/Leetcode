class Solution {
    public List<Integer> partitionLabels(String s) {
        HashMap<Character, Integer> map = new HashMap<>();
        for (int i = 0; i < s.length(); i++) {
            map.put(s.charAt(i), i);
        }
        int cnt = 0;
        List<Integer> ans = new ArrayList<>();
        int mx = 0;
        for (int i = 0; i < s.length(); i++) {
            cnt++;
            mx = Math.max(mx, map.get(s.charAt(i)));
            if (mx == i) {
                ans.add(cnt);
                cnt = 0;
                mx = 0;
            }
        }
        return ans;
    }
}