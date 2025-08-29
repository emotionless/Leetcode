class Solution {
public:
    long long flowerGame(int n, int m) {
        if (n > m) swap(n, m);
        long long ans = 0;
        long long odd = (m + 1ll) / 2ll;
        long long even = m / 2ll;
        return (n+1ll)/2ll * even + (n/2ll) * odd;
    }
};