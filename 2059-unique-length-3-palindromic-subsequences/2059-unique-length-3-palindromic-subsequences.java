class Solution {
    public int countPalindromicSubsequence(String s) {
        int[] myHashSet = new int[2630];
        int[] counter = new int[26];
        int[] counter2 = new int[26];
        int len = s.length();
        for (int i = 0; i < 26; i++) {
            counter[i] = counter2[i] = 0;
        }
        for (int i = 0; i < len; i++) {
            counter[(int)(s.charAt(i) - 'a')]++;
        }
        for (int i = 0; i < len; i++) {
            counter[(int)(s.charAt(i) - 'a')]--;
            for (int j = 0; j < 26; j++) {
                if (counter2[j] != 0 && counter[j] != 0){
                    int num = j*100 + (s.charAt(i) - 'a');
                    myHashSet[num] = 1;
                }
            }
            
            counter2[(int)(s.charAt(i) - 'a')]++;
        }
        int ans = 0;
        for (int i : myHashSet) {
            ans += i;
        }
        return ans;
    }
}