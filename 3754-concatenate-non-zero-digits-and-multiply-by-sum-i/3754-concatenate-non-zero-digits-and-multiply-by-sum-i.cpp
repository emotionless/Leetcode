class Solution {
public:
    long long sumAndMultiply(int n) {
        long long sum = 0, mul = 1ll;
        long long dsum =  0;
        while (n > 0) {
            int d = n %10;
            dsum += d;
            if (d > 0) {
                sum += mul * d;
                mul *= 10;
            }
            n = n / 10;
        }
        return sum * dsum;
    }
};