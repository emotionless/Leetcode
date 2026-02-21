class Solution {
public:
    int countPrimeSetBits(int left, int right) {
        int ans = 0;
        bool isPrime[32] = {false};
        isPrime[2] = isPrime[3] = isPrime[5] = isPrime[7] = isPrime[11] = isPrime[13] = isPrime[17] = isPrime[19] = isPrime[23] = isPrime[29] = true;
        for (int i = left; i <= right; i++) {
            int b = __builtin_popcount(i);
            if (isPrime[b] == true) ans++;
        }
        return ans;
    }
};