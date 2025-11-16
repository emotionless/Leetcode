class Solution {
public:
    const int MOD = 1e9 + 7;
    int numSub(string s) {
        int l = s.length();
        int ans = 0;
        long long cnt = 0;
        for (int i = 0; i < l; i++) {
            if (s[i] == '0') {
                ans = (ans + (cnt * (cnt + 1ll) / 2ll)) % MOD;
                cnt = 0;
            } else {
                cnt++;
            }
        }
        ans = (ans + (cnt * (cnt + 1ll) / 2ll)) % MOD;
        return ans;
    }
};