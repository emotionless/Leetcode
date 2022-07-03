class Solution {
public:
    const int MOD = 1e9 + 7;
    int peopleAwareOfSecret(int n, int delay, int forget) {
        vector<long long> knows(n + 1, 0);
        long long total = 0;
        knows[1] = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = i + delay; j < i + forget && j <= n; j++) {
                knows[j] = (knows[j] + knows[i]) % MOD;
            }
            // cout << i << endl;
            total = (total + knows[i]) % MOD;
            if (i > forget)
                total = (total - knows[i - forget]) % MOD;
            total = (total + MOD) % MOD;
        }
        return total;
    }
};