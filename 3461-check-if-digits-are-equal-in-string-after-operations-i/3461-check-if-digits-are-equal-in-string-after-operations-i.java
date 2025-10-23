class Solution {

    String compute(String str) {
        StringBuilder newStr = new StringBuilder();
        for (int i = 0; i < str.length() - 1; i++) {
            int a = str.charAt(i) - 'a';
            int b = str.charAt(i + 1) - 'a';
            
            newStr.append((char)(('a' + (a + b) % 10)));
        }
        return newStr.toString();
    }

    public boolean hasSameDigits(String s) {
        while (s.length() > 2) {
            s = compute(s);
        }
        return s.charAt(0) == s.charAt(1);
    }
}