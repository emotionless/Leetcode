class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> ret;
        
        for (int i = 0; i <= n - k; i++) {
            vector<int> res;
            for (int j = 0; j <= m - k; j++) {
                map<int, int> counter;
                for (int x = i; x < i + k; x++) {
                    for (int y = j; y < j + k; y++) {
                        counter[grid[x][y]]++;
                    }
                }
                int pre = INT_MIN / 2;
                int ans = INT_MAX;
                for (auto x : counter) {
                    ans = min(ans, x.first - pre);
                    pre = x.first;
                }
                if (counter.size() == 1) ans = 0;
                res.push_back(ans);
            }
            ret.push_back(res);
        }

        return ret;
    }
};