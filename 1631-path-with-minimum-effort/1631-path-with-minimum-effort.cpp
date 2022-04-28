class Solution {
public:
    int dr[4] = {-1, 0, 1, 0};
    int dc[4] = {0, 1, 0, -1};
    
    struct node {
        int x, y, cost;
        node(int _x, int _y, int _cost) {
            x = _x;
            y = _y;
            cost = _cost;
        }
    };
    
    struct comparator {
        bool operator()(const node &node1, const node &node2) {
            return -node1.cost < -node2.cost;
        }
    };
    
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        priority_queue<node, vector<node>, comparator> pq;
        pq.push(node(0, 0, 0));
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        
        while (!pq.empty()) {
            auto top = pq.top();
            pq.pop();
            int x = top.x;
            int y = top.y;
            if (vis[x][y] == true) {
                continue;
            }
            if (x == (n-1) && y == (m-1)) {
                return top.cost;
            }
            vis[x][y] = true;
            for (int i = 0; i < 4; i++) {
                int adjx = x + dr[i];
                int adjy = y + dc[i];
                if (adjx < 0 || adjx >= n || adjy < 0 || adjy >= m || vis[adjx][adjy] == true) {
                    continue;
                }
                pq.push(node(adjx, adjy, max(top.cost, abs(heights[x][y] - heights[adjx][adjy]))));
            }
        }
        assert(0);
    }
};