class Solution {
    public int countPalindromicSubsequence(String s) {
        boolean[] myHashSet = new boolean[2630];
        int[] counter = new int[26];
        int[] counter2 = new int[26];
        int len = s.length();
        
        for (int i = 0; i < len; i++) {
            counter[(int)(s.charAt(i) - 'a')]++;
        }
        for (int i = 0; i < len; i++) {
            counter[(int)(s.charAt(i) - 'a')]--;
            for (int j = 0; j < 26; j++) {
                if (counter2[j] != 0 && counter[j] != 0){
                    int num = j*100 + (s.charAt(i) - 'a');
                    myHashSet[num] = true;
                }
            }
            
            counter2[(int)(s.charAt(i) - 'a')]++;
        }
        int ans = 0;
        for (boolean i : myHashSet) {
            ans += i == true? 1:0;
        }
        return ans;
    }
}