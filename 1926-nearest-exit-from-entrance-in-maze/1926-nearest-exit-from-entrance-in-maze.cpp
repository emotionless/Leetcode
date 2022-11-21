class Solution {
public:
    
    int dr[4] = {-1, 0, 1, 0};
    int dc[4] = {0, 1, 0, -1};
    
    bool isEdge(vector<int> &cur, int n, int m, vector<vector<char>> &maze) {
        if (cur[0] == 0 || cur[0] == (n-1) || cur[1] == 0 || cur[1] == (m-1)) {
            return maze[cur[0]][cur[1]] == '.';
        }
        return false;
    }
    
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int n = maze.size();
        int m = maze[0].size();
        
        maze[entrance[0]][entrance[1]] = '+';
        queue<vector<int>> q;
        q.push({entrance[0], entrance[1], 0});
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        visited[entrance[0]][entrance[1]] = true;
        
        while (!q.empty()) {
            auto top = q.front();
            q.pop();
            if (isEdge(top, n, m, maze)) return top[2];
            
            for (int i = 0; i < 4; i++) {
                int ax = top[0] + dr[i];
                int ay = top[1] + dc[i];
                if (ax < 0 || ax >= n || ay < 0 || ay >= m || maze[ax][ay] == '+' || visited[ax][ay]) continue;
                visited[ax][ay] = true;
                q.push({ax, ay, 1 + top[2]});
            }
        }
        return -1;
    }
};