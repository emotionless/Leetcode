class Solution {

    long  bigMod(long a, long b, long mod) {
        long ans = 1L;
        a %= mod;
        while (b > 0) {
            if (b%2==1) {
                ans = (ans * a) % mod;
            }
            b = b / 2;
            a = (a * a) % mod;
        }
        return ans;
    }

    public int countGoodNumbers(long n) {
        long mod = 1000000007L;
        // System.out.println(bigMod(5, 3, mod));
        return (int)((bigMod(5L, (n+1)/2L, mod) * bigMod(4L, n/2L, mod)) % mod);
    }
}

/**

 */