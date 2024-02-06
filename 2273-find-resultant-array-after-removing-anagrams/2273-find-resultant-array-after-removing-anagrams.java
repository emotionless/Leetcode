class Solution {
    public List<String> removeAnagrams(String[] words) {
        int length = words.length;
        List<String> removedAnagrams = new ArrayList<>();
        for (int i = 0; i < length; i++) {
            int j = i;
            for (j = i + 1; j < length; j++) {
                if (isAnagram(words[i], words[j])) {
                    continue;
                } else {
                    break;
                }
            }
            removedAnagrams.add(words[i]);
            i = j - 1;
        }
        return removedAnagrams;
    }
    
    private boolean isAnagram(String word1, String word2) {
        String sorted1 = getSorted(word1);
        String sorted2 = getSorted(word2);
        return sorted1.equals(sorted2);
    }
    
    private String getSorted(String word) {
        char[] ar = word.toCharArray();
        Arrays.sort(ar);
        return String.valueOf(ar);
    }
}