class Solution {
public:
    
    struct comp {
        bool operator()(const vector<int> &A, const vector<int> &B) {
            return A[1] < B[1];
        }
    };
    
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        vector<pair<int, int>> arr;
        for (int i = 0; i < queries.size(); i++) {
            arr.push_back({queries[i], i});
        }
        sort(arr.begin(), arr.end());
        sort(logs.begin(), logs.end(), comp());
        vector<int> ans(queries.size(), 0);
        int i = 0, j = 0;
        int logSz = logs.size();
        int total = 0;
        unordered_map<int, int> counter;
        for (auto &query : arr) {
            int rgt = query.first;
            int lft = rgt - x;
            while (j < logSz && logs[j][1] <= rgt) {
                counter[logs[j][0]]++;
                if (counter[logs[j][0]] == 1) total++;
                j++;
            }
            while (i < logSz && logs[i][1] < lft) {
                counter[logs[i][0]]--;
                if (counter[logs[i][0]] == 0) total--;
                i++;
            }
            ans[query.second] = n - total;
        }
        return ans;
    }
};