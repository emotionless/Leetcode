class Solution {
    public int maxScore(String s) {
        int len = s.length();
        int oneCounter = 0;
        for (int i = 0; i < len; i++) {
            oneCounter += (s.charAt(i) == '1'? 1 : 0);
        }
        int zeroCounter = 0;
        int ans = 0;
        for (int i = 0; i < len - 1; i++) {
            if (s.charAt(i) == '0') {
                zeroCounter += 1;
            } else {
                oneCounter -= 1;
            }
            ans = Math.max(ans, zeroCounter + oneCounter);
        }
        return ans;
    }
}