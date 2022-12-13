class Solution {
public:
    
    int dr[4] = {-1, 0, 1, 0};
    int dc[4] = {0, 1, 0, -1};
    
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        priority_queue<pair<int, pair<int, int>>> pq;
        int n = grid.size();
        int m = grid[0].size();
        int k = queries.size();
        pq.push({-grid[0][0], {0, 0}});
        priority_queue<pair<int, int>> data;
        for (int i = 0; i < k; i++) {
            data.push({-queries[i], i});
        }
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        visited[0][0] = true;
        vector<int> ans(k, n*m);
        int cnt = 0;
        while (!pq.empty()) {
            auto top = pq.top();
            pq.pop();
            while (!data.empty()) {
                auto cur = data.top();
                if (-top.first >= (-cur.first)) {
                    ans[cur.second] = cnt;
                    data.pop();
                } else {
                    break;
                }
            }
            cnt++;
            
            for (int i =0; i < 4; i++) {
                int ai = top.second.first + dr[i];
                int aj = top.second.second + dc[i];
                if (ai < 0 || ai >= n || aj < 0 || aj >= m || visited[ai][aj]) continue;
                visited[ai][aj] = true;
                pq.push({-grid[ai][aj], {ai, aj}});
            }
        }
        return ans;
    }
};