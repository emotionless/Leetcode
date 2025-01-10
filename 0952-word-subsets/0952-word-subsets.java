class Solution {

    int[] characterCount(String word) {
        int[] counter = new int[26];
        for (int i = 0; i < word.length(); i++) {
            counter[word.charAt(i) - 'a']++;
        }
        return counter;
    }

    public List<String> wordSubsets(String[] words1, String[] words2) {
        List<String> ans = new ArrayList<>();
        int n1 = words1.length;
        int[] mx = new int[26];
  
        for (String word : words2) {
            int[] counter2 = characterCount(word);
            for (int i = 0; i < 26; i++) {
                mx[i] = Math.max(mx[i], counter2[i]);
            }
        }
        for (String word : words1) {
            int[] counter1 = characterCount(word);
            boolean check = false;
            for (int i = 0; i < 26; i++) {
                if (mx[i] > counter1[i]) {
                    check = true;
                    break;
                }
            }
            if (!check) {
                ans.add(word);
            }
        }
        return ans;
    }
}