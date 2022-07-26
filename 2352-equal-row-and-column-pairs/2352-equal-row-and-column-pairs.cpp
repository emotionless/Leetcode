class Solution {
public:
    const int base = 31;
    const int MOD = 1e9 + 7;
    
    int equalPairs(vector<vector<int>>& grid) {
        unordered_map<int, int> hashMap;
        for (auto &v : grid) {
            long long sum = 0;
            for (auto &u : v) {
                sum = ((sum * 10ll) % MOD + u) % MOD;
            }
            hashMap[sum]++;
        }
        int ans = 0;
        int n = grid.size();
        int m = grid[0].size();
        for (int j = 0; j < m; j++) {
            long long sum = 0;
            for (int i = 0; i < n; i++) {
                sum = ((sum * 10) % MOD + grid[i][j]) % MOD;
            }
            ans += hashMap[sum];
        }
        return ans;
    }
};