class Solution {
    boolean isPrime(int num, int[] prime) {
        return prime[num] == 0;
    }
    public int[] closestPrimes(int left, int right) {
        int[] prime = new int[right + 1];
        prime[1] = 1;
        for (int i = 2; i <= right; i++) {
            if (prime[i] == 1) continue;
            for (int j = i + i; j <= right; j+=i) {
                prime[j] = 1;
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