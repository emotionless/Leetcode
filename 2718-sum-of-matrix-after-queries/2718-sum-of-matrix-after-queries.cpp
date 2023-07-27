class Solution {
public:
    long long matrixSumQueries(int n, vector<vector<int>>& queries) {
        long long ans = 0ll;
        unordered_set<int> rows, cols;
        for (int i = queries.size() - 1; i >= 0; i--) {
            auto query = queries[i];
            if (query[0] == 0) {
                if (rows.find(query[1]) != rows.end()) continue;
                rows.insert(query[1]);
                ans += query[2] * (n - cols.size());
            } else {
                if (cols.find(query[1]) != cols.end()) continue;
                cols.insert(query[1]);
                ans += query[2] * (n - rows.size());
            }
        }
        return ans;
    }
};