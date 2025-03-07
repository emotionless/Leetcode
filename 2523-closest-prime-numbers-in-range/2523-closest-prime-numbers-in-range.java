class Solution {
    boolean isPrime(int num, boolean[] prime) {
        return prime[num] == false;
    }
    public int[] closestPrimes(int left, int right) {
        boolean[] prime = new boolean[right + 1];
        prime[1] = true;
        for (int i = 2; i <= right; i++) {
            if (prime[i] == true) continue;
            for (int j = i + i; j <= right; j+=i) {
                prime[j] = true;
            }
        }
        int pre = -1;
        int first = -1, second = -1;
        int ans = right + 1;
        for (int i = left; i <= right; i++) {
            if (isPrime(i, prime)) {
                if (pre != -1) {
                    if ((i - pre) < ans) {
                        ans = i - pre;
                        first = pre;
                        second = i;
                    }
                }
                pre = i;
            }
        }
        return new int[] {first, second};
    }
}