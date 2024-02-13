class Solution {
    public boolean isPalindrome(String s) {
        int j = s.length() - 1;
        for (int i = 0; i <= j;) {
            if (!isAlphanumeric(s.charAt(i))) {
                i++;
                continue;
            } else if (!isAlphanumeric(s.charAt(j))) {
                j--;
                continue;
            }
            char ch1 = Character.toLowerCase(s.charAt(i));
            char ch2 = Character.toLowerCase(s.charAt(j));
            // System.out.println(ch1 + " -> " + ch2);
            if (ch1 != ch2) {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    
    boolean isAlphanumeric(char ch) {
        if (ch >= 'a' && ch <= 'z')  return true;
        else if (ch >= 'A' && ch <= 'Z') return true;
        else if (ch >= '0' && ch <= '9') return true;
        else return false;
    }
}