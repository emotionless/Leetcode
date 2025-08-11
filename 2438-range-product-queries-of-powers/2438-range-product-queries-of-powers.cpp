class Solution {
public:
    const long long MOD = 1e9 + 7;
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<int> container;
        for(int i =  0; i < 31; i++) {
            if (n&(1<<i)) {
                container.push_back(1<<i);
            }
        }
        int sz = container.size();
        vector<vector<int>> dp(sz, vector<int>(sz, 0ll));
        for (int i = 0;  i < sz;  i++) {
            long long ans = 1ll;
            for (int j = i; j < sz; j++) {
                ans = (ans*container[j]) % MOD;
                dp[i][j] = ans;
            }
        }
        vector<int>  result;
        for (auto query : queries) {
            result.push_back(dp[query[0]][query[1]]);
        }
        return result;
    }
};