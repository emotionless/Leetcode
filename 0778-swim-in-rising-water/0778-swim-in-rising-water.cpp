class Solution {
public:
    int dr[4] = {-1,0,  1, 0};
    int dc[4] = {0, 1, 0,  -1};

    struct node {
        int x,  y,  c;
        node(int ax, int ay, int ac) {
            x  = ax;
            y =  ay;
            c  = ac;
        }
        bool operator<(const node &A) const {
            return c > A.c;
        }
    };


    int swimInWater(vector<vector<int>>& grid) {
        const int n = grid.size();
        const  int m =  grid[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        priority_queue<node> pq;
        pq.push(node(0,0,grid[0][0]));
        int mx = 0;
        while (!pq.empty()) {
            node top = pq.top();
            pq.pop();
            int x = top.x;
            int  y = top.y;
            int c  = top.c;
            if (visited[x][y]) continue;
            mx  = max(mx, c);
            if (x == (n-1) && y == (m-1)) return mx;
            visited[x][y] = true;
            for (int i= 0; i < 4;i++) {
                int adjx = x + dr[i];
                int adjy = y + dc[i];
                if (adjx < 0 || adjx >= n || adjy < 0 || adjy >= m) continue;
                if (visited[adjx][adjy]) continue;
                pq.push(node(adjx, adjy, grid[adjx][adjy]));
            }
        }
        return -1;
    }
};