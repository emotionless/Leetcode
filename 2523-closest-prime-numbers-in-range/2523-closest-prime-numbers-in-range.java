class Solution {
    boolean isPrime(int num) {
        if (num == 2) return true;
        else if (num % 2 == 0 || num == 1) return false;
        for (int i = 3; i*i <= num; i+=2) {
            if (num %i == 0) {
                return false;
            }
        }
        return true;
    }
    public int[] closestPrimes(int left, int right) {
        int pre = -1;
        int first = -1, second = -1;
        int ans = 1000000;
        for (int i = left; i <= right; i++) {
            if (isPrime(i)) {
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