class Solution {
    public int minimumRecolors(String blocks, int k) {
        int cnt = 0;
        for (int i = 0; i < k - 1; i++) {
            if (blocks.charAt(i) == 'W') cnt++;
        }
        int i = k - 1;
        int ans = k;
        for (int j = 0; i < blocks.length(); j++, i++) {
            if (blocks.charAt(i) == 'W') cnt++;
            ans = Math.min(ans, cnt);
            if (blocks.charAt(j) == 'W') cnt--;
        }
        return ans;
    }
}