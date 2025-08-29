class Solution {
public:
    long long flowerGame(int n, int m) {
        if (n > m) swap(n, m);
        long long ans = 0;
        for (int i = 1; i <= n; i++) {
            long long odd = (m + 1ll) / 2ll;
            long long even = m / 2ll;
            if (i&1) {
                ans += even;
            } else {
                ans += odd;
            }
        }
        return ans;
    }
};