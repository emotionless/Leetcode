class Solution {
public:
    const int INF = 100000000;
    int dr[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
    int dc[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
    
    int shortestPathLength(const vector<vector<int>> &grid) {
        int n = grid.size();
        if (n == 0) return -1;
        int m = grid[0].size();
        if (m == 0) return -1;
        if (grid[0][0] == 1) return -1;
        queue<pair<int, int>> q;
        q.push(make_pair(0, 0));
        vector<vector<int>> cost(n, vector<int>(m, INF));
        cost[0][0] = 1;
        while (!q.empty()) {
            auto cur = q.front();
            q.pop();
            int x = cur.first;
            int y = cur.second;
            if (x == (n - 1) && y == (m - 1)) {
                return cost[x][y];
            }
            for (int i = 0; i < 8; i++) {
                int adjx = x + dr[i];
                int adjy = y + dc[i];
                if (adjx < 0 || adjx >= n || adjy < 0 || adjy >= m || grid[adjx][adjy] == 1) {
                    continue;
                }
                if (cost[adjx][adjy] <= (cost[x][y] + 1)) {
                    continue;
                }
                cost[adjx][adjy] = cost[x][y] + 1;
                q.push(make_pair(adjx, adjy));
            }
        }
        return -1;
    }
    
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        return shortestPathLength(grid);
    }
};