class Solution {
    public int countPalindromicSubsequence(String s) {
        HashSet<Integer> myHashSet = new HashSet<Integer>();
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
                    int num = j*10000 + (s.charAt(i) - 'a')*100 + j;
                    myHashSet.add(num);
                }
            }
            
            counter2[(int)(s.charAt(i) - 'a')]++;
        }
        return myHashSet.size();
    }
}