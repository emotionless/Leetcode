class Solution {
    public boolean areAlmostEqual(String s1, String s2) {
        int cnt = 0;
        int pos1 = -1;
        int pos2 = -1;
        for (int i = 0; i < s1.length(); i++) {

            if (s1.charAt(i) != s2.charAt(i)) {
                cnt++;
                if (cnt > 2) return false;
                if (pos1 == -1) pos1 = i;
                else pos2 = i;
            }
        }
        if (cnt == 0) return true;
        else if (cnt == 1) return false;
        
        if (s1.charAt(pos1) == s2.charAt(pos2) && s1.charAt(pos2) == s2.charAt(pos1)) return true;
        return false;
    }
}