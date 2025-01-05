class Solution {
    public String shiftingLetters(String s, int[][] shifts) {
        int n = s.length();
        int[] degree = new int[n];
        for (int[] shift : shifts) {
            int left = shift[0];
            int right = shift[1];
            int dir = shift[2];
            if (dir == 0) dir = -1;
            degree[left] += dir;
            if (right < n-1) {
                degree[right + 1] -= dir;
            }
        }
        char[] mys = s.toCharArray();
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += degree[i];
            sum = (sum%26 + 26) % 26;
            // System.out.println(sum + " " + degree[i]);
            mys[i] = (char)('a' + (mys[i] - 'a' + sum)%26);
        }
        return String.valueOf(mys);
    }
}