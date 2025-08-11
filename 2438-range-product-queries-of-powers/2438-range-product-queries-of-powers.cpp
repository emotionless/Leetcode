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
        vector<int>  result;
        for (auto query : queries) {
            long long ans = 1ll;
            for (int i = query[0]; i <= query[1]; i++) {
                ans = (ans * container[i]) % MOD;
            }
            result.push_back(ans);
        }
        return result;
    }
};