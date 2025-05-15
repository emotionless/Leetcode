class Solution {
    public List<String> getLongestSubsequence(String[] words, int[] groups) {
        List<String> ans = new ArrayList<>();
        int pre = -1;
        for (int i = 0; i < groups.length; i++) {
            int group = groups[i];
            if (group != pre) {
                ans.add(words[i]);
                pre = group;
            }
        }
        return ans;
    }
}