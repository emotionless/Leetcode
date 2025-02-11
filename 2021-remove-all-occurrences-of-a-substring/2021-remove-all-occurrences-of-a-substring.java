class Solution {
    public String removeOccurrences(String s, String part) {
        while (s.indexOf(part) != -1) {
            s = s.replaceFirst(part, "");
        }
        return s;
    }
}