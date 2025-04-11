class Solution {
    boolean isSymmetric(String str) {
        int f = 0;
        int len = str.length();
        if (len%2==1) return false;
        for (int i = 0; i < len; i++) {
            if (i < len/2) f += (int)(str.charAt(i) - '0');
            else f -= (int)(str.charAt(i) - '0');
        }
        return f == 0;
    }

    public int countSymmetricIntegers(int low, int high) {
        int ans = 0;
        for (int i = low; i <= high; i++) {
            if (isSymmetric(String.valueOf(i))) {
                ans++;
            }
        }
        return ans;
    }
}