class Solution {
public:
    const int INF = 1000000;
    int dr[4] = {-1, 0, 1, 0};
    int dc[4] = {0, 1, 0, -1};
    
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size();
        if (n == 0) return -1;
        int m = grid[0].size();
        if (m == 0) return -1;
        vector<vector<int>> cost(n, vector<int>(m, INF));
        queue<pair<int, int>> q;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    cost[i][j] = 0;
                    q.push(make_pair(i, j));
                }
            }
        }
        int mx = -1;
        while (!q.empty()) {
            auto cur = q.front();
            q.pop();
            int x = cur.first;
            int y = cur.second;
            
            for (int i = 0; i < 4; i++) {
                int adjx = x + dr[i];
                int adjy = y + dc[i];
                if (adjx < 0 || adjx >= n || adjy < 0 || adjy >= m) continue;
                if (cost[adjx][adjy] > (cost[x][y] + 1)) {
                    cost[adjx][adjy] = cost[x][y] + 1;
                    mx = max(mx, cost[adjx][adjy]);
                    q.push(make_pair(adjx, adjy));
                }
            }
        }
        return mx;
    }
};