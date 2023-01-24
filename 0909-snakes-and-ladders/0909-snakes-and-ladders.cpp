class Solution {
public:
    const int INF = 1000000;
    int solve(const vector<int> &path) {
        
        queue<int> q;
        vector<int> cost(path.size(), INF);
        q.push(1);
        cost[1] = 0;
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            
            for (int i = cur + 1; i < path.size() && i <= (cur + 6); i++) {
                int nxt = i;
                if (path[nxt] != -1) nxt = path[nxt];
                if (cost[nxt] > (cost[cur] + 1)) {
                    cost[nxt] = cost[cur] + 1;
                    q.push(nxt);
                }
            }
        }
        return cost[path.size() - 1];
    }
    
    int snakesAndLadders(vector<vector<int>>& board) {
        vector<int> path;
        path.push_back(0);
        int n = board.size();
        bool ck = false;
        for (int i = n - 1; i >= 0; i--) {
            if (!ck) {
                for (int j = 0; j < n; j++) {
                    path.push_back(board[i][j]);
                }
            } else {
                for (int j = n-1; j >= 0; j--) {
                    path.push_back(board[i][j]);
                }
            }
            ck ^= 1;
        }
        int res = solve(path);
        if (res == INF) return -1;
        return res;
    }
};