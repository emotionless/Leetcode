class Solution {
    public List<String> stringMatching(String[] words) {

        List<String> ans = new ArrayList<>();
        int n = words.length;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (words[j].contains(words[i]) && i != j) {
                    ans.add(words[i]);
                    break;
                }
            }
        }
        return ans;
    }
}