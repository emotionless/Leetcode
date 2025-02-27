class Solution {
    public int minOperations(int n) {
        String numStr = Integer.toBinaryString(n);
        int len = numStr.length();
        boolean found = false;
        int zero = 0, one = 0;
        int ans = 0;
        for (int i = len - 1; i >= 0; i--) {
            if (numStr.charAt(i) == '0') {
                if (i > 0 && numStr.charAt(i - 1) == '0') {
                    ans += Math.min(2, one);
                    one = 0;
                } else {
                    if (one > 1) {
                        ans ++;
                        one = 1;
                    } else {
                        ans += Math.min(1, one);
                        one = 0;
                    }
                }
            } else {
                one++;
            }
            // System.out.println(i + " " + zero + " " + one + " " + ans);
        }
        if (one > 0) ans += Math.min(2, one);
        return ans;
    }
}

/**

110110
100111
101010101

100110

5 1 0 0
4 0 1 0
3 0 2 0
2 0 1 1
1 0 2 1
0 0 3 1

1010100

 */